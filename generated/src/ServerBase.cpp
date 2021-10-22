
// AUTO GENERATED by vnxcppcodegen

#include <vnx/database/package.hxx>
#include <vnx/database/ServerBase.hxx>
#include <vnx/NoSuchMethod.hxx>
#include <vnx/Hash128.hpp>
#include <vnx/Module.h>
#include <vnx/ModuleInterface_vnx_get_config.hxx>
#include <vnx/ModuleInterface_vnx_get_config_return.hxx>
#include <vnx/ModuleInterface_vnx_get_config_object.hxx>
#include <vnx/ModuleInterface_vnx_get_config_object_return.hxx>
#include <vnx/ModuleInterface_vnx_get_module_info.hxx>
#include <vnx/ModuleInterface_vnx_get_module_info_return.hxx>
#include <vnx/ModuleInterface_vnx_get_type_code.hxx>
#include <vnx/ModuleInterface_vnx_get_type_code_return.hxx>
#include <vnx/ModuleInterface_vnx_restart.hxx>
#include <vnx/ModuleInterface_vnx_restart_return.hxx>
#include <vnx/ModuleInterface_vnx_self_test.hxx>
#include <vnx/ModuleInterface_vnx_self_test_return.hxx>
#include <vnx/ModuleInterface_vnx_set_config.hxx>
#include <vnx/ModuleInterface_vnx_set_config_return.hxx>
#include <vnx/ModuleInterface_vnx_set_config_object.hxx>
#include <vnx/ModuleInterface_vnx_set_config_object_return.hxx>
#include <vnx/ModuleInterface_vnx_stop.hxx>
#include <vnx/ModuleInterface_vnx_stop_return.hxx>
#include <vnx/Object.hpp>
#include <vnx/database/Server_delete_from.hxx>
#include <vnx/database/Server_delete_from_return.hxx>
#include <vnx/database/Server_delete_many.hxx>
#include <vnx/database/Server_delete_many_return.hxx>
#include <vnx/database/Server_delete_one.hxx>
#include <vnx/database/Server_delete_one_return.hxx>
#include <vnx/database/Server_get_table_info.hxx>
#include <vnx/database/Server_get_table_info_return.hxx>
#include <vnx/database/Server_insert_many.hxx>
#include <vnx/database/Server_insert_many_return.hxx>
#include <vnx/database/Server_insert_one.hxx>
#include <vnx/database/Server_insert_one_return.hxx>
#include <vnx/database/Server_select.hxx>
#include <vnx/database/Server_select_return.hxx>
#include <vnx/database/Server_select_many.hxx>
#include <vnx/database/Server_select_many_return.hxx>
#include <vnx/database/Server_select_one.hxx>
#include <vnx/database/Server_select_one_return.hxx>
#include <vnx/database/Server_sql_query.hxx>
#include <vnx/database/Server_sql_query_return.hxx>
#include <vnx/database/Server_sql_update.hxx>
#include <vnx/database/Server_sql_update_return.hxx>
#include <vnx/database/Server_truncate.hxx>
#include <vnx/database/Server_truncate_return.hxx>
#include <vnx/database/Server_update.hxx>
#include <vnx/database/Server_update_return.hxx>
#include <vnx/database/Server_update_many.hxx>
#include <vnx/database/Server_update_many_return.hxx>
#include <vnx/database/Server_update_one.hxx>
#include <vnx/database/Server_update_one_return.hxx>
#include <vnx/database/Server_write_new_block.hxx>
#include <vnx/database/Server_write_new_block_return.hxx>
#include <vnx/database/table_info_t.hxx>
#include <vnx/query/Delete.hxx>
#include <vnx/query/Select.hxx>
#include <vnx/query/Update.hxx>

#include <vnx/vnx.h>


namespace vnx {
namespace database {


const vnx::Hash64 ServerBase::VNX_TYPE_HASH(0x3e27b2d3ee41ac7full);
const vnx::Hash64 ServerBase::VNX_CODE_HASH(0xd892ef8e2c8cd668ull);

ServerBase::ServerBase(const std::string& _vnx_name)
	:	Module::Module(_vnx_name)
{
	vnx::read_config(vnx_name + ".location", location);
	vnx::read_config(vnx_name + ".id_name", id_name);
	vnx::read_config(vnx_name + ".max_block_size", max_block_size);
	vnx::read_config(vnx_name + ".show_queries", show_queries);
	vnx::read_config(vnx_name + ".ignore_errors", ignore_errors);
}

vnx::Hash64 ServerBase::get_type_hash() const {
	return VNX_TYPE_HASH;
}

std::string ServerBase::get_type_name() const {
	return "vnx.database.Server";
}

const vnx::TypeCode* ServerBase::get_type_code() const {
	return vnx::database::vnx_native_type_code_ServerBase;
}

void ServerBase::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = vnx::database::vnx_native_type_code_ServerBase;
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, location);
	_visitor.type_field(_type_code->fields[1], 1); vnx::accept(_visitor, id_name);
	_visitor.type_field(_type_code->fields[2], 2); vnx::accept(_visitor, max_block_size);
	_visitor.type_field(_type_code->fields[3], 3); vnx::accept(_visitor, show_queries);
	_visitor.type_field(_type_code->fields[4], 4); vnx::accept(_visitor, ignore_errors);
	_visitor.type_end(*_type_code);
}

