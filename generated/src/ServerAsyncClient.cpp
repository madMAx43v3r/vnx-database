
// AUTO GENERATED by vnxcppcodegen

#include <vnx/database/package.hxx>
#include <vnx/database/ServerAsyncClient.hxx>
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

#include <vnx/Generic.hxx>
#include <vnx/vnx.h>


namespace vnx {
namespace database {

ServerAsyncClient::ServerAsyncClient(const std::string& service_name)
	:	AsyncClient::AsyncClient(vnx::Hash64(service_name))
{
}

ServerAsyncClient::ServerAsyncClient(vnx::Hash64 service_addr)
	:	AsyncClient::AsyncClient(service_addr)
{
}

uint64_t ServerAsyncClient::vnx_get_config_object(const std::function<void(const ::vnx::Object&)>& _callback, const std::function<void(const vnx::exception&)>& _error_callback) {
	auto _method = ::vnx::ModuleInterface_vnx_get_config_object::create();
	const auto _request_id = ++vnx_next_id;
	{
		std::lock_guard<std::mutex> _lock(vnx_mutex);
		vnx_pending[_request_id] = 0;
		vnx_queue_vnx_get_config_object[_request_id] = std::make_pair(_callback, _error_callback);
	}
	vnx_request(_method, _request_id);
	return _request_id;
}

uint64_t ServerAsyncClient::vnx_get_config(const std::string& name, const std::function<void(const ::vnx::Variant&)>& _callback, const std::function<void(const vnx::exception&)>& _error_callback) {
	auto _method = ::vnx::ModuleInterface_vnx_get_config::create();
	_method->name = name;
	const auto _request_id = ++vnx_next_id;
	{
		std::lock_guard<std::mutex> _lock(vnx_mutex);
		vnx_pending[_request_id] = 1;
		vnx_queue_vnx_get_config[_request_id] = std::make_pair(_callback, _error_callback);
	}
	vnx_request(_method, _request_id);
	return _request_id;
}

uint64_t ServerAsyncClient::vnx_set_config_object(const ::vnx::Object& config, const std::function<void()>& _callback, const std::function<void(const vnx::exception&)>& _error_callback) {
	auto _method = ::vnx::ModuleInterface_vnx_set_config_object::create();
	_method->config = config;
	const auto _request_id = ++vnx_next_id;
	{
		std::lock_guard<std::mutex> _lock(vnx_mutex);
		vnx_pending[_request_id] = 2;
		vnx_queue_vnx_set_config_object[_request_id] = std::make_pair(_callback, _error_callback);
	}
	vnx_request(_method, _request_id);
	return _request_id;
}

uint64_t ServerAsyncClient::vnx_set_config(const std::string& name, const ::vnx::Variant& value, const std::function<void()>& _callback, const std::function<void(const vnx::exception&)>& _error_callback) {
	auto _method = ::vnx::ModuleInterface_vnx_set_config::create();
	_method->name = name;
	_method->value = value;
	const auto _request_id = ++vnx_next_id;
	{
		std::lock_guard<std::mutex> _lock(vnx_mutex);
		vnx_pending[_request_id] = 3;
		vnx_queue_vnx_set_config[_request_id] = std::make_pair(_callback, _error_callback);
	}
	vnx_request(_method, _request_id);
	return _request_id;
}

uint64_t ServerAsyncClient::vnx_get_type_code(const std::function<void(const ::vnx::TypeCode&)>& _callback, const std::function<void(const vnx::exception&)>& _error_callback) {
	auto _method = ::vnx::ModuleInterface_vnx_get_type_code::create();
	const auto _request_id = ++vnx_next_id;
	{
		std::lock_guard<std::mutex> _lock(vnx_mutex);
		vnx_pending[_request_id] = 4;
		vnx_queue_vnx_get_type_code[_request_id] = std::make_pair(_callback, _error_callback);
	}
	vnx_request(_method, _request_id);
	return _request_id;
}

uint64_t ServerAsyncClient::vnx_get_module_info(const std::function<void(std::shared_ptr<const ::vnx::ModuleInfo>)>& _callback, const std::function<void(const vnx::exception&)>& _error_callback) {
	auto _method = ::vnx::ModuleInterface_vnx_get_module_info::create();
	const auto _request_id = ++vnx_next_id;
	{
		std::lock_guard<std::mutex> _lock(vnx_mutex);
		vnx_pending[_request_id] = 5;
		vnx_queue_vnx_get_module_info[_request_id] = std::make_pair(_callback, _error_callback);
	}
	vnx_request(_method, _request_id);
	return _request_id;
}

uint64_t ServerAsyncClient::vnx_restart(const std::function<void()>& _callback, const std::function<void(const vnx::exception&)>& _error_callback) {
	auto _method = ::vnx::ModuleInterface_vnx_restart::create();
	const auto _request_id = ++vnx_next_id;
	{
		std::lock_guard<std::mutex> _lock(vnx_mutex);
		vnx_pending[_request_id] = 6;
		vnx_queue_vnx_restart[_request_id] = std::make_pair(_callback, _error_callback);
	}
	vnx_request(_method, _request_id);
	return _request_id;
}

uint64_t ServerAsyncClient::vnx_stop(const std::function<void()>& _callback, const std::function<void(const vnx::exception&)>& _error_callback) {
	auto _method = ::vnx::ModuleInterface_vnx_stop::create();
	const auto _request_id = ++vnx_next_id;
	{
		std::lock_guard<std::mutex> _lock(vnx_mutex);
		vnx_pending[_request_id] = 7;
		vnx_queue_vnx_stop[_request_id] = std::make_pair(_callback, _error_callback);
	}
	vnx_request(_method, _request_id);
	return _request_id;
}

uint64_t ServerAsyncClient::vnx_self_test(const std::function<void(const vnx::bool_t&)>& _callback, const std::function<void(const vnx::exception&)>& _error_callback) {
	auto _method = ::vnx::ModuleInterface_vnx_self_test::create();
	const auto _request_id = ++vnx_next_id;
	{
		std::lock_guard<std::mutex> _lock(vnx_mutex);
		vnx_pending[_request_id] = 8;
		vnx_queue_vnx_self_test[_request_id] = std::make_pair(_callback, _error_callback);
	}
	vnx_request(_method, _request_id);
	return _request_id;
}

uint64_t ServerAsyncClient::sql_query(const std::string& query, const std::function<void(const std::vector<::vnx::Object>&)>& _callback, const std::function<void(const vnx::exception&)>& _error_callback) {
	auto _method = ::vnx::database::Server_sql_query::create();
	_method->query = query;
	const auto _request_id = ++vnx_next_id;
	{
		std::lock_guard<std::mutex> _lock(vnx_mutex);
		vnx_pending[_request_id] = 9;
		vnx_queue_sql_query[_request_id] = std::make_pair(_callback, _error_callback);
	}
	vnx_request(_method, _request_id);
	return _request_id;
}

uint64_t ServerAsyncClient::sql_update(const std::string& query, const std::function<void()>& _callback, const std::function<void(const vnx::exception&)>& _error_callback) {
	auto _method = ::vnx::database::Server_sql_update::create();
	_method->query = query;
	const auto _request_id = ++vnx_next_id;
	{
		std::lock_guard<std::mutex> _lock(vnx_mutex);
		vnx_pending[_request_id] = 10;
		vnx_queue_sql_update[_request_id] = std::make_pair(_callback, _error_callback);
	}
	vnx_request(_method, _request_id);
	return _request_id;
}

uint64_t ServerAsyncClient::select(const ::vnx::query::Select& query, const std::function<void(const std::vector<::vnx::Object>&)>& _callback, const std::function<void(const vnx::exception&)>& _error_callback) {
	auto _method = ::vnx::database::Server_select::create();
	_method->query = query;
	const auto _request_id = ++vnx_next_id;
	{
		std::lock_guard<std::mutex> _lock(vnx_mutex);
		vnx_pending[_request_id] = 11;
		vnx_queue_select[_request_id] = std::make_pair(_callback, _error_callback);
	}
	vnx_request(_method, _request_id);
	return _request_id;
}

uint64_t ServerAsyncClient::update(const ::vnx::query::Update& query, const std::function<void()>& _callback, const std::function<void(const vnx::exception&)>& _error_callback) {
	auto _method = ::vnx::database::Server_update::create();
	_method->query = query;
	const auto _request_id = ++vnx_next_id;
	{
		std::lock_guard<std::mutex> _lock(vnx_mutex);
		vnx_pending[_request_id] = 12;
		vnx_queue_update[_request_id] = std::make_pair(_callback, _error_callback);
	}
	vnx_request(_method, _request_id);
	return _request_id;
}

uint64_t ServerAsyncClient::delete_from(const ::vnx::query::Delete& query, const std::function<void()>& _callback, const std::function<void(const vnx::exception&)>& _error_callback) {
	auto _method = ::vnx::database::Server_delete_from::create();
	_method->query = query;
	const auto _request_id = ++vnx_next_id;
	{
		std::lock_guard<std::mutex> _lock(vnx_mutex);
		vnx_pending[_request_id] = 13;
		vnx_queue_delete_from[_request_id] = std::make_pair(_callback, _error_callback);
	}
	vnx_request(_method, _request_id);
	return _request_id;
}

uint64_t ServerAsyncClient::select_one(const std::string& table, const ::vnx::Hash128& id, const std::function<void(const ::vnx::Object&)>& _callback, const std::function<void(const vnx::exception&)>& _error_callback) {
	auto _method = ::vnx::database::Server_select_one::create();
	_method->table = table;
	_method->id = id;
	const auto _request_id = ++vnx_next_id;
	{
		std::lock_guard<std::mutex> _lock(vnx_mutex);
		vnx_pending[_request_id] = 14;
		vnx_queue_select_one[_request_id] = std::make_pair(_callback, _error_callback);
	}
	vnx_request(_method, _request_id);
	return _request_id;
}

uint64_t ServerAsyncClient::select_many(const std::string& table, const std::vector<::vnx::Hash128>& ids, const std::function<void(const std::vector<::vnx::Object>&)>& _callback, const std::function<void(const vnx::exception&)>& _error_callback) {
	auto _method = ::vnx::database::Server_select_many::create();
	_method->table = table;
	_method->ids = ids;
	const auto _request_id = ++vnx_next_id;
	{
		std::lock_guard<std::mutex> _lock(vnx_mutex);
		vnx_pending[_request_id] = 15;
		vnx_queue_select_many[_request_id] = std::make_pair(_callback, _error_callback);
	}
	vnx_request(_method, _request_id);
	return _request_id;
}

uint64_t ServerAsyncClient::insert_one(const std::string& table, const ::vnx::Hash128& id, const ::vnx::Object& object, const std::function<void()>& _callback, const std::function<void(const vnx::exception&)>& _error_callback) {
	auto _method = ::vnx::database::Server_insert_one::create();
	_method->table = table;
	_method->id = id;
	_method->object = object;
	const auto _request_id = ++vnx_next_id;
	{
		std::lock_guard<std::mutex> _lock(vnx_mutex);
		vnx_pending[_request_id] = 16;
		vnx_queue_insert_one[_request_id] = std::make_pair(_callback, _error_callback);
	}
	vnx_request(_method, _request_id);
	return _request_id;
}

uint64_t ServerAsyncClient::insert_many(const std::string& table, const std::map<::vnx::Hash128, ::vnx::Object>& objects, const std::function<void()>& _callback, const std::function<void(const vnx::exception&)>& _error_callback) {
	auto _method = ::vnx::database::Server_insert_many::create();
	_method->table = table;
	_method->objects = objects;
	const auto _request_id = ++vnx_next_id;
	{
		std::lock_guard<std::mutex> _lock(vnx_mutex);
		vnx_pending[_request_id] = 17;
		vnx_queue_insert_many[_request_id] = std::make_pair(_callback, _error_callback);
	}
	vnx_request(_method, _request_id);
	return _request_id;
}

uint64_t ServerAsyncClient::update_one(const std::string& table, const ::vnx::Hash128& id, const ::vnx::Object& object, const std::function<void()>& _callback, const std::function<void(const vnx::exception&)>& _error_callback) {
	auto _method = ::vnx::database::Server_update_one::create();
	_method->table = table;
	_method->id = id;
	_method->object = object;
	const auto _request_id = ++vnx_next_id;
	{
		std::lock_guard<std::mutex> _lock(vnx_mutex);
		vnx_pending[_request_id] = 18;
		vnx_queue_update_one[_request_id] = std::make_pair(_callback, _error_callback);
	}
	vnx_request(_method, _request_id);
	return _request_id;
}

uint64_t ServerAsyncClient::update_many(const std::string& table, const std::map<::vnx::Hash128, ::vnx::Object>& objects, const std::function<void()>& _callback, const std::function<void(const vnx::exception&)>& _error_callback) {
	auto _method = ::vnx::database::Server_update_many::create();
	_method->table = table;
	_method->objects = objects;
	const auto _request_id = ++vnx_next_id;
	{
		std::lock_guard<std::mutex> _lock(vnx_mutex);
		vnx_pending[_request_id] = 19;
		vnx_queue_update_many[_request_id] = std::make_pair(_callback, _error_callback);
	}
	vnx_request(_method, _request_id);
	return _request_id;
}

uint64_t ServerAsyncClient::delete_one(const std::string& table, const ::vnx::Hash128& id, const std::function<void()>& _callback, const std::function<void(const vnx::exception&)>& _error_callback) {
	auto _method = ::vnx::database::Server_delete_one::create();
	_method->table = table;
	_method->id = id;
	const auto _request_id = ++vnx_next_id;
	{
		std::lock_guard<std::mutex> _lock(vnx_mutex);
		vnx_pending[_request_id] = 20;
		vnx_queue_delete_one[_request_id] = std::make_pair(_callback, _error_callback);
	}
	vnx_request(_method, _request_id);
	return _request_id;
}

uint64_t ServerAsyncClient::delete_many(const std::string& table, const std::vector<::vnx::Hash128>& ids, const std::function<void()>& _callback, const std::function<void(const vnx::exception&)>& _error_callback) {
	auto _method = ::vnx::database::Server_delete_many::create();
	_method->table = table;
	_method->ids = ids;
	const auto _request_id = ++vnx_next_id;
	{
		std::lock_guard<std::mutex> _lock(vnx_mutex);
		vnx_pending[_request_id] = 21;
		vnx_queue_delete_many[_request_id] = std::make_pair(_callback, _error_callback);
	}
	vnx_request(_method, _request_id);
	return _request_id;
}

uint64_t ServerAsyncClient::truncate(const std::string& table, const std::function<void()>& _callback, const std::function<void(const vnx::exception&)>& _error_callback) {
	auto _method = ::vnx::database::Server_truncate::create();
	_method->table = table;
	const auto _request_id = ++vnx_next_id;
	{
		std::lock_guard<std::mutex> _lock(vnx_mutex);
		vnx_pending[_request_id] = 22;
		vnx_queue_truncate[_request_id] = std::make_pair(_callback, _error_callback);
	}
	vnx_request(_method, _request_id);
	return _request_id;
}

uint64_t ServerAsyncClient::get_table_info(const std::function<void(const std::vector<::vnx::database::table_info_t>&)>& _callback, const std::function<void(const vnx::exception&)>& _error_callback) {
	auto _method = ::vnx::database::Server_get_table_info::create();
	const auto _request_id = ++vnx_next_id;
	{
		std::lock_guard<std::mutex> _lock(vnx_mutex);
		vnx_pending[_request_id] = 23;
		vnx_queue_get_table_info[_request_id] = std::make_pair(_callback, _error_callback);
	}
	vnx_request(_method, _request_id);
	return _request_id;
}

uint64_t ServerAsyncClient::write_new_block(const std::function<void()>& _callback, const std::function<void(const vnx::exception&)>& _error_callback) {
	auto _method = ::vnx::database::Server_write_new_block::create();
	const auto _request_id = ++vnx_next_id;
	{
		std::lock_guard<std::mutex> _lock(vnx_mutex);
		vnx_pending[_request_id] = 24;
		vnx_queue_write_new_block[_request_id] = std::make_pair(_callback, _error_callback);
	}
	vnx_request(_method, _request_id);
	return _request_id;
}

int32_t ServerAsyncClient::vnx_purge_request(uint64_t _request_id, const vnx::exception& _ex) {
	std::unique_lock<std::mutex> _lock(vnx_mutex);
	const auto _iter = vnx_pending.find(_request_id);
	if(_iter == vnx_pending.end()) {
		return -1;
	}
	const auto _index = _iter->second;
	vnx_pending.erase(_iter);
	switch(_index) {
		case 0: {
			const auto _iter = vnx_queue_vnx_get_config_object.find(_request_id);
			if(_iter != vnx_queue_vnx_get_config_object.end()) {
				const auto _callback = std::move(_iter->second.second);
				vnx_queue_vnx_get_config_object.erase(_iter);
				_lock.unlock();
				if(_callback) {
					_callback(_ex);
				}
			}
			break;
		}
		case 1: {
			const auto _iter = vnx_queue_vnx_get_config.find(_request_id);
			if(_iter != vnx_queue_vnx_get_config.end()) {
				const auto _callback = std::move(_iter->second.second);
				vnx_queue_vnx_get_config.erase(_iter);
				_lock.unlock();
				if(_callback) {
					_callback(_ex);
				}
			}
			break;
		}
		case 2: {
			const auto _iter = vnx_queue_vnx_set_config_object.find(_request_id);
			if(_iter != vnx_queue_vnx_set_config_object.end()) {
				const auto _callback = std::move(_iter->second.second);
				vnx_queue_vnx_set_config_object.erase(_iter);
				_lock.unlock();
				if(_callback) {
					_callback(_ex);
				}
			}
			break;
		}
		case 3: {
			const auto _iter = vnx_queue_vnx_set_config.find(_request_id);
			if(_iter != vnx_queue_vnx_set_config.end()) {
				const auto _callback = std::move(_iter->second.second);
				vnx_queue_vnx_set_config.erase(_iter);
				_lock.unlock();
				if(_callback) {
					_callback(_ex);
				}
			}
			break;
		}
		case 4: {
			const auto _iter = vnx_queue_vnx_get_type_code.find(_request_id);
			if(_iter != vnx_queue_vnx_get_type_code.end()) {
				const auto _callback = std::move(_iter->second.second);
				vnx_queue_vnx_get_type_code.erase(_iter);
				_lock.unlock();
				if(_callback) {
					_callback(_ex);
				}
			}
			break;
		}
		case 5: {
			const auto _iter = vnx_queue_vnx_get_module_info.find(_request_id);
			if(_iter != vnx_queue_vnx_get_module_info.end()) {
				const auto _callback = std::move(_iter->second.second);
				vnx_queue_vnx_get_module_info.erase(_iter);
				_lock.unlock();
				if(_callback) {
					_callback(_ex);
				}
			}
			break;
		}
		case 6: {
			const auto _iter = vnx_queue_vnx_restart.find(_request_id);
			if(_iter != vnx_queue_vnx_restart.end()) {
				const auto _callback = std::move(_iter->second.second);
				vnx_queue_vnx_restart.erase(_iter);
				_lock.unlock();
				if(_callback) {
					_callback(_ex);
				}
			}
			break;
		}
		case 7: {
			const auto _iter = vnx_queue_vnx_stop.find(_request_id);
			if(_iter != vnx_queue_vnx_stop.end()) {
				const auto _callback = std::move(_iter->second.second);
				vnx_queue_vnx_stop.erase(_iter);
				_lock.unlock();
				if(_callback) {
					_callback(_ex);
				}
			}
			break;
		}
		case 8: {
			const auto _iter = vnx_queue_vnx_self_test.find(_request_id);
			if(_iter != vnx_queue_vnx_self_test.end()) {
				const auto _callback = std::move(_iter->second.second);
				vnx_queue_vnx_self_test.erase(_iter);
				_lock.unlock();
				if(_callback) {
					_callback(_ex);
				}
			}
			break;
		}
		case 9: {
			const auto _iter = vnx_queue_sql_query.find(_request_id);
			if(_iter != vnx_queue_sql_query.end()) {
				const auto _callback = std::move(_iter->second.second);
				vnx_queue_sql_query.erase(_iter);
				_lock.unlock();
				if(_callback) {
					_callback(_ex);
				}
			}
			break;
		}
		case 10: {
			const auto _iter = vnx_queue_sql_update.find(_request_id);
			if(_iter != vnx_queue_sql_update.end()) {
				const auto _callback = std::move(_iter->second.second);
				vnx_queue_sql_update.erase(_iter);
				_lock.unlock();
				if(_callback) {
					_callback(_ex);
				}
			}
			break;
		}
		case 11: {
			const auto _iter = vnx_queue_select.find(_request_id);
			if(_iter != vnx_queue_select.end()) {
				const auto _callback = std::move(_iter->second.second);
				vnx_queue_select.erase(_iter);
				_lock.unlock();
				if(_callback) {
					_callback(_ex);
				}
			}
			break;
		}
		case 12: {
			const auto _iter = vnx_queue_update.find(_request_id);
			if(_iter != vnx_queue_update.end()) {
				const auto _callback = std::move(_iter->second.second);
				vnx_queue_update.erase(_iter);
				_lock.unlock();
				if(_callback) {
					_callback(_ex);
				}
			}
			break;
		}
		case 13: {
			const auto _iter = vnx_queue_delete_from.find(_request_id);
			if(_iter != vnx_queue_delete_from.end()) {
				const auto _callback = std::move(_iter->second.second);
				vnx_queue_delete_from.erase(_iter);
				_lock.unlock();
				if(_callback) {
					_callback(_ex);
				}
			}
			break;
		}
		case 14: {
			const auto _iter = vnx_queue_select_one.find(_request_id);
			if(_iter != vnx_queue_select_one.end()) {
				const auto _callback = std::move(_iter->second.second);
				vnx_queue_select_one.erase(_iter);
				_lock.unlock();
				if(_callback) {
					_callback(_ex);
				}
			}
			break;
		}
		case 15: {
			const auto _iter = vnx_queue_select_many.find(_request_id);
			if(_iter != vnx_queue_select_many.end()) {
				const auto _callback = std::move(_iter->second.second);
				vnx_queue_select_many.erase(_iter);
				_lock.unlock();
				if(_callback) {
					_callback(_ex);
				}
			}
			break;
		}
		case 16: {
			const auto _iter = vnx_queue_insert_one.find(_request_id);
			if(_iter != vnx_queue_insert_one.end()) {
				const auto _callback = std::move(_iter->second.second);
				vnx_queue_insert_one.erase(_iter);
				_lock.unlock();
				if(_callback) {
					_callback(_ex);
				}
			}
			break;
		}
		case 17: {
			const auto _iter = vnx_queue_insert_many.find(_request_id);
			if(_iter != vnx_queue_insert_many.end()) {
				const auto _callback = std::move(_iter->second.second);
				vnx_queue_insert_many.erase(_iter);
				_lock.unlock();
				if(_callback) {
					_callback(_ex);
				}
			}
			break;
		}
		case 18: {
			const auto _iter = vnx_queue_update_one.find(_request_id);
			if(_iter != vnx_queue_update_one.end()) {
				const auto _callback = std::move(_iter->second.second);
				vnx_queue_update_one.erase(_iter);
				_lock.unlock();
				if(_callback) {
					_callback(_ex);
				}
			}
			break;
		}
		case 19: {
			const auto _iter = vnx_queue_update_many.find(_request_id);
			if(_iter != vnx_queue_update_many.end()) {
				const auto _callback = std::move(_iter->second.second);
				vnx_queue_update_many.erase(_iter);
				_lock.unlock();
				if(_callback) {
					_callback(_ex);
				}
			}
			break;
		}
		case 20: {
			const auto _iter = vnx_queue_delete_one.find(_request_id);
			if(_iter != vnx_queue_delete_one.end()) {
				const auto _callback = std::move(_iter->second.second);
				vnx_queue_delete_one.erase(_iter);
				_lock.unlock();
				if(_callback) {
					_callback(_ex);
				}
			}
			break;
		}
		case 21: {
			const auto _iter = vnx_queue_delete_many.find(_request_id);
			if(_iter != vnx_queue_delete_many.end()) {
				const auto _callback = std::move(_iter->second.second);
				vnx_queue_delete_many.erase(_iter);
				_lock.unlock();
				if(_callback) {
					_callback(_ex);
				}
			}
			break;
		}
		case 22: {
			const auto _iter = vnx_queue_truncate.find(_request_id);
			if(_iter != vnx_queue_truncate.end()) {
				const auto _callback = std::move(_iter->second.second);
				vnx_queue_truncate.erase(_iter);
				_lock.unlock();
				if(_callback) {
					_callback(_ex);
				}
			}
			break;
		}
		case 23: {
			const auto _iter = vnx_queue_get_table_info.find(_request_id);
			if(_iter != vnx_queue_get_table_info.end()) {
				const auto _callback = std::move(_iter->second.second);
				vnx_queue_get_table_info.erase(_iter);
				_lock.unlock();
				if(_callback) {
					_callback(_ex);
				}
			}
			break;
		}
		case 24: {
			const auto _iter = vnx_queue_write_new_block.find(_request_id);
			if(_iter != vnx_queue_write_new_block.end()) {
				const auto _callback = std::move(_iter->second.second);
				vnx_queue_write_new_block.erase(_iter);
				_lock.unlock();
				if(_callback) {
					_callback(_ex);
				}
			}
			break;
		}
	}
	return _index;
}

int32_t ServerAsyncClient::vnx_callback_switch(uint64_t _request_id, std::shared_ptr<const vnx::Value> _value) {
	std::unique_lock<std::mutex> _lock(vnx_mutex);
	const auto _iter = vnx_pending.find(_request_id);
	if(_iter == vnx_pending.end()) {
		throw std::runtime_error("ServerAsyncClient: received unknown return");
	}
	const auto _index = _iter->second;
	vnx_pending.erase(_iter);
	switch(_index) {
		case 0: {
			const auto _iter = vnx_queue_vnx_get_config_object.find(_request_id);
			if(_iter == vnx_queue_vnx_get_config_object.end()) {
				throw std::runtime_error("ServerAsyncClient: callback not found");
			}
			const auto _callback = std::move(_iter->second.first);
			vnx_queue_vnx_get_config_object.erase(_iter);
			_lock.unlock();
			if(_callback) {
				if(auto _result = std::dynamic_pointer_cast<const ::vnx::ModuleInterface_vnx_get_config_object_return>(_value)) {
					_callback(_result->_ret_0);
				} else if(_value && !_value->is_void()) {
					_callback(_value->get_field_by_index(0).to<::vnx::Object>());
				} else {
					throw std::logic_error("ServerAsyncClient: invalid return value");
				}
			}
			break;
		}
		case 1: {
			const auto _iter = vnx_queue_vnx_get_config.find(_request_id);
			if(_iter == vnx_queue_vnx_get_config.end()) {
				throw std::runtime_error("ServerAsyncClient: callback not found");
			}
			const auto _callback = std::move(_iter->second.first);
			vnx_queue_vnx_get_config.erase(_iter);
			_lock.unlock();
			if(_callback) {
				if(auto _result = std::dynamic_pointer_cast<const ::vnx::ModuleInterface_vnx_get_config_return>(_value)) {
					_callback(_result->_ret_0);
				} else if(_value && !_value->is_void()) {
					_callback(_value->get_field_by_index(0).to<::vnx::Variant>());
				} else {
					throw std::logic_error("ServerAsyncClient: invalid return value");
				}
			}
			break;
		}
		case 2: {
			const auto _iter = vnx_queue_vnx_set_config_object.find(_request_id);
			if(_iter == vnx_queue_vnx_set_config_object.end()) {
				throw std::runtime_error("ServerAsyncClient: callback not found");
			}
			const auto _callback = std::move(_iter->second.first);
			vnx_queue_vnx_set_config_object.erase(_iter);
			_lock.unlock();
			if(_callback) {
				_callback();
			}
			break;
		}
		case 3: {
			const auto _iter = vnx_queue_vnx_set_config.find(_request_id);
			if(_iter == vnx_queue_vnx_set_config.end()) {
				throw std::runtime_error("ServerAsyncClient: callback not found");
			}
			const auto _callback = std::move(_iter->second.first);
			vnx_queue_vnx_set_config.erase(_iter);
			_lock.unlock();
			if(_callback) {
				_callback();
			}
			break;
		}
		case 4: {
			const auto _iter = vnx_queue_vnx_get_type_code.find(_request_id);
			if(_iter == vnx_queue_vnx_get_type_code.end()) {
				throw std::runtime_error("ServerAsyncClient: callback not found");
			}
			const auto _callback = std::move(_iter->second.first);
			vnx_queue_vnx_get_type_code.erase(_iter);
			_lock.unlock();
			if(_callback) {
				if(auto _result = std::dynamic_pointer_cast<const ::vnx::ModuleInterface_vnx_get_type_code_return>(_value)) {
					_callback(_result->_ret_0);
				} else if(_value && !_value->is_void()) {
					_callback(_value->get_field_by_index(0).to<::vnx::TypeCode>());
				} else {
					throw std::logic_error("ServerAsyncClient: invalid return value");
				}
			}
			break;
		}
		case 5: {
			const auto _iter = vnx_queue_vnx_get_module_info.find(_request_id);
			if(_iter == vnx_queue_vnx_get_module_info.end()) {
				throw std::runtime_error("ServerAsyncClient: callback not found");
			}
			const auto _callback = std::move(_iter->second.first);
			vnx_queue_vnx_get_module_info.erase(_iter);
			_lock.unlock();
			if(_callback) {
				if(auto _result = std::dynamic_pointer_cast<const ::vnx::ModuleInterface_vnx_get_module_info_return>(_value)) {
					_callback(_result->_ret_0);
				} else if(_value && !_value->is_void()) {
					_callback(_value->get_field_by_index(0).to<std::shared_ptr<const ::vnx::ModuleInfo>>());
				} else {
					throw std::logic_error("ServerAsyncClient: invalid return value");
				}
			}
			break;
		}
		case 6: {
			const auto _iter = vnx_queue_vnx_restart.find(_request_id);
			if(_iter == vnx_queue_vnx_restart.end()) {
				throw std::runtime_error("ServerAsyncClient: callback not found");
			}
			const auto _callback = std::move(_iter->second.first);
			vnx_queue_vnx_restart.erase(_iter);
			_lock.unlock();
			if(_callback) {
				_callback();
			}
			break;
		}
		case 7: {
			const auto _iter = vnx_queue_vnx_stop.find(_request_id);
			if(_iter == vnx_queue_vnx_stop.end()) {
				throw std::runtime_error("ServerAsyncClient: callback not found");
			}
			const auto _callback = std::move(_iter->second.first);
			vnx_queue_vnx_stop.erase(_iter);
			_lock.unlock();
			if(_callback) {
				_callback();
			}
			break;
		}
		case 8: {
			const auto _iter = vnx_queue_vnx_self_test.find(_request_id);
			if(_iter == vnx_queue_vnx_self_test.end()) {
				throw std::runtime_error("ServerAsyncClient: callback not found");
			}
			const auto _callback = std::move(_iter->second.first);
			vnx_queue_vnx_self_test.erase(_iter);
			_lock.unlock();
			if(_callback) {
				if(auto _result = std::dynamic_pointer_cast<const ::vnx::ModuleInterface_vnx_self_test_return>(_value)) {
					_callback(_result->_ret_0);
				} else if(_value && !_value->is_void()) {
					_callback(_value->get_field_by_index(0).to<vnx::bool_t>());
				} else {
					throw std::logic_error("ServerAsyncClient: invalid return value");
				}
			}
			break;
		}
		case 9: {
			const auto _iter = vnx_queue_sql_query.find(_request_id);
			if(_iter == vnx_queue_sql_query.end()) {
				throw std::runtime_error("ServerAsyncClient: callback not found");
			}
			const auto _callback = std::move(_iter->second.first);
			vnx_queue_sql_query.erase(_iter);
			_lock.unlock();
			if(_callback) {
				if(auto _result = std::dynamic_pointer_cast<const ::vnx::database::Server_sql_query_return>(_value)) {
					_callback(_result->_ret_0);
				} else if(_value && !_value->is_void()) {
					_callback(_value->get_field_by_index(0).to<std::vector<::vnx::Object>>());
				} else {
					throw std::logic_error("ServerAsyncClient: invalid return value");
				}
			}
			break;
		}
		case 10: {
			const auto _iter = vnx_queue_sql_update.find(_request_id);
			if(_iter == vnx_queue_sql_update.end()) {
				throw std::runtime_error("ServerAsyncClient: callback not found");
			}
			const auto _callback = std::move(_iter->second.first);
			vnx_queue_sql_update.erase(_iter);
			_lock.unlock();
			if(_callback) {
				_callback();
			}
			break;
		}
		case 11: {
			const auto _iter = vnx_queue_select.find(_request_id);
			if(_iter == vnx_queue_select.end()) {
				throw std::runtime_error("ServerAsyncClient: callback not found");
			}
			const auto _callback = std::move(_iter->second.first);
			vnx_queue_select.erase(_iter);
			_lock.unlock();
			if(_callback) {
				if(auto _result = std::dynamic_pointer_cast<const ::vnx::database::Server_select_return>(_value)) {
					_callback(_result->_ret_0);
				} else if(_value && !_value->is_void()) {
					_callback(_value->get_field_by_index(0).to<std::vector<::vnx::Object>>());
				} else {
					throw std::logic_error("ServerAsyncClient: invalid return value");
				}
			}
			break;
		}
		case 12: {
			const auto _iter = vnx_queue_update.find(_request_id);
			if(_iter == vnx_queue_update.end()) {
				throw std::runtime_error("ServerAsyncClient: callback not found");
			}
			const auto _callback = std::move(_iter->second.first);
			vnx_queue_update.erase(_iter);
			_lock.unlock();
			if(_callback) {
				_callback();
			}
			break;
		}
		case 13: {
			const auto _iter = vnx_queue_delete_from.find(_request_id);
			if(_iter == vnx_queue_delete_from.end()) {
				throw std::runtime_error("ServerAsyncClient: callback not found");
			}
			const auto _callback = std::move(_iter->second.first);
			vnx_queue_delete_from.erase(_iter);
			_lock.unlock();
			if(_callback) {
				_callback();
			}
			break;
		}
		case 14: {
			const auto _iter = vnx_queue_select_one.find(_request_id);
			if(_iter == vnx_queue_select_one.end()) {
				throw std::runtime_error("ServerAsyncClient: callback not found");
			}
			const auto _callback = std::move(_iter->second.first);
			vnx_queue_select_one.erase(_iter);
			_lock.unlock();
			if(_callback) {
				if(auto _result = std::dynamic_pointer_cast<const ::vnx::database::Server_select_one_return>(_value)) {
					_callback(_result->_ret_0);
				} else if(_value && !_value->is_void()) {
					_callback(_value->get_field_by_index(0).to<::vnx::Object>());
				} else {
					throw std::logic_error("ServerAsyncClient: invalid return value");
				}
			}
			break;
		}
		case 15: {
			const auto _iter = vnx_queue_select_many.find(_request_id);
			if(_iter == vnx_queue_select_many.end()) {
				throw std::runtime_error("ServerAsyncClient: callback not found");
			}
			const auto _callback = std::move(_iter->second.first);
			vnx_queue_select_many.erase(_iter);
			_lock.unlock();
			if(_callback) {
				if(auto _result = std::dynamic_pointer_cast<const ::vnx::database::Server_select_many_return>(_value)) {
					_callback(_result->_ret_0);
				} else if(_value && !_value->is_void()) {
					_callback(_value->get_field_by_index(0).to<std::vector<::vnx::Object>>());
				} else {
					throw std::logic_error("ServerAsyncClient: invalid return value");
				}
			}
			break;
		}
		case 16: {
			const auto _iter = vnx_queue_insert_one.find(_request_id);
			if(_iter == vnx_queue_insert_one.end()) {
				throw std::runtime_error("ServerAsyncClient: callback not found");
			}
			const auto _callback = std::move(_iter->second.first);
			vnx_queue_insert_one.erase(_iter);
			_lock.unlock();
			if(_callback) {
				_callback();
			}
			break;
		}
		case 17: {
			const auto _iter = vnx_queue_insert_many.find(_request_id);
			if(_iter == vnx_queue_insert_many.end()) {
				throw std::runtime_error("ServerAsyncClient: callback not found");
			}
			const auto _callback = std::move(_iter->second.first);
			vnx_queue_insert_many.erase(_iter);
			_lock.unlock();
			if(_callback) {
				_callback();
			}
			break;
		}
		case 18: {
			const auto _iter = vnx_queue_update_one.find(_request_id);
			if(_iter == vnx_queue_update_one.end()) {
				throw std::runtime_error("ServerAsyncClient: callback not found");
			}
			const auto _callback = std::move(_iter->second.first);
			vnx_queue_update_one.erase(_iter);
			_lock.unlock();
			if(_callback) {
				_callback();
			}
			break;
		}
		case 19: {
			const auto _iter = vnx_queue_update_many.find(_request_id);
			if(_iter == vnx_queue_update_many.end()) {
				throw std::runtime_error("ServerAsyncClient: callback not found");
			}
			const auto _callback = std::move(_iter->second.first);
			vnx_queue_update_many.erase(_iter);
			_lock.unlock();
			if(_callback) {
				_callback();
			}
			break;
		}
		case 20: {
			const auto _iter = vnx_queue_delete_one.find(_request_id);
			if(_iter == vnx_queue_delete_one.end()) {
				throw std::runtime_error("ServerAsyncClient: callback not found");
			}
			const auto _callback = std::move(_iter->second.first);
			vnx_queue_delete_one.erase(_iter);
			_lock.unlock();
			if(_callback) {
				_callback();
			}
			break;
		}
		case 21: {
			const auto _iter = vnx_queue_delete_many.find(_request_id);
			if(_iter == vnx_queue_delete_many.end()) {
				throw std::runtime_error("ServerAsyncClient: callback not found");
			}
			const auto _callback = std::move(_iter->second.first);
			vnx_queue_delete_many.erase(_iter);
			_lock.unlock();
			if(_callback) {
				_callback();
			}
			break;
		}
		case 22: {
			const auto _iter = vnx_queue_truncate.find(_request_id);
			if(_iter == vnx_queue_truncate.end()) {
				throw std::runtime_error("ServerAsyncClient: callback not found");
			}
			const auto _callback = std::move(_iter->second.first);
			vnx_queue_truncate.erase(_iter);
			_lock.unlock();
			if(_callback) {
				_callback();
			}
			break;
		}
		case 23: {
			const auto _iter = vnx_queue_get_table_info.find(_request_id);
			if(_iter == vnx_queue_get_table_info.end()) {
				throw std::runtime_error("ServerAsyncClient: callback not found");
			}
			const auto _callback = std::move(_iter->second.first);
			vnx_queue_get_table_info.erase(_iter);
			_lock.unlock();
			if(_callback) {
				if(auto _result = std::dynamic_pointer_cast<const ::vnx::database::Server_get_table_info_return>(_value)) {
					_callback(_result->_ret_0);
				} else if(_value && !_value->is_void()) {
					_callback(_value->get_field_by_index(0).to<std::vector<::vnx::database::table_info_t>>());
				} else {
					throw std::logic_error("ServerAsyncClient: invalid return value");
				}
			}
			break;
		}
		case 24: {
			const auto _iter = vnx_queue_write_new_block.find(_request_id);
			if(_iter == vnx_queue_write_new_block.end()) {
				throw std::runtime_error("ServerAsyncClient: callback not found");
			}
			const auto _callback = std::move(_iter->second.first);
			vnx_queue_write_new_block.erase(_iter);
			_lock.unlock();
			if(_callback) {
				_callback();
			}
			break;
		}
		default:
			if(_index >= 0) {
				throw std::logic_error("ServerAsyncClient: invalid callback index");
			}
	}
	return _index;
}


} // namespace vnx
} // namespace database
