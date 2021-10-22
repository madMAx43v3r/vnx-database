
// AUTO GENERATED by vnxcppcodegen

#ifndef INCLUDE_vnx_query_PACKAGE_HXX_
#define INCLUDE_vnx_query_PACKAGE_HXX_

#include <vnx/Type.h>

#include <vnx/package.hxx>


namespace vnx {
namespace query {


class Aggregate;
class Average;
class Comparison;
class Count;
class Delete;
class Expression;
class Field;
class Function;
class GroupBy;
class Limit;
class Max;
class Min;
class OrderBy;
class Query;
class Select;
class Sum;
class Unary;
class Update;
class Value;
struct func_type_e;
struct op_type_e;

extern const vnx::TypeCode* const vnx_native_type_code_Aggregate; ///< \private
extern const vnx::TypeCode* const vnx_native_type_code_Average; ///< \private
extern const vnx::TypeCode* const vnx_native_type_code_Comparison; ///< \private
extern const vnx::TypeCode* const vnx_native_type_code_Count; ///< \private
extern const vnx::TypeCode* const vnx_native_type_code_Delete; ///< \private
extern const vnx::TypeCode* const vnx_native_type_code_Expression; ///< \private
extern const vnx::TypeCode* const vnx_native_type_code_Field; ///< \private
extern const vnx::TypeCode* const vnx_native_type_code_Function; ///< \private
extern const vnx::TypeCode* const vnx_native_type_code_GroupBy; ///< \private
extern const vnx::TypeCode* const vnx_native_type_code_Limit; ///< \private
extern const vnx::TypeCode* const vnx_native_type_code_Max; ///< \private
extern const vnx::TypeCode* const vnx_native_type_code_Min; ///< \private
extern const vnx::TypeCode* const vnx_native_type_code_OrderBy; ///< \private
extern const vnx::TypeCode* const vnx_native_type_code_Query; ///< \private
extern const vnx::TypeCode* const vnx_native_type_code_Select; ///< \private
extern const vnx::TypeCode* const vnx_native_type_code_Sum; ///< \private
extern const vnx::TypeCode* const vnx_native_type_code_Unary; ///< \private
extern const vnx::TypeCode* const vnx_native_type_code_Update; ///< \private
extern const vnx::TypeCode* const vnx_native_type_code_Value; ///< \private
extern const vnx::TypeCode* const vnx_native_type_code_func_type_e; ///< \private
extern const vnx::TypeCode* const vnx_native_type_code_op_type_e; ///< \private

} // namespace vnx
} // namespace query


