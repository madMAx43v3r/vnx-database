
#include <vnx/database/Server.h>
#include <vnx/database/Root.hxx>
#include <vnx/database/Table.hxx>
#include <vnx/query/query.h>

#include <vnx/Request.hxx>
#include <vnx/Generic.hxx>

#include <sqltoast/sqltoast.h>


namespace vnx {
namespace database {

static const std::string g_deleted_name = "__deleted";

Server::Server(const std::string& _vnx_name)
	:	ServerBase(_vnx_name)
{
}

void Server::init() {
	vnx::open_pipe(vnx_name, this, 1000);
}

void Server::main()
{
	root = vnx::read_from_file<Root>(location + "index.dat");
	if(root) {
		for(const auto& file_name : root->blocks) {
			try {
				vnx::File file(file_name);
				file.open("rb");
				while(auto value = vnx::read(file.in)) {
					if(auto p_object = std::dynamic_pointer_cast<Object>(value)) {
						const auto id = (*p_object)[id_name].to<Hash128>();
						if(p_object->field.count(g_deleted_name)) {
							index.erase(id);
						} else {
							index[id] = *p_object;
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
			table.file = std::make_shared<vnx::File>(location + "table_" + table_name + ".dat");
			try {
				table.file->open("rb");
				if(auto value = vnx::read(table.file->in)) {
					if(auto tmp = std::dynamic_pointer_cast<Table>(value)) {
						if(tmp->name == table_name) {
							table.keys.insert(tmp->keys.begin(), tmp->keys.end());
						} else {
							throw std::logic_error("invalid table name: " + tmp->name);
						}
					} else {
						throw std::logic_error("invalid table file: " + table.file->get_path());
					}
				}
			} catch(const std::exception& ex) {
				log(ERROR) << "Failed to read table '" << table_name << "': " << ex.what();
				if(!ignore_errors) {
					throw;
				}
			}
			table.file->close();
			log(INFO) << "Loaded table '" << table_name << "' with " << table.keys.size() << " objects.";
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
	if(last_pos > 0) {
		stage_file.seek_to(last_pos);
	} else {
		stage_file.write_header();
		stage_file.flush();
	}
	
	set_timer_millis(1000, std::bind(&Server::maintain, this));
	
	Super::main();
	
	vnx::write(stage_file.out, std::shared_ptr<Value>());	// closing value
	stage_file.close();
}

std::shared_ptr<const vnx::Return> Server::handle(std::shared_ptr<const vnx::Request> request) {
	if(request->flags & Message::REPLAY) {
		Super::handle(request);
		return nullptr;
	}
	return Super::handle(request);
}

std::string to_string(const sqltoast::lexeme_t& word) {
	return std::string(word.start, word.end);
}

std::shared_ptr<const query::Expression> to_expression(const sqltoast::value_expression_primary_t* value);

std::shared_ptr<const query::Expression> to_expression(const sqltoast::numeric_factor_t* factor) {
	if(!factor) {
		throw std::logic_error("!factor");
	}
	std::shared_ptr<const query::Expression> out;
	if(auto primary = factor->primary.get()) {
		switch(primary->type) {
			case sqltoast::NUMERIC_PRIMARY_TYPE_VALUE: {
				auto value = static_cast<const sqltoast::numeric_value_t*>(primary);
				if(auto primary = value->primary.get()) {
					out = to_expression(primary);
				}
				break;
			}
			default:
				throw std::logic_error("unsupported numeric function");
		}
	}
	return out;
}

std::shared_ptr<const query::Expression> to_expression(const sqltoast::numeric_term_t* term) {
	if(!term) {
		throw std::logic_error("!term");
	}
	std::shared_ptr<const query::Expression> out;
	if(term->op == sqltoast::NUMERIC_OP_NONE) {
		out = to_expression(term->left.get());
	} else {
		auto func = query::Function::create();
		switch(term->op) {
			default:
				throw std::logic_error("unsupported numeric function");
		}
		out = func;
	}
	return out;
}

std::shared_ptr<const query::Expression> to_expression(const sqltoast::value_expression_t* value);

std::shared_ptr<const query::Expression> to_expression(const sqltoast::value_expression_primary_t* value) {
	if(!value) {
		throw std::logic_error("!value");
	}
	std::shared_ptr<const query::Expression> out;
	switch(value->vep_type) {
		case sqltoast::VEP_TYPE_COLUMN_REFERENCE: {
			auto field = query::Field::create();
			field->name = to_string(value->lexeme);
			out = field;
			break;
		}
		case sqltoast::VEP_TYPE_UNSIGNED_VALUE_SPECIFICATION: {
			auto spec = static_cast<const sqltoast::unsigned_value_specification_t*>(value);
			switch(spec->uvs_type) {
				case sqltoast::UVS_TYPE_UNSIGNED_NUMERIC:
				case sqltoast::UVS_TYPE_CHARACTER_STRING:
				case sqltoast::UVS_TYPE_NATIONAL_CHARACTER_STRING: {
					auto result = query::Value::create();
					vnx::from_string(to_string(value->lexeme), result->data);
					out = result;
					break;
				}
				default:
					throw std::logic_error("unsupported value type");
			}
			break;
		}
		case sqltoast::VEP_TYPE_SET_FUNCTION_SPECIFICATION: {
			auto function = static_cast<const sqltoast::set_function_t*>(value);
			switch(function->func_type) {
				case sqltoast::SET_FUNCTION_TYPE_COUNT: out = query::Count::create(); break;
				case sqltoast::SET_FUNCTION_TYPE_AVG: {
					auto avg = query::Average::create();
					avg->A = to_expression(function->value.get());
					out = avg;
					break;
				}
				case sqltoast::SET_FUNCTION_TYPE_SUM: {
					auto avg = query::Sum::create();
					avg->A = to_expression(function->value.get());
					out = avg;
					break;
				}
				case sqltoast::SET_FUNCTION_TYPE_MIN: {
					auto avg = query::Min::create();
					avg->A = to_expression(function->value.get());
					out = avg;
					break;
				}
				case sqltoast::SET_FUNCTION_TYPE_MAX: {
					auto avg = query::Max::create();
					avg->A = to_expression(function->value.get());
					out = avg;
					break;
				}
				default:
					throw std::logic_error("unsupported function");
			}
			break;
		}
		default:
			throw std::logic_error("invalid expression primary");
	}
	return out;
}

std::shared_ptr<const query::Expression> to_expression(const sqltoast::value_expression_t* value) {
	if(!value) {
		throw std::logic_error("!value");
	}
	std::shared_ptr<const query::Expression> out;
	switch(value->type) {
		case sqltoast::VALUE_EXPRESSION_TYPE_STRING_EXPRESSION: {
			auto ex = static_cast<const sqltoast::character_value_expression_t*>(value);
			for(const auto& value : ex->values) {
				if(auto primary = value->primary.get()) {
					if(auto value = primary->value.get()) {
						auto next = to_expression(value);
						if(out) {
							throw std::logic_error("string concatenation not supported");
						} else {
							out = next;
						}
					} else if(auto func = primary->string_function.get()) {
						throw std::logic_error("string functions not supported");
					}
				}
			}
			break;
		}
		case sqltoast::VALUE_EXPRESSION_TYPE_NUMERIC_EXPRESSION: {
			auto ex = static_cast<const sqltoast::numeric_expression*>(value);
			if(ex->op == sqltoast::NUMERIC_OP_NONE) {
				out = to_expression(ex->left.get());
			} else {
				auto func = query::Function::create();
				switch(ex->op) {
					default:
						throw std::logic_error("unsupported numeric expression");
				}
				out = func;
			}
		}
		// TODO
	}
	return out;
}

std::shared_ptr<const query::Expression> to_expression(const sqltoast::row_value_constructor_t* value) {
	if(!value) {
		throw std::logic_error("!value");
	}
	std::shared_ptr<const query::Expression> out;
	switch(value->rvc_type) {
		case sqltoast::RVC_TYPE_ELEMENT: {
			auto element = static_cast<const sqltoast::row_value_constructor_element_t*>(value);
			switch(element->rvc_element_type) {
				case sqltoast::RVC_ELEMENT_TYPE_VALUE_EXPRESSION: {
					auto value = static_cast<const sqltoast::row_value_expression_t*>(element);
					out = to_expression(value);
					break;
				}
				default:
					throw std::logic_error("unsupported row-value constructor element");
			}
			break;
		}
		default:
			throw std::logic_error("unsupported row-value constructor");
	}
	return out;
}

std::shared_ptr<const query::Expression> to_expression(const sqltoast::predicate_t* predicate) {
	if(!predicate) {
		throw std::logic_error("!predicate");
	}
	std::shared_ptr<const query::Expression> out;
	switch(predicate->predicate_type) {
		case sqltoast::PREDICATE_TYPE_COMPARISON: {
			auto pred = static_cast<const sqltoast::comp_predicate_t*>(predicate);
			auto comp = query::Comparison::create();
			comp->L = to_expression(pred->left.get());
			comp->R = to_expression(pred->right.get());
			switch(pred->op) {
				case sqltoast::COMP_OP_EQUAL: comp->type = query::op_type_e::EQUAL; break;
				case sqltoast::COMP_OP_NOT_EQUAL: comp->type = query::op_type_e::NOT_EQUAL; break;
				case sqltoast::COMP_OP_GREATER: comp->type = query::op_type_e::GREATER; break;
				case sqltoast::COMP_OP_GREATER_EQUAL: comp->type = query::op_type_e::GREATER_EQUAL; break;
				case sqltoast::COMP_OP_LESS: comp->type = query::op_type_e::LESS; break;
				case sqltoast::COMP_OP_LESS_EQUAL: comp->type = query::op_type_e::LESS_EQUAL; break;
				default:
					throw std::logic_error("invalid comparison operator");
			}
			out = comp;
			break;
		}
	}
	return out;
}

std::shared_ptr<const query::Expression> to_expression(const sqltoast::search_condition_t* condition);

std::shared_ptr<const query::Expression> to_expression(const sqltoast::boolean_term_t* term) {
	if(!term) {
		throw std::logic_error("!term");
	}
	std::shared_ptr<const query::Expression> out;
	if(auto factor = term->factor.get()) {
		if(auto primary = term->factor->primary.get()) {
			if(auto predicate = primary->predicate.get()) {
				out = to_expression(predicate);
			} else if(auto next = primary->search_condition.get()) {
				out = to_expression(next);
			}
		}
		if(factor->reverse_op) {
			auto inv = query::Unary::create();
			inv->X = out;
			inv->type = query::op_type_e::NOT;
			out = inv;
		}
	}
	if(auto next = term->and_operand.get()) {
		auto comp = query::Comparison::create();
		comp->L = out;
		comp->R = to_expression(next);
		comp->type = query::op_type_e::AND;
		out = comp;
	}
	return out;
}

std::shared_ptr<const query::Expression> to_expression(const sqltoast::search_condition_t* condition) {
	if(!condition) {
		throw std::logic_error("!condition");
	}
	std::shared_ptr<const query::Expression> out;
	for(const auto& term : condition->terms) {
		auto next = to_expression(term.get());
		if(out) {
			auto comp = query::Comparison::create();
			comp->L = out;
			comp->R = next;
			comp->type = query::op_type_e::OR;
			out = comp;
		} else {
			out = next;
		}
	}
	return out;
}

std::vector<Object> Server::sql_query(const std::string& query) const {
	sqltoast::parse_input_t subject(query.cbegin(), query.cend());
	const sqltoast::parse_result_t res = sqltoast::parse(subject);
	if(res.code != sqltoast::PARSE_OK) {
		throw std::runtime_error("SQL parse failed: " + res.error);
	}
	std::vector<Object> out;
	for(const auto& statement : res.statements) {
		switch(statement->type) {
			case sqltoast::STATEMENT_TYPE_SELECT: {
				query::Select new_query;
				auto stmt = static_cast<const sqltoast::select_statement_t*>(statement.get());
				if(auto query = stmt->query.get()) {
					int index = 0;
					for(const auto& field : query->selected_columns) {
						if(auto value = field.value.get()) {
							auto ex = to_expression(value);
							std::string alias;
							if(field.has_alias()) {
								alias = to_string(field.alias);
							} else {
								alias = ex->as_string();
							}
							if(auto agg = std::dynamic_pointer_cast<const query::Aggregate>(ex)) {
								new_query.aggregates[alias] = agg;
							} else {
								new_query.fields[alias] = ex;
							}
						}
						index++;
					}
					if(auto from = query->table_expression.get()) {
						for(const auto& ref : from->referenced_tables) {
							switch(ref->type) {
								case sqltoast::TABLE_REFERENCE_TYPE_TABLE: {
									auto table = static_cast<const sqltoast::table_t*>(ref.get());
									new_query.from = to_string(table->table_name);
									break;
								}
							}
						}
						if(auto where = from->where_condition.get()) {
							new_query.where = to_expression(where);
						}
					}
				}
				if(show_queries) {
					log(INFO) << new_query.as_string();
				}
				const auto rows = select(new_query);
				out.insert(out.end(), rows.begin(), rows.end());
				break;
			}
		}
	}
	return out;
}

void Server::sql_update(const std::string& query) {
	//
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
	for(const auto& entry : funcs) {
		row[entry.first] = entry.second->get_result();
	}
	return row;
}

std::vector<Object> Server::select(const query::Select& query) const {
	const table_t& table = find_table(query.from);
	std::vector<Object> result;
	for(const auto& key : table.keys) {
		if(const auto* p_object = get_object(key)) {
			if(!query.where || query.where->execute(*p_object).to<bool>()) {
				if(query.fields.empty()) {
					result.push_back(*p_object);
				} else {
					Object row;
					for(const auto& entry : query.fields) {
						if(const auto& ex = entry.second) {
							row[entry.first] = ex->execute(*p_object);
						}
					}
					result.push_back(std::move(row));
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
	}
	else if(!query.aggregates.empty())
	{
		if(!query.fields.empty()) {
			throw std::logic_error("cannot have fields in aggregate mode");
		}
		Object object = aggregate(query, result);
		result.clear();
		result.push_back(std::move(object));
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
	for(const auto& key : table.keys) {
		if(const auto* p_object = get_object(key)) {
			if(!query.where || query.where->execute(*p_object).to<bool>()) {
				update_one(key, query.set);
			}
		}
	}
	commit();
}

void Server::delete_from(const query::Delete& query) {
	if(query.where) {
		const table_t& table = find_table(query.from);
		std::vector<Hash128> list;
		for(const auto& key : table.keys) {
			if(const auto* p_object = get_object(key)) {
				if(query.where->execute(*p_object).to<bool>()) {
					list.push_back(key);
				}
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
	if(const auto* p_object = get_object(id)) {
		return *p_object;
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
	staged[id_name] = id;
	staged.field.erase(g_deleted_name);
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
	if(const auto* p_object = get_object(id)) {
		Object tmp = *p_object;
		for(const auto& field : object.field) {
			if(field.first != id_name) {
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
	object[id_name] = id;
	object[g_deleted_name] = true;
}

void Server::delete_one(table_t& table, const Hash128& id) {
	auto iter = table.keys.find(id);
	if(iter != table.keys.end()) {
		table.keys.erase(iter);
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
	for(const auto& id : table.keys) {
		delete_one(id);
	}
	table.keys.clear();
	commit();
}

std::vector<table_info_t> Server::get_table_info() const {
	std::vector<table_info_t> result;
	for(const auto& entry : table_map) {
		table_info_t info;
		info.name = entry.first;
		info.num_rows = entry.second.keys.size();
		result.emplace_back(info);
	}
	return result;
}

Server::table_t& Server::get_table(const std::string& name) {
	table_t& table = table_map[name];
	if(!table.file) {
		table.file = std::make_shared<vnx::File>(location + "table_" + name + ".dat");
	}
	return table;
}

const Server::table_t& Server::find_table(const std::string& name) const {
	auto iter = table_map.find(name);
	if(iter == table_map.end()) {
		throw std::logic_error("table '" + name + "' not found");
	}
	return iter->second;
}

bool Server::insert_row(table_t& table, const Hash128& key) {
	return table.keys.insert(key).second;
}

const Object* Server::get_object(const Hash128& key) const {
	{
		auto iter = stage.find(key);
		if(iter != stage.end()) {
			const auto& object = iter->second;
			if(object.field.count(g_deleted_name)) {
				return nullptr;
			}
			return &object;
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
	if(stage_file.get_output_pos() >= max_block_size) {
		write_new_block();
	}
}

void Server::write_new_block()
{
	const auto block_index = root->blocks.size();

	vnx::File file(location + "block_" + std::to_string(block_index) + ".dat");

	auto new_root = vnx::clone(root);
	new_root->tables.clear();
	new_root->blocks.push_back(file.get_path());

	file.open("wb");
	file.write_header();
	
	for(const auto& entry : stage) {
		vnx::write(file.out, entry.second);
	}
	file.close();
	
	for(auto& entry : table_map) {
		table_t& table = entry.second;
		table.file->open("wb");
		table.file->write_header();

		auto value = Table::create();
		value->name = entry.first;
		value->keys.insert(value->keys.end(), table.keys.begin(), table.keys.end());
		vnx::write(table.file->out, value);
		table.file->close();

		new_root->tables.push_back(entry.first);
	}
	{
		const auto dst_path = location + "index.dat";
		const auto tmp_path = dst_path + ".tmp";
		vnx::write_to_file(tmp_path, new_root);

		if(::rename(tmp_path.c_str(), dst_path.c_str())) {
			throw std::runtime_error("rename() failed with: " + std::string(std::strerror(errno)));
		}
	}
	root = new_root;
	stage.clear();

	stage_file.close();
	stage_file.open("wb");
	stage_file.write_header();
	stage_file.flush();
}
	
	
} // web
} // vnx
