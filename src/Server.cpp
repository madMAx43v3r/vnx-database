
#include <vnx/database/Server.h>
#include <vnx/database/Root.hxx>
#include <vnx/database/Table.hxx>

#include <vnx/Request.hxx>
#include <vnx/Generic.hxx>


namespace vnx {
namespace database {

Server::Server(const std::string& _vnx_name)
	:	ServerBase(_vnx_name)
{
}

void Server::init() {
	vnx::open_pipe(vnx_name, this, 1000);
}

void Server::main()
{
	root = vnx::read_from_file<Root>(location + "/index.dat");
	if(root) {
		for(const auto& file_name : root->blocks) {
			try {
				vnx::File file(file_name);
				file.open("rb");
				while(auto value = vnx::read(file.in)) {
					if(auto object = std::dynamic_pointer_cast<Object>(value)) {
						const auto id = (*object)["id"].to<Hash128>();
						if((*object)["__delete"]) {
							index.erase(id);
						} else {
							index[id] = *object;
						}
					} else {
						log(WARN) << "Not an Object: " << value->get_type_name();
					}
				}
			} catch(const std::underflow_error& ex) {
				// nothing
			} catch(const std::exception& ex) {
				log(ERROR) << "Failed to read block '" << file_name << "': " << ex.what();
				if(!ignore_errors) {
					throw;
				}
			}
		}
		log(INFO) << "Loaded " << root->blocks.size() << " blocks, " << index.size() << " objects total.";
		
		for(const auto& table_name : root->tables)
		{
			table_t& table = get_table(table_name);
			table.hash = Hash128(table_name);
			table.file = std::make_shared<vnx::File>(location + "/table_" + table_name + ".dat");
			try {
				table.file->open("rb");
				if(auto value = vnx::read(table.file->in)) {
					if(auto tmp = std::dynamic_pointer_cast<Table>(value)) {
						if(tmp->name == table_name) {
							table.rows.insert(tmp->keys.begin(), tmp->keys.end());
						} else {
							throw std::logic_error("invalid table name: " + tmp->name);
						}
					} else {
						throw std::logic_error("!Table");
					}
				}
			} catch(const std::exception& ex) {
				log(ERROR) << "Failed to read table '" << table_name << "': " << ex.what();
				if(!ignore_errors) {
					throw;
				}
			}
			table.file->close();
			log(INFO) << "Loaded table '" << table_name << "' with " << table.rows.size() << " objects total.";
		}
	} else {
		root = Root::create();
	}
	
	stage_file.open(location + "stage.dat", "ab+");
	stage_file.seek_begin();
	int64_t last_pos = 0;
	try {
		uint64_t seq_num = 1;
		const auto src_mac = Hash64::rand();
		while(auto value = vnx::read(stage_file.in)) {
			auto request = Request::create();
			request->flags = Message::BLOCKING | Message::REPLAY;
			request->src_mac = src_mac;
			request->request_id = seq_num++;
			request->method = value;
			Super::handle(std::const_pointer_cast<const Request>(request));
			last_pos = stage_file.get_input_pos();
		}
	} catch(const std::exception& ex) {
		if(last_pos > 0) {
			log(WARN) << ex.what();
		}
	}
	stage_file.close();
	log(INFO) << "Loaded " << stage.size() << " objects from stage file.";
	
	stage_file.open("rb+");
	stage_file.seek_to(last_pos);
	
	set_timer_millis(1000, std::bind(&Server::maintain, this));
	
	Super::main();
	
	vnx::write(stage_file.out, std::shared_ptr<Value>());
	stage_file.close();
}

std::shared_ptr<const vnx::Return> Server::handle(std::shared_ptr<const vnx::Request> request) {
	if(request->flags & Message::REPLAY) {
		Super::handle(request);
		return nullptr;
	}
	return Super::handle(request);
}

Object aggregate(const query::Select& query, const std::vector<Object>& result) {
	std::map<std::string, std::shared_ptr<query::Aggregate>> funcs;
	for(const auto& entry : query.aggregates) {
		funcs[entry.first] = vnx::clone(entry.second);
	}
	for(const auto& object : result) {
		for(auto& entry : funcs) {
			entry.second->update(object);
		}
	}
	Object row;
	for(auto& entry : funcs) {
		row[entry.first] = entry.second->get_result();
	}
	return row;
}

std::vector<Object> Server::select(const query::Select& query) const {
	const table_t& table = find_table(query.from);
	std::vector<Object> result;
	for(const auto& key : table.rows) {
		Object object;
		if(get_object(key, object)) {
			object["id"] = flip_hash(table, key);
		}
		if(!query.where || query.where->execute(object).to<bool>()) {
			if(query.fields.empty()) {
				result.push_back(std::move(object));
			} else {
				result.emplace_back();
				Object& row = result.back();
				for(const auto& entry : query.fields) {
					if(entry.second) {
						row[entry.first] = entry.second->execute(object);
					}
				}
			}
		}
	}
	if(query.group_by) {
		if(!query.fields.empty()) {
			throw std::logic_error("cannot have fields in group_by mode");
		}
		std::unordered_map<Variant, std::vector<Object>> groups;
		for(auto& object : result) {
			groups[object[query.group_by->field]].push_back(std::move(object));
		}
		result.clear();
		for(const auto& entry : groups) {
			Object object = aggregate(query, entry.second);
			if(!query.having || query.having->execute(object).to<bool>()) {
				object[query.group_by->field] = entry.first;
				result.push_back(std::move(object));
			}
		}
	} else {
		if(!query.aggregates.empty()) {
			if(!query.fields.empty()) {
				throw std::logic_error("cannot have fields in aggregate mode");
			}
			Object object = aggregate(query, result);
			result.clear();
			result.push_back(std::move(object));
		}
	}
	if(query.order_by) {
		std::multimap<Variant, Object> index;
		for(auto& object : result) {
			index.insert(std::make_pair(object[query.order_by->field], std::move(object)));
		}
		result.clear();
		switch(query.order_by->mode) {
			case query::OrderBy::ASC:
				for(auto it = index.begin(); it != index.end(); ++it) {
					result.push_back(std::move(it->second));
				}
				break;
			case query::OrderBy::DESC:
				for(auto it = index.rbegin(); it != index.rend(); ++it) {
					result.push_back(std::move(it->second));
				}
				break;
			default:
				throw std::logic_error("invalid order_by mode");
		}
	}
	if(query.limit) {
		if(query.limit->offset > 0) {
			result.erase(result.begin(), result.begin() + query.limit->offset);
		}
		if(query.limit->num_rows >= 0) {
			if(result.size() > query.limit->num_rows) {
				result.resize(size_t(query.limit->num_rows));
			}
		}
	}
	return result;
}

void Server::update(const query::Update& query) {
	const table_t& table = find_table(query.table);
	for(const auto& key : table.rows) {
		Object object;
		if(get_object(key, object)) {
			object["id"] = flip_hash(table, key);
		}
		if(!query.where || query.where->execute(object).to<bool>()) {
			update_one(key, query.set);
		}
	}
	commit();
}

void Server::delete_from(const query::Delete& query) {
	if(query.where) {
		const table_t& table = find_table(query.from);
		std::vector<Hash128> list;
		for(const auto& key : table.rows) {
			const Hash128 id = flip_hash(table, key);
			Object object;
			if(get_object(key, object)) {
				object["id"] = id;
			}
			if(query.where->execute(object).to<bool>()) {
				list.push_back(id);
			}
		}
		{
			table_t& table = get_table(query.from);
			for(const auto& id : list) {
				delete_one(table, id);
			}
		}
		commit();
	} else {
		truncate(query.from);
	}
}

Object Server::select_one(const std::string& table_name, const Hash128& id) const {
	const table_t& table = find_table(table_name);
	if(const auto* object = get_object(id)) {
		return *object;
	}
	return Object();
}

std::vector<Object> Server::select_many(const std::string& table_name, const std::vector<Hash128>& ids) const {
	std::vector<Object> result;
	for(const auto& id : ids) {
		result.push_back(select_one(table_name, id));
	}
	return result;
}

void Server::insert_one(const vnx::Hash128& id, const vnx::Object& object) {
	auto& staged = stage[id];
	staged = object;
	staged["id"] = id;
}

void Server::insert_one(table_t& table, const vnx::Hash128& id, const vnx::Object& object) {
	insert_row(table, id);
	insert_one(id, object);
}

void Server::insert_one(const std::string& table_name, const Hash128& id, const Object& object) {
	table_t& table = get_table(table_name);
	insert_one(table, id, object);
	commit();
}

void Server::insert_many(const std::string& table_name, const std::map<Hash128, Object>& objects) {
	table_t& table = get_table(table_name);
	for(const auto& entry : objects) {
		insert_one(table, entry.first, entry.second);
	}
	commit();
}

void Server::update_one(const Hash128& id, const Object& object) {
	if(const auto* obj = get_object(id)) {
		Object tmp = *obj;
		for(const auto& field : object.field) {
			if(field.first != "id") {
				tmp[field.first] = field.second;
			}
		}
		stage[id] = tmp;
	}
}

void Server::update_one(table_t& table, const Hash128& id, const Object& object) {
	if(insert_row(table, id)) {
		insert_one(id, object);
	} else {
		update_one(id, object);
	}
}

void Server::update_one(const std::string& table_name, const Hash128& id, const Object& object) {
	table_t& table = get_table(table_name);
	update_one(table, id, object);
	commit();
}

void Server::update_many(const std::string& table_name, const std::map<Hash128, Object>& objects) {
	table_t& table = get_table(table_name);
	for(const auto& entry : objects) {
		update_one(table, entry.first, entry.second);
	}
	commit();
}

void Server::delete_one(const Hash128& id) {
	auto& object = stage[id];
	object.clear();
	object["id"] = id;
	object["__delete"] = true;
}

void Server::delete_one(table_t& table, const Hash128& id) {
	auto iter = table.rows.find(id);
	if(iter != table.rows.end()) {
		table.rows.erase(iter);
		delete_one(id);
	}
}

void Server::delete_one(const std::string& table_name, const Hash128& id) {
	table_t& table = get_table(table_name);
	delete_one(table, id);
	commit();
}

void Server::delete_many(const std::string& table_name, const std::vector<Hash128>& ids) {
	table_t& table = get_table(table_name);
	for(const auto& id : ids) {
		delete_one(table, id);
	}
	commit();
}

void Server::truncate(const std::string& table_name) {
	table_t& table = get_table(table_name);
	for(const auto& id : table.rows) {
		delete_one(id);
	}
	table.rows.clear();
	commit();
}

std::vector<table_info_t> Server::get_table_info() const {
	std::vector<table_info_t> result;
	for(const auto& entry : table_map) {
		table_info_t info;
		info.name = entry.first;
		info.num_rows = entry.second.rows.size();
		result.emplace_back(info);
	}
	return result;
}

Server::table_t& Server::get_table(const std::string& name) {
	table_t& table = table_map[name];
	if(!table.file) {
		table.hash = Hash128(name);
		table.file = std::make_shared<vnx::File>(location + "table_" + name + ".dat");
	}
	return table;
}

const Server::table_t& Server::find_table(const std::string& name) const {
	auto iter = table_map.find(name);
	if(iter == table_map.end()) {
		throw std::logic_error("Table '" + name + "' not found!");
	}
	return iter->second;
}

bool Server::insert_row(table_t& table, const Hash128& key) {
	return table.rows.insert(key).second;
}

const Object* Server::get_object(const Hash128& key) const {
	{
		auto iter = stage.find(key);
		if(iter != stage.end()) {
			return &iter->second;
		}
	}
	auto iter = index.find(key);
	if(iter != index.end()) {
		return &iter->second;
	}
	return nullptr;
}

void Server::commit() {
	if(vnx_request) {
		vnx::write(stage_file.out, vnx_request->method);
		stage_file.flush();
	} else {
		throw std::logic_error("nothing to commit");
	}
}

void Server::maintain() {
	if(stage_file.get_output_pos() >= block_size) {
		write_new_block();
	}
}

void Server::write_new_block()
{
	block_t block;
	block.index = block_table.size();
	block.file = std::make_shared<vnx::File>();
	vnx::File file(location + "block_" + std::to_string(block.index) + ".dat");
	file.open(, "wb");
	file.write_header();
	
	std::map<Hash128, int64_t> header;
	for(const auto& entry : stage) {
		header[entry.first] = -1;
	}
	vnx::write(file.out, uint16_t(CODE_DYNAMIC));
	const auto header_begin_pos = file.get_output_pos();
	vnx::write_dynamic(file.out, header);
	
	for(const auto& entry : stage) {
		if(!entry.second.empty()) {
			header[entry.first] = int64_t(file.get_output_pos());
			vnx::write(file.out, entry.second);
		}
	}
	file.seek_to(header_begin_pos);
	vnx::write_dynamic(file.out, header);
	file.close();
	
	for(auto& entry : table_map) {
		table_t& table = entry.second;
		table.file->open("wb");
		table.file->write_header();
		vnx::write(table.file->out, uint16_t(CODE_DYNAMIC));
		vnx::write_dynamic(table.file->out, table.rows);
		table.file->close();
	}
	
	file.open("rb");
	read_block(block);
	block_table.push_back(block);
	stage.clear();
	
	{
		std::vector<std::string> list;
		for(const auto& block_ : block_table) {
			if(block_.file) {
				list.push_back(block_.file->get_path());
			}
		}
		vnx::write_to_file(location + "index.dat", vnx::Generic::create(Variant(list)));
	}
	{
		std::vector<std::string> list;
		for(const auto& entry : table_map) {
			list.push_back(entry.first);
		}
		vnx::write_to_file(location + "table.dat", vnx::Generic::create(Variant(list)));
	}
	
	stage_file.close();
	stage_file.open(location + "stage.dat", "wb");
	stage_file.write_header();
	stage_file.flush();
}
	
	
} // web
} // vnx
