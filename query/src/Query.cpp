
#include <vnx/query/query.h>

#include <sstream>


namespace vnx {
namespace query {

Variant Expression::execute(const Object& object) const {
	return Variant();
}

Variant Field::execute(const Object& object) const {
	return object[name];
}

Variant Value::execute(const Object& object) const {
	return data;
}

Variant Unary::execute(const Object& object) const {
	if(!X) {
		throw std::logic_error("execute(): !X");
	}
	const Variant tmp = X->execute(object);
	switch(type) {
		case op_type_e::NOT:		return Variant(!bool(tmp));
		case op_type_e::IS_NULL:	return Variant(tmp.is_null());
		case op_type_e::NOT_NULL:	return Variant(!tmp.is_null());
	}
	return Variant();
}

Variant Comparison::execute(const Object& object) const {
	if(!bool(L) || !bool(R)) {
		throw std::logic_error("execute(): !L || !R");
	}
	const Variant lhs = L->execute(object);
	const Variant rhs = R->execute(object);
	switch(type) {
		case op_type_e::AND:			return Variant(bool(lhs) && bool(rhs));
		case op_type_e::OR:				return Variant(bool(lhs) || bool(rhs));
		case op_type_e::EQUAL:			return Variant(lhs == rhs);
		case op_type_e::NOT_EQUAL:		return Variant(lhs != rhs);
		case op_type_e::LESS:			return Variant(lhs < rhs);
		case op_type_e::LESS_EQUAL:		return Variant(lhs <= rhs);
		case op_type_e::GREATER:		return Variant(lhs > rhs);
		case op_type_e::GREATER_EQUAL:	return Variant(lhs >= rhs);
	}
	return Variant();
}

Variant Function::execute(const Object& object) const {
	// TODO
	return Variant();
}


void Aggregate::update(const Object& object) {
	// nothing
}

void Min::update(const Object& object) {
	if(!A) {
		throw std::logic_error("update(): !A");
	}
	const Variant tmp = A->execute(object);
	if(result.empty() || tmp < result) {
		result = tmp;
	}
}

void Max::update(const Object& object) {
	if(!A) {
		throw std::logic_error("update(): !A");
	}
	const Variant tmp = A->execute(object);
	if(result.empty() || tmp > result) {
		result = tmp;
	}
}

void Sum::update(const Object& object) {
	if(!A) {
		throw std::logic_error("update(): !A");
	}
	result += A->execute(object).to<float64_t>();
}

void Average::update(const Object& object) {
	if(!A) {
		throw std::logic_error("update(): !A");
	}
	const Variant value = A->execute(object);
	if(!value.empty()) {
		sum += value.to<float64_t>();
		count++;
	}
}

void Count::update(const Object& object) {
	result++;
}


Variant Aggregate::get_result() const {
	return Variant();
}

Variant Min::get_result() const {
	return result;
}

Variant Max::get_result() const {
	return result;
}

Variant Sum::get_result() const {
	return Variant(result);
}

Variant Average::get_result() const {
	return Variant(count > 0 ? float64_t(sum) / float64_t(count) : float64_t(0));
}

Variant Count::get_result() const {
	return Variant(result);
}


std::string Aggregate::as_string() const {
	return "?";
}

std::string Expression::as_string() const {
	return "?";
}

std::string Count::as_string() const {
	return "COUNT()";
}

std::string Field::as_string() const {
	return name;
}

std::string Value::as_string() const {
	return data.to_string();
}

std::string Unary::as_string() const {
	switch(type) {
		case op_type_e::NOT:		return "NOT " + (X ? X->as_string() : "?");
		case op_type_e::IS_NULL:	return (X ? X->as_string() : "?") + " IS NULL";
		case op_type_e::NOT_NULL:	return (X ? X->as_string() : "?") + " IS NOT NULL";
	}
	return "?";
}

std::string Comparison::as_string() const {
	switch(type) {
		case op_type_e::AND:			return "(" + (L ? L->as_string() : "?") + " AND " + (R ? R->as_string() : "?") + ")";
		case op_type_e::OR:				return "(" + (L ? L->as_string() : "?") + " OR " + (R ? R->as_string() : "?") + ")";
		case op_type_e::EQUAL:			return (L ? L->as_string() : "?") + " = " + (R ? R->as_string() : "?");
		case op_type_e::NOT_EQUAL:		return (L ? L->as_string() : "?") + " <> " + (R ? R->as_string() : "?");
		case op_type_e::LESS:			return (L ? L->as_string() : "?") + " < " + (R ? R->as_string() : "?");
		case op_type_e::LESS_EQUAL:		return (L ? L->as_string() : "?") + " <= " + (R ? R->as_string() : "?");
		case op_type_e::GREATER:		return (L ? L->as_string() : "?") + " > " + (R ? R->as_string() : "?");
		case op_type_e::GREATER_EQUAL:	return (L ? L->as_string() : "?") + " >= " + (R ? R->as_string() : "?");
	}
	return "?";
}

std::string Function::as_string() const {
	// TODO
	return "?";
}

std::string Sum::as_string() const {
	return "SUM(" + (A ? A->as_string() : "?") + ")";
}

std::string Min::as_string() const {
	return "MIN(" + (A ? A->as_string() : "?") + ")";
}

std::string Max::as_string() const {
	return "MAX(" + (A ? A->as_string() : "?") + ")";
}

std::string Average::as_string() const {
	return "AVG(" + (A ? A->as_string() : "?") + ")";
}

std::string OrderBy::as_string() const {
	std::string mode_ = "?";
	switch(mode) {
		case ASC: mode_ = "ASC"; break;
		case DESC: mode_ = "DESC"; break;
	}
	return "ORDER BY " + field + " " + mode_;
}

std::string GroupBy::as_string() const {
	return "GROUP BY " + field;
}

std::string Limit::as_string() const {
	return (num_rows > 0 ? "LIMIT " + std::to_string(num_rows) : "")
			+ (offset ? std::string(num_rows > 0 ? " " : "") + "OFFSET " + std::to_string(offset) : "");
}

std::string Query::as_string() const {
	return "?";
}

std::string Select::as_string() const {
	std::ostringstream out;
	out << "SELECT";
	int i = 0;
	for(const auto& field : fields) {
		if(i++) {
			out << ", ";
		}
		if(field.second) {
			out << " " << field.second->as_string() << " AS " << field.first;
		}
	}
	for(const auto& field : aggregates) {
		if(i++) {
			out << ", ";
		}
		if(field.second) {
			out << " " << field.second->as_string() << " AS " << field.first;
		}
	}
	out << " FROM " << from;
	if(where) {
		out << " WHERE " << where->as_string();
	}
	if(group_by) {
		out << " " << group_by->as_string();
	}
	if(having) {
		out << " HAVING " << having->as_string();
	}
	if(order_by) {
		out << " " << order_by->as_string();
	}
	if(limit) {
		out << " " << limit->as_string();
	}
	out << ";";
	return out.str();
}

std::string Update::as_string() const {
	std::ostringstream out;
	out << "UPDATE " << table << " SET ";
	int i = 0;
	for(const auto& entry : set.field) {
		if(i++) {
			out << ", ";
		}
		out << entry.first << " = " << entry.second;
	}
	if(where) {
		out << " WHERE " << where->as_string();
	}
	out << ";";
	return out.str();
}

std::string Delete::as_string() const {
	std::ostringstream out;
	out << "DELETE FROM " << from;
	if(where) {
		out << " WHERE " << where->as_string();
	}
	out << ";";
	return out.str();
}


std::shared_ptr<const Field> field(const std::string& name) {
	auto out = Field::create();
	out->name = name;
	return out;
}

std::shared_ptr<const Unary> operator!(std::shared_ptr<const Expression> rhs) {
	auto out = Unary::create();
	out->type = op_type_e::NOT;
	out->X = rhs;
	return out;
}

std::shared_ptr<const Unary> is_null(std::shared_ptr<const Expression> rhs) {
	auto out = Unary::create();
	out->type = op_type_e::IS_NULL;
	out->X = rhs;
	return out;
}

std::shared_ptr<const Unary> not_null(std::shared_ptr<const Expression> rhs) {
	auto out = Unary::create();
	out->type = op_type_e::NOT_NULL;
	out->X = rhs;
	return out;
}

std::shared_ptr<const Comparison> operator&&(std::shared_ptr<const Expression> lhs, std::shared_ptr<const Expression> rhs) {
	auto out = Comparison::create();
	out->type = op_type_e::AND;
	out->L = lhs;
	out->R = rhs;
	return out;
}

std::shared_ptr<const Comparison> operator||(std::shared_ptr<const Expression> lhs, std::shared_ptr<const Expression> rhs) {
	auto out = Comparison::create();
	out->type = op_type_e::OR;
	out->L = lhs;
	out->R = rhs;
	return out;
}

std::shared_ptr<const Comparison> equal(std::shared_ptr<const Expression> lhs, std::shared_ptr<const Expression> rhs) {
	auto out = Comparison::create();
	out->type = op_type_e::EQUAL;
	out->L = lhs;
	out->R = rhs;
	return out;
}

std::shared_ptr<const Comparison> not_equal(std::shared_ptr<const Expression> lhs, std::shared_ptr<const Expression> rhs) {
	auto out = Comparison::create();
	out->type = op_type_e::NOT_EQUAL;
	out->L = lhs;
	out->R = rhs;
	return out;
}

std::shared_ptr<const Comparison> less(std::shared_ptr<const Expression> lhs, std::shared_ptr<const Expression> rhs) {
	auto out = Comparison::create();
	out->type = op_type_e::LESS;
	out->L = lhs;
	out->R = rhs;
	return out;
}

std::shared_ptr<const Comparison> less_equal(std::shared_ptr<const Expression> lhs, std::shared_ptr<const Expression> rhs) {
	auto out = Comparison::create();
	out->type = op_type_e::LESS_EQUAL;
	out->L = lhs;
	out->R = rhs;
	return out;
}

std::shared_ptr<const Comparison> greater(std::shared_ptr<const Expression> lhs, std::shared_ptr<const Expression> rhs) {
	auto out = Comparison::create();
	out->type = op_type_e::GREATER;
	out->L = lhs;
	out->R = rhs;
	return out;
}

std::shared_ptr<const Comparison> greater_equal(std::shared_ptr<const Expression> lhs, std::shared_ptr<const Expression> rhs) {
	auto out = Comparison::create();
	out->type = op_type_e::GREATER_EQUAL;
	out->L = lhs;
	out->R = rhs;
	return out;
}

std::shared_ptr<const Min> min(std::shared_ptr<const Expression> rhs) {
	auto out = Min::create();
	out->A = rhs;
	return out;
}

std::shared_ptr<const Max> max(std::shared_ptr<const Expression> rhs) {
	auto out = Max::create();
	out->A = rhs;
	return out;
}

std::shared_ptr<const Sum> sum(std::shared_ptr<const Expression> rhs) {
	auto out = Sum::create();
	out->A = rhs;
	return out;
}

std::shared_ptr<const Average> avg(std::shared_ptr<const Expression> rhs) {
	auto out = Average::create();
	out->A = rhs;
	return out;
}

std::shared_ptr<const Count> count() {
	return Count::create();
}

std::shared_ptr<const GroupBy> group_by(const std::string& field) {
	auto out = GroupBy::create();
	out->field = field;
	return out;
}

std::shared_ptr<const OrderBy> order_by(const std::string& field, const int32_t& mode) {
	auto out = OrderBy::create();
	out->field = field;
	out->mode = mode;
	return out;
}

std::shared_ptr<const Limit> limit(const int64_t& num_rows, const int64_t& offset) {
	auto out = Limit::create();
	out->num_rows = num_rows;
	out->offset = offset;
	return out;
}

std::shared_ptr<Select> select(	const std::string& from,
								const std::vector<std::string>& fields,
								std::shared_ptr<const Expression> where,
								std::shared_ptr<const GroupBy> group_by,
								std::shared_ptr<const Expression> having,
								std::shared_ptr<const OrderBy> order_by,
								std::shared_ptr<const Limit> limit)
{
	auto out = Select::create();
	out->from = from;
	for(const auto& name : fields) {
		out->fields[name] = field(name);
	}
	out->where = where;
	out->group_by = group_by;
	out->having = having;
	out->order_by = order_by;
	out->limit = limit;
	return out;
}

std::shared_ptr<Update> update(	const std::string& table,
								const Object& set,
								std::shared_ptr<const Expression> where)
{
	auto out = Update::create();
	out->table = table;
	out->set = set;
	out->where = where;
	return out;
}

std::shared_ptr<Delete> delete_from(const std::string& from,
									std::shared_ptr<const Expression> where)
{
	auto out = Delete::create();
	out->from = from;
	out->where = where;
	return out;
}

	
} // query
} // vnx
