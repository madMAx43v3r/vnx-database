
// AUTO GENERATED by vnxcppcodegen

#include <vnx/database/package.hxx>
#include <vnx/database/Server_write_new_block.hxx>
#include <vnx/Value.h>
#include <vnx/database/Server_write_new_block_return.hxx>

#include <vnx/vnx.h>


namespace vnx {
namespace database {


const vnx::Hash64 Server_write_new_block::VNX_TYPE_HASH(0x566c1834091e052aull);
const vnx::Hash64 Server_write_new_block::VNX_CODE_HASH(0x5500c9d55b0e2201ull);

vnx::Hash64 Server_write_new_block::get_type_hash() const {
	return VNX_TYPE_HASH;
}

std::string Server_write_new_block::get_type_name() const {
	return "vnx.database.Server.write_new_block";
}

const vnx::TypeCode* Server_write_new_block::get_type_code() const {
	return vnx::database::vnx_native_type_code_Server_write_new_block;
}

std::shared_ptr<Server_write_new_block> Server_write_new_block::create() {
	return std::make_shared<Server_write_new_block>();
}

std::shared_ptr<vnx::Value> Server_write_new_block::clone() const {
	return std::make_shared<Server_write_new_block>(*this);
}

void Server_write_new_block::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void Server_write_new_block::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void Server_write_new_block::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = vnx::database::vnx_native_type_code_Server_write_new_block;
	_visitor.type_begin(*_type_code);
	_visitor.type_end(*_type_code);
}

void Server_write_new_block::write(std::ostream& _out) const {
	_out << "{\"__type\": \"vnx.database.Server.write_new_block\"";
	_out << "}";
}

void Server_write_new_block::read(std::istream& _in) {
	if(auto _json = vnx::read_json(_in)) {
		from_object(_json->to_object());
	}
}

vnx::Object Server_write_new_block::to_object() const {
	vnx::Object _object;
	_object["__type"] = "vnx.database.Server.write_new_block";
	return _object;
}

void Server_write_new_block::from_object(const vnx::Object& _object) {
}

vnx::Variant Server_write_new_block::get_field(const std::string& _name) const {
	return vnx::Variant();
}

void Server_write_new_block::set_field(const std::string& _name, const vnx::Variant& _value) {
	throw std::logic_error("no such field: '" + _name + "'");
}

/// \private
std::ostream& operator<<(std::ostream& _out, const Server_write_new_block& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, Server_write_new_block& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* Server_write_new_block::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(VNX_TYPE_HASH);
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> Server_write_new_block::static_create_type_code() {
	auto type_code = std::make_shared<vnx::TypeCode>();
	type_code->name = "vnx.database.Server.write_new_block";
	type_code->type_hash = vnx::Hash64(0x566c1834091e052aull);
	type_code->code_hash = vnx::Hash64(0x5500c9d55b0e2201ull);
	type_code->is_native = true;
	type_code->is_class = true;
	type_code->is_method = true;
	type_code->native_size = sizeof(::vnx::database::Server_write_new_block);
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<Server_write_new_block>(); };
	type_code->return_type = ::vnx::database::Server_write_new_block_return::static_get_type_code();
	type_code->build();
	return type_code;
}


} // namespace vnx
} // namespace database


namespace vnx {

void read(TypeInput& in, ::vnx::database::Server_write_new_block& value, const TypeCode* type_code, const uint16_t* code) {
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
	if(type_code->is_matched) {
	}
	for(const auto* _field : type_code->ext_fields) {
		switch(_field->native_index) {
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::vnx::database::Server_write_new_block& value, const TypeCode* type_code, const uint16_t* code) {
	if(code && code[0] == CODE_OBJECT) {
		vnx::write(out, value.to_object(), nullptr, code);
		return;
	}
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = vnx::database::vnx_native_type_code_Server_write_new_block;
		out.write_type_code(type_code);
		vnx::write_class_header<::vnx::database::Server_write_new_block>(out);
	}
	else if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
}

void read(std::istream& in, ::vnx::database::Server_write_new_block& value) {
	value.read(in);
}

void write(std::ostream& out, const ::vnx::database::Server_write_new_block& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::vnx::database::Server_write_new_block& value) {
	value.accept(visitor);
}

} // vnx
