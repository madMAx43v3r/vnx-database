
// AUTO GENERATED by vnxcppcodegen

#include <vnx/query/package.hxx>
#include <vnx/query/Query.hxx>
#include <vnx/Value.h>

#include <vnx/vnx.h>


namespace vnx {
namespace query {


const vnx::Hash64 Query::VNX_TYPE_HASH(0x588a043d9c55a247ull);
const vnx::Hash64 Query::VNX_CODE_HASH(0x71962f482bc991b6ull);

vnx::Hash64 Query::get_type_hash() const {
	return VNX_TYPE_HASH;
}

std::string Query::get_type_name() const {
	return "vnx.query.Query";
}

const vnx::TypeCode* Query::get_type_code() const {
	return vnx::query::vnx_native_type_code_Query;
}

std::shared_ptr<Query> Query::create() {
	return std::make_shared<Query>();
}

std::shared_ptr<vnx::Value> Query::clone() const {
	return std::make_shared<Query>(*this);
}

void Query::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void Query::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void Query::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = vnx::query::vnx_native_type_code_Query;
	_visitor.type_begin(*_type_code);
	_visitor.type_end(*_type_code);
}

void Query::write(std::ostream& _out) const {
	_out << "{\"__type\": \"vnx.query.Query\"";
	_out << "}";
}

void Query::read(std::istream& _in) {
	if(auto _json = vnx::read_json(_in)) {
		from_object(_json->to_object());
	}
}

vnx::Object Query::to_object() const {
	vnx::Object _object;
	_object["__type"] = "vnx.query.Query";
	return _object;
}

void Query::from_object(const vnx::Object& _object) {
}

vnx::Variant Query::get_field(const std::string& _name) const {
	return vnx::Variant();
}

void Query::set_field(const std::string& _name, const vnx::Variant& _value) {
	throw std::logic_error("no such field: '" + _name + "'");
}

/// \private
std::ostream& operator<<(std::ostream& _out, const Query& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, Query& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* Query::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(VNX_TYPE_HASH);
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> Query::static_create_type_code() {
	auto type_code = std::make_shared<vnx::TypeCode>();
	type_code->name = "vnx.query.Query";
	type_code->type_hash = vnx::Hash64(0x588a043d9c55a247ull);
	type_code->code_hash = vnx::Hash64(0x71962f482bc991b6ull);
	type_code->is_native = true;
	type_code->is_class = true;
	type_code->native_size = sizeof(::vnx::query::Query);
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<Query>(); };
	type_code->build();
	return type_code;
}


} // namespace vnx
} // namespace query


namespace vnx {

void read(TypeInput& in, ::vnx::query::Query& value, const TypeCode* type_code, const uint16_t* code) {
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
	in.read(type_code->total_field_size);
	if(type_code->is_matched) {
	}
	for(const auto* _field : type_code->ext_fields) {
		switch(_field->native_index) {
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::vnx::query::Query& value, const TypeCode* type_code, const uint16_t* code) {
	if(code && code[0] == CODE_OBJECT) {
		vnx::write(out, value.to_object(), nullptr, code);
		return;
	}
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = vnx::query::vnx_native_type_code_Query;
		out.write_type_code(type_code);
		vnx::write_class_header<::vnx::query::Query>(out);
	}
	else if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
}

void read(std::istream& in, ::vnx::query::Query& value) {
	value.read(in);
}

void write(std::ostream& out, const ::vnx::query::Query& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::vnx::query::Query& value) {
	value.accept(visitor);
}

} // vnx