namespace vnx {

void read(TypeInput& in, ::vnx::query::Aggregate& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void read(TypeInput& in, ::vnx::query::Average& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void read(TypeInput& in, ::vnx::query::Comparison& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void read(TypeInput& in, ::vnx::query::Count& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void read(TypeInput& in, ::vnx::query::Delete& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void read(TypeInput& in, ::vnx::query::Expression& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void read(TypeInput& in, ::vnx::query::Field& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void read(TypeInput& in, ::vnx::query::Function& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void read(TypeInput& in, ::vnx::query::GroupBy& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void read(TypeInput& in, ::vnx::query::Limit& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void read(TypeInput& in, ::vnx::query::Max& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void read(TypeInput& in, ::vnx::query::Min& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void read(TypeInput& in, ::vnx::query::OrderBy& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void read(TypeInput& in, ::vnx::query::Query& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void read(TypeInput& in, ::vnx::query::Select& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void read(TypeInput& in, ::vnx::query::Sum& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void read(TypeInput& in, ::vnx::query::Unary& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void read(TypeInput& in, ::vnx::query::Update& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void read(TypeInput& in, ::vnx::query::Value& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void read(TypeInput& in, ::vnx::query::func_type_e& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void read(TypeInput& in, ::vnx::query::op_type_e& value, const TypeCode* type_code, const uint16_t* code); ///< \private

void write(TypeOutput& out, const ::vnx::query::Aggregate& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void write(TypeOutput& out, const ::vnx::query::Average& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void write(TypeOutput& out, const ::vnx::query::Comparison& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void write(TypeOutput& out, const ::vnx::query::Count& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void write(TypeOutput& out, const ::vnx::query::Delete& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void write(TypeOutput& out, const ::vnx::query::Expression& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void write(TypeOutput& out, const ::vnx::query::Field& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void write(TypeOutput& out, const ::vnx::query::Function& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void write(TypeOutput& out, const ::vnx::query::GroupBy& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void write(TypeOutput& out, const ::vnx::query::Limit& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void write(TypeOutput& out, const ::vnx::query::Max& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void write(TypeOutput& out, const ::vnx::query::Min& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void write(TypeOutput& out, const ::vnx::query::OrderBy& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void write(TypeOutput& out, const ::vnx::query::Query& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void write(TypeOutput& out, const ::vnx::query::Select& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void write(TypeOutput& out, const ::vnx::query::Sum& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void write(TypeOutput& out, const ::vnx::query::Unary& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void write(TypeOutput& out, const ::vnx::query::Update& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void write(TypeOutput& out, const ::vnx::query::Value& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void write(TypeOutput& out, const ::vnx::query::func_type_e& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void write(TypeOutput& out, const ::vnx::query::op_type_e& value, const TypeCode* type_code, const uint16_t* code); ///< \private

void read(std::istream& in, ::vnx::query::Aggregate& value); ///< \private
void read(std::istream& in, ::vnx::query::Average& value); ///< \private
void read(std::istream& in, ::vnx::query::Comparison& value); ///< \private
void read(std::istream& in, ::vnx::query::Count& value); ///< \private
void read(std::istream& in, ::vnx::query::Delete& value); ///< \private
void read(std::istream& in, ::vnx::query::Expression& value); ///< \private
void read(std::istream& in, ::vnx::query::Field& value); ///< \private
void read(std::istream& in, ::vnx::query::Function& value); ///< \private
void read(std::istream& in, ::vnx::query::GroupBy& value); ///< \private
void read(std::istream& in, ::vnx::query::Limit& value); ///< \private
void read(std::istream& in, ::vnx::query::Max& value); ///< \private
void read(std::istream& in, ::vnx::query::Min& value); ///< \private
void read(std::istream& in, ::vnx::query::OrderBy& value); ///< \private
void read(std::istream& in, ::vnx::query::Query& value); ///< \private
void read(std::istream& in, ::vnx::query::Select& value); ///< \private
void read(std::istream& in, ::vnx::query::Sum& value); ///< \private
void read(std::istream& in, ::vnx::query::Unary& value); ///< \private
void read(std::istream& in, ::vnx::query::Update& value); ///< \private
void read(std::istream& in, ::vnx::query::Value& value); ///< \private
void read(std::istream& in, ::vnx::query::func_type_e& value); ///< \private
void read(std::istream& in, ::vnx::query::op_type_e& value); ///< \private

void write(std::ostream& out, const ::vnx::query::Aggregate& value); ///< \private
void write(std::ostream& out, const ::vnx::query::Average& value); ///< \private
void write(std::ostream& out, const ::vnx::query::Comparison& value); ///< \private
void write(std::ostream& out, const ::vnx::query::Count& value); ///< \private
void write(std::ostream& out, const ::vnx::query::Delete& value); ///< \private
void write(std::ostream& out, const ::vnx::query::Expression& value); ///< \private
void write(std::ostream& out, const ::vnx::query::Field& value); ///< \private
void write(std::ostream& out, const ::vnx::query::Function& value); ///< \private
void write(std::ostream& out, const ::vnx::query::GroupBy& value); ///< \private
void write(std::ostream& out, const ::vnx::query::Limit& value); ///< \private
void write(std::ostream& out, const ::vnx::query::Max& value); ///< \private
void write(std::ostream& out, const ::vnx::query::Min& value); ///< \private
void write(std::ostream& out, const ::vnx::query::OrderBy& value); ///< \private
void write(std::ostream& out, const ::vnx::query::Query& value); ///< \private
void write(std::ostream& out, const ::vnx::query::Select& value); ///< \private
void write(std::ostream& out, const ::vnx::query::Sum& value); ///< \private
void write(std::ostream& out, const ::vnx::query::Unary& value); ///< \private
void write(std::ostream& out, const ::vnx::query::Update& value); ///< \private
void write(std::ostream& out, const ::vnx::query::Value& value); ///< \private
void write(std::ostream& out, const ::vnx::query::func_type_e& value); ///< \private
void write(std::ostream& out, const ::vnx::query::op_type_e& value); ///< \private

void accept(Visitor& visitor, const ::vnx::query::Aggregate& value); ///< \private
void accept(Visitor& visitor, const ::vnx::query::Average& value); ///< \private
void accept(Visitor& visitor, const ::vnx::query::Comparison& value); ///< \private
void accept(Visitor& visitor, const ::vnx::query::Count& value); ///< \private
void accept(Visitor& visitor, const ::vnx::query::Delete& value); ///< \private
void accept(Visitor& visitor, const ::vnx::query::Expression& value); ///< \private
void accept(Visitor& visitor, const ::vnx::query::Field& value); ///< \private
void accept(Visitor& visitor, const ::vnx::query::Function& value); ///< \private
void accept(Visitor& visitor, const ::vnx::query::GroupBy& value); ///< \private
void accept(Visitor& visitor, const ::vnx::query::Limit& value); ///< \private
void accept(Visitor& visitor, const ::vnx::query::Max& value); ///< \private
void accept(Visitor& visitor, const ::vnx::query::Min& value); ///< \private
void accept(Visitor& visitor, const ::vnx::query::OrderBy& value); ///< \private
void accept(Visitor& visitor, const ::vnx::query::Query& value); ///< \private
void accept(Visitor& visitor, const ::vnx::query::Select& value); ///< \private
void accept(Visitor& visitor, const ::vnx::query::Sum& value); ///< \private
void accept(Visitor& visitor, const ::vnx::query::Unary& value); ///< \private
void accept(Visitor& visitor, const ::vnx::query::Update& value); ///< \private
void accept(Visitor& visitor, const ::vnx::query::Value& value); ///< \private
void accept(Visitor& visitor, const ::vnx::query::func_type_e& value); ///< \private
void accept(Visitor& visitor, const ::vnx::query::op_type_e& value); ///< \private

/// \private
template<>
struct type<::vnx::query::Aggregate> {
	void read(TypeInput& in, ::vnx::query::Aggregate& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::read(in, value, type_code, code);
	}
	void write(TypeOutput& out, const ::vnx::query::Aggregate& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::write(out, value, type_code, code);
	}
	void read(std::istream& in, ::vnx::query::Aggregate& value) {
		vnx::read(in, value);
	}
	void write(std::ostream& out, const ::vnx::query::Aggregate& value) {
		vnx::write(out, value);
	}
	void accept(Visitor& visitor, const ::vnx::query::Aggregate& value) {
		vnx::accept(visitor, value);
	}
	void create_dynamic_code(std::vector<uint16_t>& code);
	void create_dynamic_code(std::vector<uint16_t>& code, const ::vnx::query::Aggregate& value, bool special = false);
};

/// \private
template<>
struct type<::vnx::query::Average> {
	void read(TypeInput& in, ::vnx::query::Average& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::read(in, value, type_code, code);
	}
	void write(TypeOutput& out, const ::vnx::query::Average& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::write(out, value, type_code, code);
	}
	void read(std::istream& in, ::vnx::query::Average& value) {
		vnx::read(in, value);
	}
	void write(std::ostream& out, const ::vnx::query::Average& value) {
		vnx::write(out, value);
	}
	void accept(Visitor& visitor, const ::vnx::query::Average& value) {
		vnx::accept(visitor, value);
	}
	void create_dynamic_code(std::vector<uint16_t>& code);
	void create_dynamic_code(std::vector<uint16_t>& code, const ::vnx::query::Average& value, bool special = false);
};

/// \private
template<>
struct type<::vnx::query::Comparison> {
	void read(TypeInput& in, ::vnx::query::Comparison& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::read(in, value, type_code, code);
	}
	void write(TypeOutput& out, const ::vnx::query::Comparison& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::write(out, value, type_code, code);
	}
	void read(std::istream& in, ::vnx::query::Comparison& value) {
		vnx::read(in, value);
	}
	void write(std::ostream& out, const ::vnx::query::Comparison& value) {
		vnx::write(out, value);
	}
	void accept(Visitor& visitor, const ::vnx::query::Comparison& value) {
		vnx::accept(visitor, value);
	}
	void create_dynamic_code(std::vector<uint16_t>& code);
	void create_dynamic_code(std::vector<uint16_t>& code, const ::vnx::query::Comparison& value, bool special = false);
};

/// \private
template<>
struct type<::vnx::query::Count> {
	void read(TypeInput& in, ::vnx::query::Count& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::read(in, value, type_code, code);
	}
	void write(TypeOutput& out, const ::vnx::query::Count& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::write(out, value, type_code, code);
	}
	void read(std::istream& in, ::vnx::query::Count& value) {
		vnx::read(in, value);
	}
	void write(std::ostream& out, const ::vnx::query::Count& value) {
		vnx::write(out, value);
	}
	void accept(Visitor& visitor, const ::vnx::query::Count& value) {
		vnx::accept(visitor, value);
	}
	void create_dynamic_code(std::vector<uint16_t>& code);
	void create_dynamic_code(std::vector<uint16_t>& code, const ::vnx::query::Count& value, bool special = false);
};

/// \private
template<>
struct type<::vnx::query::Delete> {
	void read(TypeInput& in, ::vnx::query::Delete& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::read(in, value, type_code, code);
	}
	void write(TypeOutput& out, const ::vnx::query::Delete& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::write(out, value, type_code, code);
	}
	void read(std::istream& in, ::vnx::query::Delete& value) {
		vnx::read(in, value);
	}
	void write(std::ostream& out, const ::vnx::query::Delete& value) {
		vnx::write(out, value);
	}
	void accept(Visitor& visitor, const ::vnx::query::Delete& value) {
		vnx::accept(visitor, value);
	}
	void create_dynamic_code(std::vector<uint16_t>& code);
	void create_dynamic_code(std::vector<uint16_t>& code, const ::vnx::query::Delete& value, bool special = false);
};

/// \private
template<>
struct type<::vnx::query::Expression> {
	void read(TypeInput& in, ::vnx::query::Expression& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::read(in, value, type_code, code);
	}
	void write(TypeOutput& out, const ::vnx::query::Expression& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::write(out, value, type_code, code);
	}
	void read(std::istream& in, ::vnx::query::Expression& value) {
		vnx::read(in, value);
	}
	void write(std::ostream& out, const ::vnx::query::Expression& value) {
		vnx::write(out, value);
	}
	void accept(Visitor& visitor, const ::vnx::query::Expression& value) {
		vnx::accept(visitor, value);
	}
	void create_dynamic_code(std::vector<uint16_t>& code);
	void create_dynamic_code(std::vector<uint16_t>& code, const ::vnx::query::Expression& value, bool special = false);
};

/// \private
template<>
struct type<::vnx::query::Field> {
	void read(TypeInput& in, ::vnx::query::Field& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::read(in, value, type_code, code);
	}
	void write(TypeOutput& out, const ::vnx::query::Field& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::write(out, value, type_code, code);
	}
	void read(std::istream& in, ::vnx::query::Field& value) {
		vnx::read(in, value);
	}
	void write(std::ostream& out, const ::vnx::query::Field& value) {
		vnx::write(out, value);
	}
	void accept(Visitor& visitor, const ::vnx::query::Field& value) {
		vnx::accept(visitor, value);
	}
	void create_dynamic_code(std::vector<uint16_t>& code);
	void create_dynamic_code(std::vector<uint16_t>& code, const ::vnx::query::Field& value, bool special = false);
};

/// \private
template<>
struct type<::vnx::query::Function> {
	void read(TypeInput& in, ::vnx::query::Function& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::read(in, value, type_code, code);
	}
	void write(TypeOutput& out, const ::vnx::query::Function& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::write(out, value, type_code, code);
	}
	void read(std::istream& in, ::vnx::query::Function& value) {
		vnx::read(in, value);
	}
	void write(std::ostream& out, const ::vnx::query::Function& value) {
		vnx::write(out, value);
	}
	void accept(Visitor& visitor, const ::vnx::query::Function& value) {
		vnx::accept(visitor, value);
	}
	void create_dynamic_code(std::vector<uint16_t>& code);
	void create_dynamic_code(std::vector<uint16_t>& code, const ::vnx::query::Function& value, bool special = false);
};

/// \private
template<>
struct type<::vnx::query::GroupBy> {
	void read(TypeInput& in, ::vnx::query::GroupBy& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::read(in, value, type_code, code);
	}
	void write(TypeOutput& out, const ::vnx::query::GroupBy& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::write(out, value, type_code, code);
	}
	void read(std::istream& in, ::vnx::query::GroupBy& value) {
		vnx::read(in, value);
	}
	void write(std::ostream& out, const ::vnx::query::GroupBy& value) {
		vnx::write(out, value);
	}
	void accept(Visitor& visitor, const ::vnx::query::GroupBy& value) {
		vnx::accept(visitor, value);
	}
	void create_dynamic_code(std::vector<uint16_t>& code);
	void create_dynamic_code(std::vector<uint16_t>& code, const ::vnx::query::GroupBy& value, bool special = false);
};

/// \private
template<>
struct type<::vnx::query::Limit> {
	void read(TypeInput& in, ::vnx::query::Limit& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::read(in, value, type_code, code);
	}
	void write(TypeOutput& out, const ::vnx::query::Limit& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::write(out, value, type_code, code);
	}
	void read(std::istream& in, ::vnx::query::Limit& value) {
		vnx::read(in, value);
	}
	void write(std::ostream& out, const ::vnx::query::Limit& value) {
		vnx::write(out, value);
	}
	void accept(Visitor& visitor, const ::vnx::query::Limit& value) {
		vnx::accept(visitor, value);
	}
	void create_dynamic_code(std::vector<uint16_t>& code);
	void create_dynamic_code(std::vector<uint16_t>& code, const ::vnx::query::Limit& value, bool special = false);
};

/// \private
template<>
struct type<::vnx::query::Max> {
	void read(TypeInput& in, ::vnx::query::Max& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::read(in, value, type_code, code);
	}
	void write(TypeOutput& out, const ::vnx::query::Max& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::write(out, value, type_code, code);
	}
	void read(std::istream& in, ::vnx::query::Max& value) {
		vnx::read(in, value);
	}
	void write(std::ostream& out, const ::vnx::query::Max& value) {
		vnx::write(out, value);
	}
	void accept(Visitor& visitor, const ::vnx::query::Max& value) {
		vnx::accept(visitor, value);
	}
	void create_dynamic_code(std::vector<uint16_t>& code);
	void create_dynamic_code(std::vector<uint16_t>& code, const ::vnx::query::Max& value, bool special = false);
};

/// \private
template<>
struct type<::vnx::query::Min> {
	void read(TypeInput& in, ::vnx::query::Min& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::read(in, value, type_code, code);
	}
	void write(TypeOutput& out, const ::vnx::query::Min& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::write(out, value, type_code, code);
	}
	void read(std::istream& in, ::vnx::query::Min& value) {
		vnx::read(in, value);
	}
	void write(std::ostream& out, const ::vnx::query::Min& value) {
		vnx::write(out, value);
	}
	void accept(Visitor& visitor, const ::vnx::query::Min& value) {
		vnx::accept(visitor, value);
	}
	void create_dynamic_code(std::vector<uint16_t>& code);
	void create_dynamic_code(std::vector<uint16_t>& code, const ::vnx::query::Min& value, bool special = false);
};

/// \private
template<>
struct type<::vnx::query::OrderBy> {
	void read(TypeInput& in, ::vnx::query::OrderBy& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::read(in, value, type_code, code);
	}
	void write(TypeOutput& out, const ::vnx::query::OrderBy& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::write(out, value, type_code, code);
	}
	void read(std::istream& in, ::vnx::query::OrderBy& value) {
		vnx::read(in, value);
	}
	void write(std::ostream& out, const ::vnx::query::OrderBy& value) {
		vnx::write(out, value);
	}
	void accept(Visitor& visitor, const ::vnx::query::OrderBy& value) {
		vnx::accept(visitor, value);
	}
	void create_dynamic_code(std::vector<uint16_t>& code);
	void create_dynamic_code(std::vector<uint16_t>& code, const ::vnx::query::OrderBy& value, bool special = false);
};

/// \private
template<>
struct type<::vnx::query::Query> {
	void read(TypeInput& in, ::vnx::query::Query& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::read(in, value, type_code, code);
	}
	void write(TypeOutput& out, const ::vnx::query::Query& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::write(out, value, type_code, code);
	}
	void read(std::istream& in, ::vnx::query::Query& value) {
		vnx::read(in, value);
	}
	void write(std::ostream& out, const ::vnx::query::Query& value) {
		vnx::write(out, value);
	}
	void accept(Visitor& visitor, const ::vnx::query::Query& value) {
		vnx::accept(visitor, value);
	}
	void create_dynamic_code(std::vector<uint16_t>& code);
	void create_dynamic_code(std::vector<uint16_t>& code, const ::vnx::query::Query& value, bool special = false);
};

/// \private
template<>
struct type<::vnx::query::Select> {
	void read(TypeInput& in, ::vnx::query::Select& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::read(in, value, type_code, code);
	}
	void write(TypeOutput& out, const ::vnx::query::Select& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::write(out, value, type_code, code);
	}
	void read(std::istream& in, ::vnx::query::Select& value) {
		vnx::read(in, value);
	}
	void write(std::ostream& out, const ::vnx::query::Select& value) {
		vnx::write(out, value);
	}
	void accept(Visitor& visitor, const ::vnx::query::Select& value) {
		vnx::accept(visitor, value);
	}
	void create_dynamic_code(std::vector<uint16_t>& code);
	void create_dynamic_code(std::vector<uint16_t>& code, const ::vnx::query::Select& value, bool special = false);
};

/// \private
template<>
struct type<::vnx::query::Sum> {
	void read(TypeInput& in, ::vnx::query::Sum& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::read(in, value, type_code, code);
	}
	void write(TypeOutput& out, const ::vnx::query::Sum& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::write(out, value, type_code, code);
	}
	void read(std::istream& in, ::vnx::query::Sum& value) {
		vnx::read(in, value);
	}
	void write(std::ostream& out, const ::vnx::query::Sum& value) {
		vnx::write(out, value);
	}
	void accept(Visitor& visitor, const ::vnx::query::Sum& value) {
		vnx::accept(visitor, value);
	}
	void create_dynamic_code(std::vector<uint16_t>& code);
	void create_dynamic_code(std::vector<uint16_t>& code, const ::vnx::query::Sum& value, bool special = false);
};

/// \private
template<>
struct type<::vnx::query::Unary> {
	void read(TypeInput& in, ::vnx::query::Unary& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::read(in, value, type_code, code);
	}
	void write(TypeOutput& out, const ::vnx::query::Unary& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::write(out, value, type_code, code);
	}
	void read(std::istream& in, ::vnx::query::Unary& value) {
		vnx::read(in, value);
	}
	void write(std::ostream& out, const ::vnx::query::Unary& value) {
		vnx::write(out, value);
	}
	void accept(Visitor& visitor, const ::vnx::query::Unary& value) {
		vnx::accept(visitor, value);
	}
	void create_dynamic_code(std::vector<uint16_t>& code);
	void create_dynamic_code(std::vector<uint16_t>& code, const ::vnx::query::Unary& value, bool special = false);
};

/// \private
template<>
struct type<::vnx::query::Update> {
	void read(TypeInput& in, ::vnx::query::Update& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::read(in, value, type_code, code);
	}
	void write(TypeOutput& out, const ::vnx::query::Update& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::write(out, value, type_code, code);
	}
	void read(std::istream& in, ::vnx::query::Update& value) {
		vnx::read(in, value);
	}
	void write(std::ostream& out, const ::vnx::query::Update& value) {
		vnx::write(out, value);
	}
	void accept(Visitor& visitor, const ::vnx::query::Update& value) {
		vnx::accept(visitor, value);
	}
	void create_dynamic_code(std::vector<uint16_t>& code);
	void create_dynamic_code(std::vector<uint16_t>& code, const ::vnx::query::Update& value, bool special = false);
};

/// \private
template<>
struct type<::vnx::query::Value> {
	void read(TypeInput& in, ::vnx::query::Value& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::read(in, value, type_code, code);
	}
	void write(TypeOutput& out, const ::vnx::query::Value& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::write(out, value, type_code, code);
	}
	void read(std::istream& in, ::vnx::query::Value& value) {
		vnx::read(in, value);
	}
	void write(std::ostream& out, const ::vnx::query::Value& value) {
		vnx::write(out, value);
	}
	void accept(Visitor& visitor, const ::vnx::query::Value& value) {
		vnx::accept(visitor, value);
	}
	void create_dynamic_code(std::vector<uint16_t>& code);
	void create_dynamic_code(std::vector<uint16_t>& code, const ::vnx::query::Value& value, bool special = false);
};

/// \private
template<>
struct type<::vnx::query::func_type_e> {
	void read(TypeInput& in, ::vnx::query::func_type_e& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::read(in, value, type_code, code);
	}
	void write(TypeOutput& out, const ::vnx::query::func_type_e& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::write(out, value, type_code, code);
	}
	void read(std::istream& in, ::vnx::query::func_type_e& value) {
		vnx::read(in, value);
	}
	void write(std::ostream& out, const ::vnx::query::func_type_e& value) {
		vnx::write(out, value);
	}
	void accept(Visitor& visitor, const ::vnx::query::func_type_e& value) {
		vnx::accept(visitor, value);
	}
	void create_dynamic_code(std::vector<uint16_t>& code);
	void create_dynamic_code(std::vector<uint16_t>& code, const ::vnx::query::func_type_e& value, bool special = false);
};

/// \private
template<>
struct type<::vnx::query::op_type_e> {
	void read(TypeInput& in, ::vnx::query::op_type_e& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::read(in, value, type_code, code);
	}
	void write(TypeOutput& out, const ::vnx::query::op_type_e& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::write(out, value, type_code, code);
	}
	void read(std::istream& in, ::vnx::query::op_type_e& value) {
		vnx::read(in, value);
	}
	void write(std::ostream& out, const ::vnx::query::op_type_e& value) {
		vnx::write(out, value);
	}
	void accept(Visitor& visitor, const ::vnx::query::op_type_e& value) {
		vnx::accept(visitor, value);
	}
	void create_dynamic_code(std::vector<uint16_t>& code);
	void create_dynamic_code(std::vector<uint16_t>& code, const ::vnx::query::op_type_e& value, bool special = false);
};


} // namespace vnx

#endif // INCLUDE_vnx_query_PACKAGE_HXX_
