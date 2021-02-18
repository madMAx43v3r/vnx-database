
#include <vnx/query/package.h>

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

Variant Equal::execute(const Object& object) const {
	if(!A || !B) {
		throw std::logic_error("execute(): !A || !B");
	}
	return A->execute(object) == B->execute(object);
}

Variant NotEqual::execute(const Object& object) const {
	if(!A || !B) {
		throw std::logic_error("execute(): !A || !B");
	}
	return A->execute(object) != B->execute(object);
}

Variant Less::execute(const Object& object) const {
	if(!A || !B) {
		throw std::logic_error("execute(): !A || !B");
	}
	return A->execute(object) < B->execute(object);
}

Variant LessEqual::execute(const Object& object) const {
	if(!A || !B) {
		throw std::logic_error("execute(): !A || !B");
	}
	return A->execute(object) <= B->execute(object);
}

Variant Greater::execute(const Object& object) const {
	if(!A || !B) {
		throw std::logic_error("execute(): !A || !B");
	}
	return A->execute(object) > B->execute(object);
}

Variant GreaterEqual::execute(const Object& object) const {
	if(!A || !B) {
		throw std::logic_error("execute(): !A || !B");
	}
	return A->execute(object) >= B->execute(object);
}

Variant And::execute(const Object& object) const {
	if(!A || !B) {
		throw std::logic_error("execute(): !A || !B");
	}
	return bool(A->execute(object)) && bool(B->execute(object));
}

Variant Or::execute(const Object& object) const {
	if(!A || !B) {
		throw std::logic_error("execute(): !A || !B");
	}
	return bool(A->execute(object)) || bool(B->execute(object));
}

Variant Not::execute(const Object& object) const {
	if(!A) {
		throw std::logic_error("execute(): !A");
	}
	const Variant result = A->execute(object);
	return !bool(A->execute(object));
}

Variant IsNull::execute(const Object& object) const {
	if(!A) {
		throw std::logic_error("execute(): !A");
	}
	const Variant result = A->execute(object);
	return result.empty() || result.is_null();
}

Variant NotNull::execute(const Object& object) const {
	if(!A) {
		throw std::logic_error("execute(): !A");
	}
	const Variant result = A->execute(object);
	return !(result.empty() || result.is_null());
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
	return result;
}

Variant Average::get_result() const {
	return count > 0 ? float64_t(sum) / float64_t(count) : float64_t(0);
}

Variant Count::get_result() const {
	return result;
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

std::string Not::as_string() const {
	return "NOT " + (A ? A->as_string() : "?");
}

std::string IsNull::as_string() const {
	return (A ? A->as_string() : "?") + " IS NULL";
}

std::string NotNull::as_string() const {
	return (A ? A->as_string() : "?") + " IS NOT NULL";
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

std::string And::as_string() const {
	return "(" + (A ? A->as_string() : "?") + " AND " + (B ? B->as_string() : "?") + ")";
}

std::string Or::as_string() const {
	return "(" + (A ? A->as_string() : "?") + " OR " + (B ? B->as_string() : "?") + ")";
}

std::string Equal::as_string() const {
	return (A ? A->as_string() : "?") + " = " + (B ? B->as_string() : "?");
}

std::string NotEqual::as_string() const {
	return (A ? A->as_string() : "?") + " <> " + (B ? B->as_string() : "?");
}

std::string Less::as_string() const {
	return (A ? A->as_string() : "?") + " < " + (B ? B->as_string() : "?");
}

std::string LessEqual::as_string() const {
	return (A ? A->as_string() : "?") + " <= " + (B ? B->as_string() : "?");
}

std::string Greater::as_string() const {
	return (A ? A->as_string() : "?") + " > " + (B ? B->as_string() : "?");
}

std::string GreaterEqual::as_string() const {
	return (A ? A->as_string() : "?") + " >= " + (B ? B->as_string() : "?");
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


	
} // query
} // vnx