void ServerBase::write(std::ostream& _out) const {
	_out << "{";
	_out << "\"location\": "; vnx::write(_out, location);
	_out << ", \"id_name\": "; vnx::write(_out, id_name);
	_out << ", \"max_block_size\": "; vnx::write(_out, max_block_size);
	_out << ", \"show_queries\": "; vnx::write(_out, show_queries);
	_out << ", \"ignore_errors\": "; vnx::write(_out, ignore_errors);
	_out << "}";
}

void ServerBase::read(std::istream& _in) {
	if(auto _json = vnx::read_json(_in)) {
		from_object(_json->to_object());
	}
}

vnx::Object ServerBase::to_object() const {
	vnx::Object _object;
	_object["__type"] = "vnx.database.Server";
	_object["location"] = location;
	_object["id_name"] = id_name;
	_object["max_block_size"] = max_block_size;
	_object["show_queries"] = show_queries;
	_object["ignore_errors"] = ignore_errors;
	return _object;
}

void ServerBase::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "id_name") {
			_entry.second.to(id_name);
		} else if(_entry.first == "ignore_errors") {
			_entry.second.to(ignore_errors);
		} else if(_entry.first == "location") {
			_entry.second.to(location);
		} else if(_entry.first == "max_block_size") {
			_entry.second.to(max_block_size);
		} else if(_entry.first == "show_queries") {
			_entry.second.to(show_queries);
		}
	}
}

vnx::Variant ServerBase::get_field(const std::string& _name) const {
	if(_name == "location") {
		return vnx::Variant(location);
	}
	if(_name == "id_name") {
		return vnx::Variant(id_name);
	}
	if(_name == "max_block_size") {
		return vnx::Variant(max_block_size);
	}
	if(_name == "show_queries") {
		return vnx::Variant(show_queries);
	}
	if(_name == "ignore_errors") {
		return vnx::Variant(ignore_errors);
	}
	return vnx::Variant();
}

