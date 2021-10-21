
// AUTO GENERATED by vnxcppcodegen

#include <vnx/database/package.hxx>
#include <vnx/database/table_info_t.hxx>

#include <vnx/vnx.h>


namespace vnx {
namespace database {


const vnx::Hash64 table_info_t::VNX_TYPE_HASH(0x4e487c2dcb24fb05ull);
const vnx::Hash64 table_info_t::VNX_CODE_HASH(0xdbacfeaad50e752full);

vnx::Hash64 table_info_t::get_type_hash() const {
	return VNX_TYPE_HASH;
}

std::string table_info_t::get_type_name() const {
	return "vnx.database.table_info_t";
}

const vnx::TypeCode* table_info_t::get_type_code() const {
	return vnx::database::vnx_native_type_code_table_info_t;
}

std::shared_ptr<table_info_t> table_info_t::create() {
	return std::make_shared<table_info_t>();
}

std::shared_ptr<table_info_t> table_info_t::clone() const {
	return std::make_shared<table_info_t>(*this);
}

void table_info_t::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void table_info_t::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void table_info_t::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = vnx::database::vnx_native_type_code_table_info_t;
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, name);
	_visitor.type_field(_type_code->fields[1], 1); vnx::accept(_visitor, num_rows);
	_visitor.type_end(*_type_code);
}

void table_info_t::write(std::ostream& _out) const {
	_out << "{";
	_out << "\"name\": "; vnx::write(_out, name);
	_out << ", \"num_rows\": "; vnx::write(_out, num_rows);
	_out << "}";
}

void table_info_t::read(std::istream& _in) {
	if(auto _json = vnx::read_json(_in)) {
		from_object(_json->to_object());
	}
}

vnx::Object table_info_t::to_object() const {
	vnx::Object _object;
	_object["__type"] = "vnx.database.table_info_t";
	_object["name"] = name;
	_object["num_rows"] = num_rows;
	return _object;
}

void table_info_t::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "name") {
			_entry.second.to(name);
		} else if(_entry.first == "num_rows") {
			_entry.second.to(num_rows);
		}
	}
}

vnx::Variant table_info_t::get_field(const std::string& _name) const {
	if(_name == "name") {
		return vnx::Variant(name);
	}
	if(_name == "num_rows") {
		return vnx::Variant(num_rows);
	}
	return vnx::Variant();
}

void table_info_t::set_field(const std::string& _name, const vnx::Variant& _value) {
	if(_name == "name") {
		_value.to(name);
	} else if(_name == "num_rows") {
		_value.to(num_rows);
	} else {
		throw std::logic_error("no such field: '" + _name + "'");
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const table_info_t& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, table_info_t& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* table_info_t::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(VNX_TYPE_HASH);
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> table_info_t::static_create_type_code() {
	auto type_code = std::make_shared<vnx::TypeCode>();
	type_code->name = "vnx.database.table_info_t";
	type_code->type_hash = vnx::Hash64(0x4e487c2dcb24fb05ull);
	type_code->code_hash = vnx::Hash64(0xdbacfeaad50e752full);
	type_code->is_native = true;
	type_code->native_size = sizeof(::vnx::database::table_info_t);
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<vnx::Struct<table_info_t>>(); };
	type_code->fields.resize(2);
	{
		auto& field = type_code->fields[0];
		field.is_extended = true;
		field.name = "name";
		field.code = {32};
	}
	{
		auto& field = type_code->fields[1];
		field.data_size = 8;
		field.name = "num_rows";
		field.code = {4};
	}
	type_code->build();
	return type_code;
}


} // namespace vnx
} // namespace database


namespace vnx {

void read(TypeInput& in, ::vnx::database::table_info_t& value, const TypeCode* type_code, const uint16_t* code) {
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
	const char* const _buf = in.read(type_code->total_field_size);
	if(type_code->is_matched) {
		if(const auto* const _field = type_code->field_map[1]) {
			vnx::read_value(_buf + _field->offset, value.num_rows, _field->code.data());
		}
	}
	for(const auto* _field : type_code->ext_fields) {
		switch(_field->native_index) {
			case 0: vnx::read(in, value.name, type_code, _field->code.data()); break;
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::vnx::database::table_info_t& value, const TypeCode* type_code, const uint16_t* code) {
	if(code && code[0] == CODE_OBJECT) {
		vnx::write(out, value.to_object(), nullptr, code);
		return;
	}
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = vnx::database::vnx_native_type_code_table_info_t;
		out.write_type_code(type_code);
		vnx::write_class_header<::vnx::database::table_info_t>(out);
	}
	else if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	char* const _buf = out.write(8);
	vnx::write_value(_buf + 0, value.num_rows);
	vnx::write(out, value.name, type_code, type_code->fields[0].code.data());
}

void read(std::istream& in, ::vnx::database::table_info_t& value) {
	value.read(in);
}

void write(std::ostream& out, const ::vnx::database::table_info_t& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::vnx::database::table_info_t& value) {
	value.accept(visitor);
}

bool is_equivalent<::vnx::database::table_info_t>::operator()(const uint16_t* code, const TypeCode* type_code) {
	if(code[0] != CODE_STRUCT || !type_code) {
		return false;
	}
	type_code = type_code->depends[code[1]];
	return type_code->type_hash == ::vnx::database::table_info_t::VNX_TYPE_HASH && type_code->is_equivalent;
}

} // vnx
