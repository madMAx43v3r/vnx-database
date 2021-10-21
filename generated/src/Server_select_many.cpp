
// AUTO GENERATED by vnxcppcodegen

#include <vnx/database/package.hxx>
#include <vnx/database/Server_select_many.hxx>
#include <vnx/Hash128.hpp>
#include <vnx/Value.h>
#include <vnx/database/Server_select_many_return.hxx>

#include <vnx/vnx.h>


namespace vnx {
namespace database {


const vnx::Hash64 Server_select_many::VNX_TYPE_HASH(0xe1346a3b8326c22full);
const vnx::Hash64 Server_select_many::VNX_CODE_HASH(0xbb4f5959ad84dd76ull);

vnx::Hash64 Server_select_many::get_type_hash() const {
	return VNX_TYPE_HASH;
}

std::string Server_select_many::get_type_name() const {
	return "vnx.database.Server.select_many";
}

const vnx::TypeCode* Server_select_many::get_type_code() const {
	return vnx::database::vnx_native_type_code_Server_select_many;
}

std::shared_ptr<Server_select_many> Server_select_many::create() {
	return std::make_shared<Server_select_many>();
}

std::shared_ptr<vnx::Value> Server_select_many::clone() const {
	return std::make_shared<Server_select_many>(*this);
}

void Server_select_many::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void Server_select_many::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void Server_select_many::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = vnx::database::vnx_native_type_code_Server_select_many;
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, table);
	_visitor.type_field(_type_code->fields[1], 1); vnx::accept(_visitor, ids);
	_visitor.type_end(*_type_code);
}

void Server_select_many::write(std::ostream& _out) const {
	_out << "{\"__type\": \"vnx.database.Server.select_many\"";
	_out << ", \"table\": "; vnx::write(_out, table);
	_out << ", \"ids\": "; vnx::write(_out, ids);
	_out << "}";
}

void Server_select_many::read(std::istream& _in) {
	if(auto _json = vnx::read_json(_in)) {
		from_object(_json->to_object());
	}
}

vnx::Object Server_select_many::to_object() const {
	vnx::Object _object;
	_object["__type"] = "vnx.database.Server.select_many";
	_object["table"] = table;
	_object["ids"] = ids;
	return _object;
}

void Server_select_many::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "ids") {
			_entry.second.to(ids);
		} else if(_entry.first == "table") {
			_entry.second.to(table);
		}
	}
}

vnx::Variant Server_select_many::get_field(const std::string& _name) const {
	if(_name == "table") {
		return vnx::Variant(table);
	}
	if(_name == "ids") {
		return vnx::Variant(ids);
	}
	return vnx::Variant();
}

void Server_select_many::set_field(const std::string& _name, const vnx::Variant& _value) {
	if(_name == "table") {
		_value.to(table);
	} else if(_name == "ids") {
		_value.to(ids);
	} else {
		throw std::logic_error("no such field: '" + _name + "'");
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const Server_select_many& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, Server_select_many& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* Server_select_many::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(VNX_TYPE_HASH);
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> Server_select_many::static_create_type_code() {
	auto type_code = std::make_shared<vnx::TypeCode>();
	type_code->name = "vnx.database.Server.select_many";
	type_code->type_hash = vnx::Hash64(0xe1346a3b8326c22full);
	type_code->code_hash = vnx::Hash64(0xbb4f5959ad84dd76ull);
	type_code->is_native = true;
	type_code->is_class = true;
	type_code->is_method = true;
	type_code->native_size = sizeof(::vnx::database::Server_select_many);
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<Server_select_many>(); };
	type_code->is_const = true;
	type_code->return_type = ::vnx::database::Server_select_many_return::static_get_type_code();
	type_code->fields.resize(2);
	{
		auto& field = type_code->fields[0];
		field.is_extended = true;
		field.name = "table";
		field.code = {32};
	}
	{
		auto& field = type_code->fields[1];
		field.is_extended = true;
		field.name = "ids";
		field.code = {12, 11, 2, 4};
	}
	type_code->build();
	return type_code;
}


} // namespace vnx
} // namespace database


namespace vnx {

void read(TypeInput& in, ::vnx::database::Server_select_many& value, const TypeCode* type_code, const uint16_t* code) {
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
			case 0: vnx::read(in, value.table, type_code, _field->code.data()); break;
			case 1: vnx::read(in, value.ids, type_code, _field->code.data()); break;
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::vnx::database::Server_select_many& value, const TypeCode* type_code, const uint16_t* code) {
	if(code && code[0] == CODE_OBJECT) {
		vnx::write(out, value.to_object(), nullptr, code);
		return;
	}
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = vnx::database::vnx_native_type_code_Server_select_many;
		out.write_type_code(type_code);
		vnx::write_class_header<::vnx::database::Server_select_many>(out);
	}
	else if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	vnx::write(out, value.table, type_code, type_code->fields[0].code.data());
	vnx::write(out, value.ids, type_code, type_code->fields[1].code.data());
}

void read(std::istream& in, ::vnx::database::Server_select_many& value) {
	value.read(in);
}

void write(std::ostream& out, const ::vnx::database::Server_select_many& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::vnx::database::Server_select_many& value) {
	value.accept(visitor);
}

} // vnx
