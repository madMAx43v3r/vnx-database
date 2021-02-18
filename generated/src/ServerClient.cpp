
// AUTO GENERATED by vnxcppcodegen

#include <vnx/database/package.hxx>
#include <vnx/database/ServerClient.hxx>
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
#include <vnx/query/Delete.hxx>
#include <vnx/query/Select.hxx>
#include <vnx/query/Update.hxx>

#include <vnx/Generic.hxx>
#include <vnx/vnx.h>


namespace vnx {
namespace database {

ServerClient::ServerClient(const std::string& service_name)
	:	Client::Client(vnx::Hash64(service_name))
{
}

ServerClient::ServerClient(vnx::Hash64 service_addr)
	:	Client::Client(service_addr)
{
}

::vnx::Object ServerClient::vnx_get_config_object() {
	auto _method = ::vnx::ModuleInterface_vnx_get_config_object::create();
	auto _return_value = vnx_request(_method, false);
	if(auto _result = std::dynamic_pointer_cast<const ::vnx::ModuleInterface_vnx_get_config_object_return>(_return_value)) {
		return _result->_ret_0;
	} else if(_return_value && !_return_value->is_void()) {
		return _return_value->get_field_by_index(0).to<::vnx::Object>();
	} else {
		throw std::logic_error("ServerClient: invalid return value");
	}
}

::vnx::Variant ServerClient::vnx_get_config(const std::string& name) {
	auto _method = ::vnx::ModuleInterface_vnx_get_config::create();
	_method->name = name;
	auto _return_value = vnx_request(_method, false);
	if(auto _result = std::dynamic_pointer_cast<const ::vnx::ModuleInterface_vnx_get_config_return>(_return_value)) {
		return _result->_ret_0;
	} else if(_return_value && !_return_value->is_void()) {
		return _return_value->get_field_by_index(0).to<::vnx::Variant>();
	} else {
		throw std::logic_error("ServerClient: invalid return value");
	}
}

void ServerClient::vnx_set_config_object(const ::vnx::Object& config) {
	auto _method = ::vnx::ModuleInterface_vnx_set_config_object::create();
	_method->config = config;
	vnx_request(_method, false);
}

void ServerClient::vnx_set_config_object_async(const ::vnx::Object& config) {
	auto _method = ::vnx::ModuleInterface_vnx_set_config_object::create();
	_method->config = config;
	vnx_request(_method, true);
}

void ServerClient::vnx_set_config(const std::string& name, const ::vnx::Variant& value) {
	auto _method = ::vnx::ModuleInterface_vnx_set_config::create();
	_method->name = name;
	_method->value = value;
	vnx_request(_method, false);
}

void ServerClient::vnx_set_config_async(const std::string& name, const ::vnx::Variant& value) {
	auto _method = ::vnx::ModuleInterface_vnx_set_config::create();
	_method->name = name;
	_method->value = value;
	vnx_request(_method, true);
}

::vnx::TypeCode ServerClient::vnx_get_type_code() {
	auto _method = ::vnx::ModuleInterface_vnx_get_type_code::create();
	auto _return_value = vnx_request(_method, false);
	if(auto _result = std::dynamic_pointer_cast<const ::vnx::ModuleInterface_vnx_get_type_code_return>(_return_value)) {
		return _result->_ret_0;
	} else if(_return_value && !_return_value->is_void()) {
		return _return_value->get_field_by_index(0).to<::vnx::TypeCode>();
	} else {
		throw std::logic_error("ServerClient: invalid return value");
	}
}

std::shared_ptr<const ::vnx::ModuleInfo> ServerClient::vnx_get_module_info() {
	auto _method = ::vnx::ModuleInterface_vnx_get_module_info::create();
	auto _return_value = vnx_request(_method, false);
	if(auto _result = std::dynamic_pointer_cast<const ::vnx::ModuleInterface_vnx_get_module_info_return>(_return_value)) {
		return _result->_ret_0;
	} else if(_return_value && !_return_value->is_void()) {
		return _return_value->get_field_by_index(0).to<std::shared_ptr<const ::vnx::ModuleInfo>>();
	} else {
		throw std::logic_error("ServerClient: invalid return value");
	}
}

void ServerClient::vnx_restart() {
	auto _method = ::vnx::ModuleInterface_vnx_restart::create();
	vnx_request(_method, false);
}

void ServerClient::vnx_restart_async() {
	auto _method = ::vnx::ModuleInterface_vnx_restart::create();
	vnx_request(_method, true);
}

void ServerClient::vnx_stop() {
	auto _method = ::vnx::ModuleInterface_vnx_stop::create();
	vnx_request(_method, false);
}

void ServerClient::vnx_stop_async() {
	auto _method = ::vnx::ModuleInterface_vnx_stop::create();
	vnx_request(_method, true);
}

vnx::bool_t ServerClient::vnx_self_test() {
	auto _method = ::vnx::ModuleInterface_vnx_self_test::create();
	auto _return_value = vnx_request(_method, false);
	if(auto _result = std::dynamic_pointer_cast<const ::vnx::ModuleInterface_vnx_self_test_return>(_return_value)) {
		return _result->_ret_0;
	} else if(_return_value && !_return_value->is_void()) {
		return _return_value->get_field_by_index(0).to<vnx::bool_t>();
	} else {
		throw std::logic_error("ServerClient: invalid return value");
	}
}

std::vector<::vnx::Object> ServerClient::select(const ::vnx::query::Select& query) {
	auto _method = ::vnx::database::Server_select::create();
	_method->query = query;
	auto _return_value = vnx_request(_method, false);
	if(auto _result = std::dynamic_pointer_cast<const ::vnx::database::Server_select_return>(_return_value)) {
		return _result->_ret_0;
	} else if(_return_value && !_return_value->is_void()) {
		return _return_value->get_field_by_index(0).to<std::vector<::vnx::Object>>();
	} else {
		throw std::logic_error("ServerClient: invalid return value");
	}
}

void ServerClient::update(const ::vnx::query::Update& query) {
	auto _method = ::vnx::database::Server_update::create();
	_method->query = query;
	vnx_request(_method, false);
}

void ServerClient::update_async(const ::vnx::query::Update& query) {
	auto _method = ::vnx::database::Server_update::create();
	_method->query = query;
	vnx_request(_method, true);
}

void ServerClient::delete_from(const ::vnx::query::Delete& query) {
	auto _method = ::vnx::database::Server_delete_from::create();
	_method->query = query;
	vnx_request(_method, false);
}

void ServerClient::delete_from_async(const ::vnx::query::Delete& query) {
	auto _method = ::vnx::database::Server_delete_from::create();
	_method->query = query;
	vnx_request(_method, true);
}

::vnx::Object ServerClient::select_one(const std::string& table, const ::vnx::Hash128& id) {
	auto _method = ::vnx::database::Server_select_one::create();
	_method->table = table;
	_method->id = id;
	auto _return_value = vnx_request(_method, false);
	if(auto _result = std::dynamic_pointer_cast<const ::vnx::database::Server_select_one_return>(_return_value)) {
		return _result->_ret_0;
	} else if(_return_value && !_return_value->is_void()) {
		return _return_value->get_field_by_index(0).to<::vnx::Object>();
	} else {
		throw std::logic_error("ServerClient: invalid return value");
	}
}

std::vector<::vnx::Object> ServerClient::select_many(const std::string& table, const std::vector<::vnx::Hash128>& ids) {
	auto _method = ::vnx::database::Server_select_many::create();
	_method->table = table;
	_method->ids = ids;
	auto _return_value = vnx_request(_method, false);
	if(auto _result = std::dynamic_pointer_cast<const ::vnx::database::Server_select_many_return>(_return_value)) {
		return _result->_ret_0;
	} else if(_return_value && !_return_value->is_void()) {
		return _return_value->get_field_by_index(0).to<std::vector<::vnx::Object>>();
	} else {
		throw std::logic_error("ServerClient: invalid return value");
	}
}

void ServerClient::insert_one(const std::string& table, const ::vnx::Hash128& id, const ::vnx::Object& object) {
	auto _method = ::vnx::database::Server_insert_one::create();
	_method->table = table;
	_method->id = id;
	_method->object = object;
	vnx_request(_method, false);
}

void ServerClient::insert_one_async(const std::string& table, const ::vnx::Hash128& id, const ::vnx::Object& object) {
	auto _method = ::vnx::database::Server_insert_one::create();
	_method->table = table;
	_method->id = id;
	_method->object = object;
	vnx_request(_method, true);
}

void ServerClient::insert_many(const std::string& table, const std::map<::vnx::Hash128, ::vnx::Object>& objects) {
	auto _method = ::vnx::database::Server_insert_many::create();
	_method->table = table;
	_method->objects = objects;
	vnx_request(_method, false);
}

void ServerClient::insert_many_async(const std::string& table, const std::map<::vnx::Hash128, ::vnx::Object>& objects) {
	auto _method = ::vnx::database::Server_insert_many::create();
	_method->table = table;
	_method->objects = objects;
	vnx_request(_method, true);
}

void ServerClient::update_one(const std::string& table, const ::vnx::Hash128& id, const ::vnx::Object& object) {
	auto _method = ::vnx::database::Server_update_one::create();
	_method->table = table;
	_method->id = id;
	_method->object = object;
	vnx_request(_method, false);
}

void ServerClient::update_one_async(const std::string& table, const ::vnx::Hash128& id, const ::vnx::Object& object) {
	auto _method = ::vnx::database::Server_update_one::create();
	_method->table = table;
	_method->id = id;
	_method->object = object;
	vnx_request(_method, true);
}

void ServerClient::update_many(const std::string& table, const std::map<::vnx::Hash128, ::vnx::Object>& objects) {
	auto _method = ::vnx::database::Server_update_many::create();
	_method->table = table;
	_method->objects = objects;
	vnx_request(_method, false);
}

void ServerClient::update_many_async(const std::string& table, const std::map<::vnx::Hash128, ::vnx::Object>& objects) {
	auto _method = ::vnx::database::Server_update_many::create();
	_method->table = table;
	_method->objects = objects;
	vnx_request(_method, true);
}

void ServerClient::delete_one(const std::string& table, const ::vnx::Hash128& id) {
	auto _method = ::vnx::database::Server_delete_one::create();
	_method->table = table;
	_method->id = id;
	vnx_request(_method, false);
}

void ServerClient::delete_one_async(const std::string& table, const ::vnx::Hash128& id) {
	auto _method = ::vnx::database::Server_delete_one::create();
	_method->table = table;
	_method->id = id;
	vnx_request(_method, true);
}

void ServerClient::delete_many(const std::string& table, const std::vector<::vnx::Hash128>& ids) {
	auto _method = ::vnx::database::Server_delete_many::create();
	_method->table = table;
	_method->ids = ids;
	vnx_request(_method, false);
}

void ServerClient::delete_many_async(const std::string& table, const std::vector<::vnx::Hash128>& ids) {
	auto _method = ::vnx::database::Server_delete_many::create();
	_method->table = table;
	_method->ids = ids;
	vnx_request(_method, true);
}

void ServerClient::truncate(const std::string& table) {
	auto _method = ::vnx::database::Server_truncate::create();
	_method->table = table;
	vnx_request(_method, false);
}

void ServerClient::truncate_async(const std::string& table) {
	auto _method = ::vnx::database::Server_truncate::create();
	_method->table = table;
	vnx_request(_method, true);
}

std::map<std::string, ::vnx::Object> ServerClient::get_table_info() {
	auto _method = ::vnx::database::Server_get_table_info::create();
	auto _return_value = vnx_request(_method, false);
	if(auto _result = std::dynamic_pointer_cast<const ::vnx::database::Server_get_table_info_return>(_return_value)) {
		return _result->_ret_0;
	} else if(_return_value && !_return_value->is_void()) {
		return _return_value->get_field_by_index(0).to<std::map<std::string, ::vnx::Object>>();
	} else {
		throw std::logic_error("ServerClient: invalid return value");
	}
}

void ServerClient::write_new_block() {
	auto _method = ::vnx::database::Server_write_new_block::create();
	vnx_request(_method, false);
}

void ServerClient::write_new_block_async() {
	auto _method = ::vnx::database::Server_write_new_block::create();
	vnx_request(_method, true);
}


} // namespace vnx
} // namespace database
