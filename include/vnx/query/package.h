
#ifndef INCLUDE_VNX_QUERY_PACKAGE_H
#define INCLUDE_VNX_QUERY_PACKAGE_H

#include <vnx/query/And.hxx>
#include <vnx/query/Count.hxx>
#include <vnx/query/Equal.hxx>
#include <vnx/query/Field.hxx>
#include <vnx/query/Greater.hxx>
#include <vnx/query/GreaterEqual.hxx>
#include <vnx/query/Less.hxx>
#include <vnx/query/LessEqual.hxx>
#include <vnx/query/Max.hxx>
#include <vnx/query/Min.hxx>
#include <vnx/query/NotEqual.hxx>
#include <vnx/query/Or.hxx>
#include <vnx/query/Value.hxx>
#include <vnx/query/Sum.hxx>
#include <vnx/query/OrderBy.hxx>
#include <vnx/query/GroupBy.hxx>
#include <vnx/query/Limit.hxx>
#include <vnx/query/Select.hxx>
#include <vnx/query/Update.hxx>
#include <vnx/query/Delete.hxx>
#include <vnx/query/NotNull.hxx>
#include <vnx/query/IsNull.hxx>
#include <vnx/query/Not.hxx>
#include <vnx/query/Average.hxx>


namespace vnx {
namespace query {

inline std::shared_ptr<Field> field(const std::string& name) {
	auto query = Field::create();
	query->name = name;
	return query;
}

inline std::shared_ptr<Value> value(const Variant& value) {
	auto query = Value::create();
	query->data = value;
	return query;
}

inline std::shared_ptr<Equal> equal(std::shared_ptr<const Expression> A, std::shared_ptr<const Expression> B) {
	auto query = Equal::create();
	query->A = A;
	query->B = B;
	return query;
}

inline std::shared_ptr<NotEqual> not_equal(std::shared_ptr<const Expression> A, std::shared_ptr<const Expression> B) {
	auto query = NotEqual::create();
	query->A = A;
	query->B = B;
	return query;
}

inline std::shared_ptr<Less> less(std::shared_ptr<const Expression> A, std::shared_ptr<const Expression> B) {
	auto query = Less::create();
	query->A = A;
	query->B = B;
	return query;
}

inline std::shared_ptr<LessEqual> less_equal(std::shared_ptr<const Expression> A, std::shared_ptr<const Expression> B) {
	auto query = LessEqual::create();
	query->A = A;
	query->B = B;
	return query;
}

inline std::shared_ptr<Greater> greater(std::shared_ptr<const Expression> A, std::shared_ptr<const Expression> B) {
	auto query = Greater::create();
	query->A = A;
	query->B = B;
	return query;
}

inline std::shared_ptr<GreaterEqual> greater_equal(std::shared_ptr<const Expression> A, std::shared_ptr<const Expression> B) {
	auto query = GreaterEqual::create();
	query->A = A;
	query->B = B;
	return query;
}

inline std::shared_ptr<And> logical_and(std::shared_ptr<const Expression> A, std::shared_ptr<const Expression> B) {
	auto query = And::create();
	query->A = A;
	query->B = B;
	return query;
}

inline std::shared_ptr<Or> logical_or(std::shared_ptr<const Expression> A, std::shared_ptr<const Expression> B) {
	auto query = Or::create();
	query->A = A;
	query->B = B;
	return query;
}

inline std::shared_ptr<Not> logical_not(std::shared_ptr<const Expression> A) {
	auto query = Not::create();
	query->A = A;
	return query;
}

inline std::shared_ptr<IsNull> is_null(std::shared_ptr<const Expression> A) {
	auto query = IsNull::create();
	query->A = A;
	return query;
}

inline std::shared_ptr<NotNull> not_null(std::shared_ptr<const Expression> A) {
	auto query = NotNull::create();
	query->A = A;
	return query;
}

inline std::shared_ptr<Min> min(std::shared_ptr<const Expression> A) {
	auto query = Min::create();
	query->A = A;
	return query;
}

inline std::shared_ptr<Max> max(std::shared_ptr<const Expression> A) {
	auto query = Max::create();
	query->A = A;
	return query;
}

inline std::shared_ptr<Sum> sum(std::shared_ptr<const Expression> A) {
	auto query = Sum::create();
	query->A = A;
	return query;
}

inline std::shared_ptr<Average> avg(std::shared_ptr<const Expression> A) {
	auto query = Average::create();
	query->A = A;
	return query;
}

inline std::shared_ptr<Count> count() {
	return Count::create();
}

inline std::shared_ptr<OrderBy> order_by(const std::string& field, const int mode) {
	auto query = OrderBy::create();
	query->field = field;
	query->mode = mode;
	return query;
}

inline std::shared_ptr<GroupBy> group_by(const std::string& field) {
	auto query = GroupBy::create();
	query->field = field;
	return query;
}

inline std::shared_ptr<Limit> limit(const int64_t num_rows, const int64_t offset = 0) {
	auto query = Limit::create();
	query->num_rows = num_rows;
	query->offset = offset;
	return query;
}

inline Select select(	const std::string& from,
						std::shared_ptr<const Expression> where = 0,
						std::shared_ptr<const OrderBy> order_by = 0,
						std::shared_ptr<const Limit> limit = 0)
{
	Select query;
	query.from = from;
	query.where = where;
	query.order_by = order_by;
	query.limit = limit;
	return query;
}

inline Select select(	const std::string& from,
						std::shared_ptr<const Expression> where,
						std::shared_ptr<const GroupBy> group_by,
						std::shared_ptr<const OrderBy> order_by = 0,
						std::shared_ptr<const Limit> limit = 0)
{
	Select query;
	query.from = from;
	query.where = where;
	query.group_by = group_by;
	query.order_by = order_by;
	query.limit = limit;
	return query;
}

inline Select select(	const std::string& from,
						std::shared_ptr<const Expression> where,
						std::shared_ptr<const GroupBy> group_by,
						std::shared_ptr<const Expression> having,
						std::shared_ptr<const OrderBy> order_by = 0,
						std::shared_ptr<const Limit> limit = 0)
{
	Select query;
	query.from = from;
	query.where = where;
	query.group_by = group_by;
	query.having = having;
	query.order_by = order_by;
	query.limit = limit;
	return query;
}

inline Update update(	const std::string& table,
						const vnx::Object& set,
						std::shared_ptr<const Expression> where)
{
	Update query;
	query.table = table;
	query.set = set;
	query.where = where;
	return query;
}

inline Update update(	const std::string& table,
						const std::string& field,
						const vnx::Variant& value,
						std::shared_ptr<const Expression> where)
{
	Update query;
	query.table = table;
	Object set;
	set[field] = value;
	query.set = set;
	query.where = where;
	return query;
}

inline Delete delete_from(	const std::string& table,
							std::shared_ptr<const Expression> where)
{
	Delete query;
	query.from = table;
	query.where = where;
	return query;
}


} // query
} // vnx

#endif // INCLUDE_VNX_QUERY_PACKAGE_H