void ServerBase::set_field(const std::string& _name, const vnx::Variant& _value) {
	if(_name == "location") {
		_value.to(location);
	} else if(_name == "id_name") {
		_value.to(id_name);
	} else if(_name == "max_block_size") {
		_value.to(max_block_size);
	} else if(_name == "show_queries") {
		_value.to(show_queries);
	} else if(_name == "ignore_errors") {
		_value.to(ignore_errors);
	} else {
		throw std::logic_error("no such field: '" + _name + "'");
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const ServerBase& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, ServerBase& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* ServerBase::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(VNX_TYPE_HASH);
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> ServerBase::static_create_type_code() {
	auto type_code = std::make_shared<vnx::TypeCode>();
	type_code->name = "vnx.database.Server";
	type_code->type_hash = vnx::Hash64(0x3e27b2d3ee41ac7full);
	type_code->code_hash = vnx::Hash64(0xd892ef8e2c8cd668ull);
	type_code->is_native = true;
	type_code->native_size = sizeof(::vnx::database::ServerBase);
	type_code->methods.resize(25);
	type_code->methods[0] = ::vnx::ModuleInterface_vnx_get_config_object::static_get_type_code();
	type_code->methods[1] = ::vnx::ModuleInterface_vnx_get_config::static_get_type_code();
	type_code->methods[2] = ::vnx::ModuleInterface_vnx_set_config_object::static_get_type_code();
	type_code->methods[3] = ::vnx::ModuleInterface_vnx_set_config::static_get_type_code();
	type_code->methods[4] = ::vnx::ModuleInterface_vnx_get_type_code::static_get_type_code();
	type_code->methods[5] = ::vnx::ModuleInterface_vnx_get_module_info::static_get_type_code();
	type_code->methods[6] = ::vnx::ModuleInterface_vnx_restart::static_get_type_code();
	type_code->methods[7] = ::vnx::ModuleInterface_vnx_stop::static_get_type_code();
	type_code->methods[8] = ::vnx::ModuleInterface_vnx_self_test::static_get_type_code();
	type_code->methods[9] = ::vnx::database::Server_sql_query::static_get_type_code();
	type_code->methods[10] = ::vnx::database::Server_sql_update::static_get_type_code();
	type_code->methods[11] = ::vnx::database::Server_select::static_get_type_code();
	type_code->methods[12] = ::vnx::database::Server_update::static_get_type_code();
	type_code->methods[13] = ::vnx::database::Server_delete_from::static_get_type_code();
	type_code->methods[14] = ::vnx::database::Server_select_one::static_get_type_code();
	type_code->methods[15] = ::vnx::database::Server_select_many::static_get_type_code();
	type_code->methods[16] = ::vnx::database::Server_insert_one::static_get_type_code();
	type_code->methods[17] = ::vnx::database::Server_insert_many::static_get_type_code();
	type_code->methods[18] = ::vnx::database::Server_update_one::static_get_type_code();
	type_code->methods[19] = ::vnx::database::Server_update_many::static_get_type_code();
	type_code->methods[20] = ::vnx::database::Server_delete_one::static_get_type_code();
	type_code->methods[21] = ::vnx::database::Server_delete_many::static_get_type_code();
	type_code->methods[22] = ::vnx::database::Server_truncate::static_get_type_code();
	type_code->methods[23] = ::vnx::database::Server_get_table_info::static_get_type_code();
	type_code->methods[24] = ::vnx::database::Server_write_new_block::static_get_type_code();
	type_code->fields.resize(5);
	{
		auto& field = type_code->fields[0];
		field.is_extended = true;
		field.name = "location";
		field.value = vnx::to_string("data/");
		field.code = {32};
	}
	{
		auto& field = type_code->fields[1];
		field.is_extended = true;
		field.name = "id_name";
		field.value = vnx::to_string("id");
		field.code = {32};
	}
	{
		auto& field = type_code->fields[2];
		field.data_size = 8;
		field.name = "max_block_size";
		field.value = vnx::to_string(67108864);
		field.code = {8};
	}
	{
		auto& field = type_code->fields[3];
		field.data_size = 1;
		field.name = "show_queries";
		field.value = vnx::to_string(false);
		field.code = {31};
	}
	{
		auto& field = type_code->fields[4];
		field.data_size = 1;
		field.name = "ignore_errors";
		field.value = vnx::to_string(false);
		field.code = {31};
	}
	type_code->build();
	return type_code;
}

void ServerBase::vnx_handle_switch(std::shared_ptr<const vnx::Value> _value) {
	const auto* _type_code = _value->get_type_code();
	while(_type_code) {
		switch(_type_code->type_hash) {
			default:
				_type_code = _type_code->super;
		}
	}
	handle(std::static_pointer_cast<const vnx::Value>(_value));
}

std::shared_ptr<vnx::Value> ServerBase::vnx_call_switch(std::shared_ptr<const vnx::Value> _method, const vnx::request_id_t& _request_id) {
	switch(_method->get_type_hash()) {
		case 0x17f58f68bf83abc0ull: {
			auto _args = std::static_pointer_cast<const ::vnx::ModuleInterface_vnx_get_config_object>(_method);
			auto _return_value = ::vnx::ModuleInterface_vnx_get_config_object_return::create();
			_return_value->_ret_0 = vnx_get_config_object();
			return _return_value;
		}
		case 0xbbc7f1a01044d294ull: {
			auto _args = std::static_pointer_cast<const ::vnx::ModuleInterface_vnx_get_config>(_method);
			auto _return_value = ::vnx::ModuleInterface_vnx_get_config_return::create();
			_return_value->_ret_0 = vnx_get_config(_args->name);
			return _return_value;
		}
		case 0xca30f814f17f322full: {
			auto _args = std::static_pointer_cast<const ::vnx::ModuleInterface_vnx_set_config_object>(_method);
			auto _return_value = ::vnx::ModuleInterface_vnx_set_config_object_return::create();
			vnx_set_config_object(_args->config);
			return _return_value;
		}
		case 0x362aac91373958b7ull: {
			auto _args = std::static_pointer_cast<const ::vnx::ModuleInterface_vnx_set_config>(_method);
			auto _return_value = ::vnx::ModuleInterface_vnx_set_config_return::create();
			vnx_set_config(_args->name, _args->value);
			return _return_value;
		}
		case 0x305ec4d628960e5dull: {
			auto _args = std::static_pointer_cast<const ::vnx::ModuleInterface_vnx_get_type_code>(_method);
			auto _return_value = ::vnx::ModuleInterface_vnx_get_type_code_return::create();
			_return_value->_ret_0 = vnx_get_type_code();
			return _return_value;
		}
		case 0xf6d82bdf66d034a1ull: {
			auto _args = std::static_pointer_cast<const ::vnx::ModuleInterface_vnx_get_module_info>(_method);
			auto _return_value = ::vnx::ModuleInterface_vnx_get_module_info_return::create();
			_return_value->_ret_0 = vnx_get_module_info();
			return _return_value;
		}
		case 0x9e95dc280cecca1bull: {
			auto _args = std::static_pointer_cast<const ::vnx::ModuleInterface_vnx_restart>(_method);
			auto _return_value = ::vnx::ModuleInterface_vnx_restart_return::create();
			vnx_restart();
			return _return_value;
		}
		case 0x7ab49ce3d1bfc0d2ull: {
			auto _args = std::static_pointer_cast<const ::vnx::ModuleInterface_vnx_stop>(_method);
			auto _return_value = ::vnx::ModuleInterface_vnx_stop_return::create();
			vnx_stop();
			return _return_value;
		}
		case 0x6ce3775b41a42697ull: {
			auto _args = std::static_pointer_cast<const ::vnx::ModuleInterface_vnx_self_test>(_method);
			auto _return_value = ::vnx::ModuleInterface_vnx_self_test_return::create();
			_return_value->_ret_0 = vnx_self_test();
			return _return_value;
		}
		case 0x8c702a2c05b83e2full: {
			auto _args = std::static_pointer_cast<const ::vnx::database::Server_sql_query>(_method);
			auto _return_value = ::vnx::database::Server_sql_query_return::create();
			_return_value->_ret_0 = sql_query(_args->query);
			return _return_value;
		}
		case 0xde725a318e4254a5ull: {
			auto _args = std::static_pointer_cast<const ::vnx::database::Server_sql_update>(_method);
			auto _return_value = ::vnx::database::Server_sql_update_return::create();
			sql_update(_args->query);
			return _return_value;
		}
		case 0xc5f091df45ac99eaull: {
			auto _args = std::static_pointer_cast<const ::vnx::database::Server_select>(_method);
			auto _return_value = ::vnx::database::Server_select_return::create();
			_return_value->_ret_0 = select(_args->query);
			return _return_value;
		}
		case 0xc19ad2535b3c3424ull: {
			auto _args = std::static_pointer_cast<const ::vnx::database::Server_update>(_method);
			auto _return_value = ::vnx::database::Server_update_return::create();
			update(_args->query);
			return _return_value;
		}
		case 0xf9128aa1f79bd17ull: {
			auto _args = std::static_pointer_cast<const ::vnx::database::Server_delete_from>(_method);
			auto _return_value = ::vnx::database::Server_delete_from_return::create();
			delete_from(_args->query);
			return _return_value;
		}
		case 0x22221bf39d9159c2ull: {
			auto _args = std::static_pointer_cast<const ::vnx::database::Server_select_one>(_method);
			auto _return_value = ::vnx::database::Server_select_one_return::create();
			_return_value->_ret_0 = select_one(_args->table, _args->id);
			return _return_value;
		}
		case 0xe1346a3b8326c22full: {
			auto _args = std::static_pointer_cast<const ::vnx::database::Server_select_many>(_method);
			auto _return_value = ::vnx::database::Server_select_many_return::create();
			_return_value->_ret_0 = select_many(_args->table, _args->ids);
			return _return_value;
		}
		case 0xe6eae6a76679ec53ull: {
			auto _args = std::static_pointer_cast<const ::vnx::database::Server_insert_one>(_method);
			auto _return_value = ::vnx::database::Server_insert_one_return::create();
			insert_one(_args->table, _args->id, _args->object);
			return _return_value;
		}
		case 0xe62918d552ce1cfeull: {
			auto _args = std::static_pointer_cast<const ::vnx::database::Server_insert_many>(_method);
			auto _return_value = ::vnx::database::Server_insert_many_return::create();
			insert_many(_args->table, _args->objects);
			return _return_value;
		}
		case 0x326c9e9b74ce2923ull: {
			auto _args = std::static_pointer_cast<const ::vnx::database::Server_update_one>(_method);
			auto _return_value = ::vnx::database::Server_update_one_return::create();
			update_one(_args->table, _args->id, _args->object);
			return _return_value;
		}
		case 0x4e7562f764a8641ull: {
			auto _args = std::static_pointer_cast<const ::vnx::database::Server_update_many>(_method);
			auto _return_value = ::vnx::database::Server_update_many_return::create();
			update_many(_args->table, _args->objects);
			return _return_value;
		}
		case 0x4ea74a5e72ad32b8ull: {
			auto _args = std::static_pointer_cast<const ::vnx::database::Server_delete_one>(_method);
			auto _return_value = ::vnx::database::Server_delete_one_return::create();
			delete_one(_args->table, _args->id);
			return _return_value;
		}
		case 0x6796b66101cf03ull: {
			auto _args = std::static_pointer_cast<const ::vnx::database::Server_delete_many>(_method);
			auto _return_value = ::vnx::database::Server_delete_many_return::create();
			delete_many(_args->table, _args->ids);
			return _return_value;
		}
		case 0x5503f4f9957a4ffdull: {
			auto _args = std::static_pointer_cast<const ::vnx::database::Server_truncate>(_method);
			auto _return_value = ::vnx::database::Server_truncate_return::create();
			truncate(_args->table);
			return _return_value;
		}
		case 0x7c2beca30ffa7aaaull: {
			auto _args = std::static_pointer_cast<const ::vnx::database::Server_get_table_info>(_method);
			auto _return_value = ::vnx::database::Server_get_table_info_return::create();
			_return_value->_ret_0 = get_table_info();
			return _return_value;
		}
		case 0x566c1834091e052aull: {
			auto _args = std::static_pointer_cast<const ::vnx::database::Server_write_new_block>(_method);
			auto _return_value = ::vnx::database::Server_write_new_block_return::create();
			write_new_block();
			return _return_value;
		}
	}
	auto _ex = vnx::NoSuchMethod::create();
	_ex->dst_mac = vnx_request ? vnx_request->dst_mac : vnx::Hash64();
	_ex->method = _method->get_type_name();
	return _ex;
}


} // namespace vnx
} // namespace database


