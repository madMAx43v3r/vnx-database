
// AUTO GENERATED by vnxcppcodegen

#include <vnx/query/package.hxx>
#include <vnx/query/GroupBy.hxx>
#include <vnx/Value.h>

#include <vnx/vnx.h>


namespace vnx {
namespace query {


const vnx::Hash64 GroupBy::VNX_TYPE_HASH(0xbc2edcf64acd47a7ull);
const vnx::Hash64 GroupBy::VNX_CODE_HASH(0x56f7d2a0eb68026cull);

vnx::Hash64 GroupBy::get_type_hash() const {
	return VNX_TYPE_HASH;
}

std::string GroupBy::get_type_name() const {
	return "vnx.query.GroupBy";
}

const vnx::TypeCode* GroupBy::get_type_code() const {
	return vnx::query::vnx_native_type_code_GroupBy;
}

std::shared_ptr<GroupBy> GroupBy::create() {
	return std::make_shared<GroupBy>();
}

std::shared_ptr<vnx::Value> GroupBy::clone() const {
	return std::make_shared<GroupBy>(*this);
}

void GroupBy::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void GroupBy::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void GroupBy::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = vnx::query::vnx_native_type_code_GroupBy;
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, field);
	_visitor.type_end(*_type_code);
}

void GroupBy::write(std::ostream& _out) const {
	_out << "{\"__type\": \"vnx.query.GroupBy\"";
	_out << ", \"field\": "; vnx::write(_out, field);
	_out << "}";
}

void GroupBy::read(std::istream& _in) {
	if(auto _json = vnx::read_json(_in)) {
		from_object(_json->to_object());
	}
}

vnx::Object GroupBy::to_object() const {
	vnx::Object _object;
	_object["__type"] = "vnx.query.GroupBy";
	_object["field"] = field;
	return _object;
}

void GroupBy::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "field") {
			_entry.second.to(field);
		}
	}
}

vnx::Variant GroupBy::get_field(const std::string& _name) const {
	if(_name == "field") {
		return vnx::Variant(field);
	}
	return vnx::Variant();
}

void GroupBy::set_field(const std::string& _name, const vnx::Variant& _value) {
	if(_name == "field") {
		_value.to(field);
	} else {
		throw std::logic_error("no such field: '" + _name + "'");
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const GroupBy& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, GroupBy& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* GroupBy::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(VNX_TYPE_HASH);
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> GroupBy::static_create_type_code() {
	auto type_code = std::make_shared<vnx::TypeCode>();
	type_code->name = "vnx.query.GroupBy";
	type_code->type_hash = vnx::Hash64(0xbc2edcf64acd47a7ull);
	type_code->code_hash = vnx::Hash64(0x56f7d2a0eb68026cull);
	type_code->is_native = true;
	type_code->is_class = true;
	type_code->native_size = sizeof(::vnx::query::GroupBy);
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<GroupBy>(); };
	type_code->fields.resize(1);
	{
		auto& field = type_code->fields[0];
		field.is_extended = true;
		field.name = "field";
		field.code = {32};
	}
	type_code->build();
	return type_code;
}


} // namespace vnx
} // namespace query


namespace vnx {

void read(TypeInput& in, ::vnx::query::GroupBy& value, const TypeCode* type_code, const uint16_t* code) {
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
			case 0: vnx::read(in, value.field, type_code, _field->code.data()); break;
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::vnx::query::GroupBy& value, const TypeCode* type_code, const uint16_t* code) {
	if(code && code[0] == CODE_OBJECT) {
		vnx::write(out, value.to_object(), nullptr, code);
		return;
	}
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = vnx::query::vnx_native_type_code_GroupBy;
		out.write_type_code(type_code);
		vnx::write_class_header<::vnx::query::GroupBy>(out);
	}
	else if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	vnx::write(out, value.field, type_code, type_code->fields[0].code.data());
}

void read(std::istream& in, ::vnx::query::GroupBy& value) {
	value.read(in);
}

void write(std::ostream& out, const ::vnx::query::GroupBy& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::vnx::query::GroupBy& value) {
	value.accept(visitor);
}

} // vnx
