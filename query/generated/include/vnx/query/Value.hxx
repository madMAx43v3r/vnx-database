
// AUTO GENERATED by vnxcppcodegen

#ifndef INCLUDE_vnx_query_Value_HXX_
#define INCLUDE_vnx_query_Value_HXX_

#include <vnx/query/package.hxx>
#include <vnx/Object.hpp>
#include <vnx/Variant.hpp>
#include <vnx/query/Expression.hxx>


namespace vnx {
namespace query {

class Value : public ::vnx::query::Expression {
public:
	
	::vnx::Variant data;
	
	typedef ::vnx::query::Expression Super;
	
	static const vnx::Hash64 VNX_TYPE_HASH;
	static const vnx::Hash64 VNX_CODE_HASH;
	
	static constexpr uint64_t VNX_TYPE_ID = 0xfd3aaed370d889c1ull;
	
	vnx::Hash64 get_type_hash() const override;
	std::string get_type_name() const override;
	const vnx::TypeCode* get_type_code() const override;
	
	virtual ::vnx::Variant execute(const ::vnx::Object& object) const override;
	virtual std::string as_string() const override;
	
	static std::shared_ptr<Value> create();
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
	
	friend std::ostream& operator<<(std::ostream& _out, const Value& _value);
	friend std::istream& operator>>(std::istream& _in, Value& _value);
	
	static const vnx::TypeCode* static_get_type_code();
	static std::shared_ptr<vnx::TypeCode> static_create_type_code();
	
};


} // namespace vnx
} // namespace query


namespace vnx {

} // vnx

#endif // INCLUDE_vnx_query_Value_HXX_
