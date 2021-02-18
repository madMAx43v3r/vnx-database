
// AUTO GENERATED by vnxcppcodegen

#ifndef INCLUDE_vnx_query_Unary_HXX_
#define INCLUDE_vnx_query_Unary_HXX_

#include <vnx/query/package.hxx>
#include <vnx/Object.hpp>
#include <vnx/Variant.hpp>
#include <vnx/query/Expression.hxx>
#include <vnx/query/op_type_e.hxx>


namespace vnx {
namespace query {

class Unary : public ::vnx::query::Expression {
public:
	
	::vnx::query::op_type_e type;
	std::shared_ptr<const ::vnx::query::Expression> X;
	
	typedef ::vnx::query::Expression Super;
	
	static const vnx::Hash64 VNX_TYPE_HASH;
	static const vnx::Hash64 VNX_CODE_HASH;
	
	static constexpr uint64_t VNX_TYPE_ID = 0xc3bf356643366557ull;
	
	vnx::Hash64 get_type_hash() const override;
	std::string get_type_name() const override;
	const vnx::TypeCode* get_type_code() const override;
	
	virtual ::vnx::Variant execute(const ::vnx::Object& object) const override;
	virtual std::string as_string() const override;
	
	static std::shared_ptr<Unary> create();
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
	
	friend std::ostream& operator<<(std::ostream& _out, const Unary& _value);
	friend std::istream& operator>>(std::istream& _in, Unary& _value);
	
	static const vnx::TypeCode* static_get_type_code();
	static std::shared_ptr<vnx::TypeCode> static_create_type_code();
	
};


} // namespace vnx
} // namespace query


namespace vnx {

} // vnx

#endif // INCLUDE_vnx_query_Unary_HXX_