namespace vnx {

void read(TypeInput& in, ::vnx::database::ServerBase& value, const TypeCode* type_code, const uint16_t* code) {
	if(code) {
		switch(code[0]) {
			case CODE_OBJECT:
			case CODE_ALT_OBJECT: {
				Object tmp;
				vnx::read(in, tmp, type_code, code);
				value.from_object(tmp);
				return;
			}
			case CODE_DYNAMIC:
			case CODE_ALT_DYNAMIC:
				vnx::read_dynamic(in, value);
				return;
		}
	}
	if(!type_code) {
		vnx::skip(in, type_code, code);
		return;
	}
	if(code) {
		switch(code[0]) {
			case CODE_STRUCT: type_code = type_code->depends[code[1]]; break;
			case CODE_ALT_STRUCT: type_code = type_code->depends[vnx::flip_bytes(code[1])]; break;
			default: {
				vnx::skip(in, type_code, code);
				return;
			}
		}
	}
	const char* const _buf = in.read(type_code->total_field_size);
	if(type_code->is_matched) {
		if(const auto* const _field = type_code->field_map[2]) {
			vnx::read_value(_buf + _field->offset, value.max_block_size, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[3]) {
			vnx::read_value(_buf + _field->offset, value.show_queries, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[4]) {
			vnx::read_value(_buf + _field->offset, value.ignore_errors, _field->code.data());
		}
	}
	for(const auto* _field : type_code->ext_fields) {
		switch(_field->native_index) {
			case 0: vnx::read(in, value.location, type_code, _field->code.data()); break;
			case 1: vnx::read(in, value.id_name, type_code, _field->code.data()); break;
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::vnx::database::ServerBase& value, const TypeCode* type_code, const uint16_t* code) {
	if(code && code[0] == CODE_OBJECT) {
		vnx::write(out, value.to_object(), nullptr, code);
		return;
	}
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = vnx::database::vnx_native_type_code_ServerBase;
		out.write_type_code(type_code);
		vnx::write_class_header<::vnx::database::ServerBase>(out);
	}
	else if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	char* const _buf = out.write(10);
	vnx::write_value(_buf + 0, value.max_block_size);
	vnx::write_value(_buf + 8, value.show_queries);
	vnx::write_value(_buf + 9, value.ignore_errors);
	vnx::write(out, value.location, type_code, type_code->fields[0].code.data());
	vnx::write(out, value.id_name, type_code, type_code->fields[1].code.data());
}

void read(std::istream& in, ::vnx::database::ServerBase& value) {
	value.read(in);
}

void write(std::ostream& out, const ::vnx::database::ServerBase& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::vnx::database::ServerBase& value) {
	value.accept(visitor);
}

} // vnx
