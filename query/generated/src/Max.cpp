
// AUTO GENERATED by vnxcppcodegen

#include <vnx/query/package.hxx>
#include <vnx/query/Max.hxx>
#include <vnx/Object.hpp>
#include <vnx/Variant.hpp>
#include <vnx/query/Aggregate.hxx>
#include <vnx/query/Expression.hxx>

#include <vnx/vnx.h>


namespace vnx {
namespace query {


const vnx::Hash64 Max::VNX_TYPE_HASH(0x1728bd90ff0d8af8ull);
const vnx::Hash64 Max::VNX_CODE_HASH(0xf9a0127ab8ccd211ull);

vnx::Hash64 Max::get_type_hash() const {
	return VNX_TYPE_HASH;
}

std::string Max::get_type_name() const {
	return "vnx.query.Max";
}

const vnx::TypeCode* Max::get_type_code() const {
	return vnx::query::vnx_native_type_code_Max;
}

std::shared_ptr<Max> Max::create() {
	return std::make_shared<Max>();
}

std::shared_ptr<vnx::Value> Max::clone() const {
	return std::make_shared<Max>(*this);
}

void Max::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void Max::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void Max::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = vnx::query::vnx_native_type_code_Max;
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, A);
	_visitor.type_field(_type_code->fields[1], 1); vnx::accept(_visitor, result);
	_visitor.type_end(*_type_code);
}

void Max::write(std::ostream& _out) const {
	_out << "{\"__type\": \"vnx.query.Max\"";
	_out << ", \"A\": "; vnx::write(_out, A);
	_out << ", \"result\": "; vnx::write(_out, result);
	_out << "}";
}

void Max::read(std::istream& _in) {
	if(auto _json = vnx::read_json(_in)) {
		from_object(_json->to_object());
	}
}

vnx::Object Max::to_object() const {
	vnx::Object _object;
	_object["__type"] = "vnx.query.Max";
	_object["A"] = A;
	_object["result"] = result;
	return _object;
}

void Max::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "A") {
			_entry.second.to(A);
		} else if(_entry.first == "result") {
			_entry.second.to(result);
		}
	}
}

vnx::Variant Max::get_field(const std::string& _name) const {
	if(_name == "A") {
		return vnx::Variant(A);
	}
	if(_name == "result") {
		return vnx::Variant(result);
	}
	return vnx::Variant();
}

void Max::set_field(const std::string& _name, const vnx::Variant& _value) {
	if(_name == "A") {
		_value.to(A);
	} else if(_name == "result") {
		_value.to(result);
	} else {
		throw std::logic_error("no such field: '" + _name + "'");
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const Max& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, Max& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* Max::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(VNX_TYPE_HASH);
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> Max::static_create_type_code() {
	auto type_code = std::make_shared<vnx::TypeCode>();
	type_code->name = "vnx.query.Max";
	type_code->type_hash = vnx::Hash64(0x1728bd90ff0d8af8ull);
	type_code->code_hash = vnx::Hash64(0xf9a0127ab8ccd211ull);
	type_code->is_native = true;
	type_code->is_class = true;
	type_code->native_size = sizeof(::vnx::query::Max);
	type_code->parents.resize(1);
	type_code->parents[0] = ::vnx::query::Aggregate::static_get_type_code();
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<Max>(); };
	type_code->fields.resize(2);
	{
		auto& field = type_code->fields[0];
		field.is_extended = true;
		field.name = "A";
		field.code = {16};
	}
	{
		auto& field = type_code->fields[1];
		field.is_extended = true;
		field.name = "result";
		field.code = {17};
	}
	type_code->build();
	return type_code;
}


} // namespace vnx
} // namespace query


namespace vnx {

void read(TypeInput& in, ::vnx::query::Max& value, const TypeCode* type_code, const uint16_t* code) {
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
			case 0: vnx::read(in, value.A, type_code, _field->code.data()); break;
			case 1: vnx::read(in, value.result, type_code, _field->code.data()); break;
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::vnx::query::Max& value, const TypeCode* type_code, const uint16_t* code) {
	if(code && code[0] == CODE_OBJECT) {
		vnx::write(out, value.to_object(), nullptr, code);
		return;
	}
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = vnx::query::vnx_native_type_code_Max;
		out.write_type_code(type_code);
		vnx::write_class_header<::vnx::query::Max>(out);
	}
	else if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	vnx::write(out, value.A, type_code, type_code->fields[0].code.data());
	vnx::write(out, value.result, type_code, type_code->fields[1].code.data());
}

void read(std::istream& in, ::vnx::query::Max& value) {
	value.read(in);
}

void write(std::ostream& out, const ::vnx::query::Max& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::vnx::query::Max& value) {
	value.accept(visitor);
}

} // vnx
