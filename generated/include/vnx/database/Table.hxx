
// AUTO GENERATED by vnxcppcodegen

#ifndef INCLUDE_vnx_database_Table_HXX_
#define INCLUDE_vnx_database_Table_HXX_

#include <vnx/database/package.hxx>
#include <vnx/Hash128.hpp>
#include <vnx/Value.h>


namespace vnx {
namespace database {

class Table : public ::vnx::Value {
public:
	
	std::string name;
	std::vector<::vnx::Hash128> keys;
	
	typedef ::vnx::Value Super;
	
	static const vnx::Hash64 VNX_TYPE_HASH;
	static const vnx::Hash64 VNX_CODE_HASH;
	
	static constexpr uint64_t VNX_TYPE_ID = 0x1c304f2d86bc1758ull;
	
	Table() {}
	
	vnx::Hash64 get_type_hash() const override;
	std::string get_type_name() const override;
	const vnx::TypeCode* get_type_code() const override;
	
	static std::shared_ptr<Table> create();
	std::shared_ptr<vnx::Value> clone() const override;
	
	void read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) override;
	void write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const override;
	
	void read(std::istream& _in) override;
	void write(std::ostream& _out) const override;
	
	void accept(vnx::Visitor& _visitor) const override;
	
	vnx::Object to_object() const override;
	void from_object(const vnx::Object& object) override;
	
	vnx::Variant get_field(const std::string& name) const override;
	void set_field(const std::string& name, const vnx::Variant& value) override;
	
	friend std::ostream& operator<<(std::ostream& _out, const Table& _value);
	friend std::istream& operator>>(std::istream& _in, Table& _value);
	
	static const vnx::TypeCode* static_get_type_code();
	static std::shared_ptr<vnx::TypeCode> static_create_type_code();
	
};


} // namespace vnx
} // namespace database


namespace vnx {

} // vnx

#endif // INCLUDE_vnx_database_Table_HXX_
