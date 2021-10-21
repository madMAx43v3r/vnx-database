
// AUTO GENERATED by vnxcppcodegen

#include <vnx/query/package.hxx>
#include <vnx/query/Field.hxx>
#include <vnx/Object.hpp>
#include <vnx/Variant.hpp>
#include <vnx/query/Expression.hxx>

#include <vnx/vnx.h>


namespace vnx {
namespace query {


const vnx::Hash64 Field::VNX_TYPE_HASH(0x3c675ff36d258a82ull);
const vnx::Hash64 Field::VNX_CODE_HASH(0x74268ff405d1088cull);

vnx::Hash64 Field::get_type_hash() const {
	return VNX_TYPE_HASH;
}

std::string Field::get_type_name() const {
	return "vnx.query.Field";
}

const vnx::TypeCode* Field::get_type_code() const {
	return vnx::query::vnx_native_type_code_Field;
}

std::shared_ptr<Field> Field::create() {
	return std::make_shared<Field>();
}

std::shared_ptr<vnx::Value> Field::clone() const {
	return std::make_shared<Field>(*this);
}

void Field::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void Field::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void Field::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = vnx::query::vnx_native_type_code_Field;
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, name);
	_visitor.type_end(*_type_code);
}

void Field::write(std::ostream& _out) const {
	_out << "{\"__type\": \"vnx.query.Field\"";
	_out << ", \"name\": "; vnx::write(_out, name);
	_out << "}";
}

void Field::read(std::istream& _in) {
	if(auto _json = vnx::read_json(_in)) {
		from_object(_json->to_object());
	}
}

vnx::Object Field::to_object() const {
	vnx::Object _object;
	_object["__type"] = "vnx.query.Field";
	_object["name"] = name;
	return _object;
}

void Field::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "name") {
			_entry.second.to(name);
		}
	}
}

vnx::Variant Field::get_field(const std::string& _name) const {
	if(_name == "name") {
		return vnx::Variant(name);
	}
	return vnx::Variant();
}

void Field::set_field(const std::string& _name, const vnx::Variant& _value) {
	if(_name == "name") {
		_value.to(name);
	} else {
		throw std::logic_error("no such field: '" + _name + "'");
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const Field& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, Field& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* Field::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(VNX_TYPE_HASH);
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> Field::static_create_type_code() {
	auto type_code = std::make_shared<vnx::TypeCode>();
	type_code->name = "vnx.query.Field";
	type_code->type_hash = vnx::Hash64(0x3c675ff36d258a82ull);
	type_code->code_hash = vnx::Hash64(0x74268ff405d1088cull);
	type_code->is_native = true;
	type_code->is_class = true;
	type_code->native_size = sizeof(::vnx::query::Field);
	type_code->parents.resize(1);
	type_code->parents[0] = ::vnx::query::Expression::static_get_type_code();
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<Field>(); };
	type_code->fields.resize(1);
	{
		auto& field = type_code->fields[0];
		field.is_extended = true;
		field.name = "name";
		field.code = {32};
	}
	type_code->build();
	return type_code;
}


} // namespace vnx
} // namespace query


namespace vnx {

void read(TypeInput& in, ::vnx::query::Field& value, const TypeCode* type_code, const uint16_t* code) {
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
			case 0: vnx::read(in, value.name, type_code, _field->code.data()); break;
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::vnx::query::Field& value, const TypeCode* type_code, const uint16_t* code) {
	if(code && code[0] == CODE_OBJECT) {
		vnx::write(out, value.to_object(), nullptr, code);
		return;
	}
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = vnx::query::vnx_native_type_code_Field;
		out.write_type_code(type_code);
		vnx::write_class_header<::vnx::query::Field>(out);
	}
	else if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	vnx::write(out, value.name, type_code, type_code->fields[0].code.data());
}

void read(std::istream& in, ::vnx::query::Field& value) {
	value.read(in);
}

void write(std::ostream& out, const ::vnx::query::Field& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::vnx::query::Field& value) {
	value.accept(visitor);
}

} // vnx
