
#ifndef INCLUDE_VNX_DATABASE_SERVER_H
#define INCLUDE_VNX_DATABASE_SERVER_H

#include <vnx/database/ServerBase.hxx>

#include <vnx/File.h>
#include <vnx/Request.hxx>

#include <unordered_set>
#include <unordered_map>


namespace vnx {
namespace database {

class Server : public ServerBase {
public:
	Server(const std::string& _vnx_name);

protected:
	void init() override;
	
	void main() override;
	
	std::shared_ptr<const vnx::Return> handle(std::shared_ptr<const vnx::Request> request) override;
	
	std::vector<Object> select(const query::Select& query) const override;
	
	void update(const query::Update& query) override;
	
	void delete_from(const query::Delete& query) override;
	
	Object select_one(const std::string& table, const Hash128& id) const override;
	
	std::vector<Object> select_many(const std::string& table, const std::vector<Hash128>& ids) const override;
	
	void insert_one(const std::string& table, const Hash128& id, const Object& object) override;
	
	void insert_many(const std::string& table, const std::map<Hash128, Object>& objects) override;
	
	void update_one(const std::string& table, const Hash128& id, const Object& object) override;
	
	void update_many(const std::string& table, const std::map<Hash128, Object>& objects) override;
	
	void delete_one(const std::string& table, const Hash128& id) override;
	
	void delete_many(const std::string& table, const std::vector<Hash128>& ids) override;
	
	void truncate(const std::string& table) override;
	
	std::vector<table_info_t> get_table_info() const override;
	
	void write_new_block() override;

private:
	struct table_t {
		Hash128 hash;
		std::shared_ptr<vnx::File> file;
		std::unordered_set<Hash128> rows;
	};
	
	table_t& get_table(const std::string& name);
	
	const table_t& find_table(const std::string& name) const;
	
	bool insert_row(table_t& table, const Hash128& key);
	
	void insert_one(const vnx::Hash128& id, const vnx::Object& object);
	
	void insert_one(table_t& table, const vnx::Hash128& id, const vnx::Object& object);
	
	void update_one(const Hash128& id, const Object& object);
	
	void update_one(table_t& table, const Hash128& id, const Object& object);
	
	void delete_one(const Hash128& id);
	
	void delete_one(table_t& table, const Hash128& id);
	
	const Object* get_object(const Hash128& key) const;
	
	void commit();
	
	void maintain();

private:
	vnx::File stage_file;
	std::shared_ptr<Root> root;
	std::map<std::string, table_t> table_map;
	std::unordered_map<Hash128, Object> index;
	std::unordered_map<Hash128, Object> stage;
	
};
	
	
} // database
} // vnx

#endif // INCLUDE_VNX_DATABASE_SERVER_H
