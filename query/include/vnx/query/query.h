/*
 * query.h
 *
 *  Created on: Feb 18, 2021
 *      Author: mad
 */

#ifndef INCLUDE_VNX_QUERY_QUERY_H_
#define INCLUDE_VNX_QUERY_QUERY_H_

#include <vnx/query/Field.hxx>
#include <vnx/query/Value.hxx>
#include <vnx/query/Unary.hxx>
#include <vnx/query/Comparison.hxx>
#include <vnx/query/Function.hxx>
#include <vnx/query/Aggregate.hxx>
#include <vnx/query/Min.hxx>
#include <vnx/query/Max.hxx>
#include <vnx/query/Sum.hxx>
#include <vnx/query/Average.hxx>
#include <vnx/query/Count.hxx>
#include <vnx/query/Select.hxx>
#include <vnx/query/Update.hxx>
#include <vnx/query/Delete.hxx>


namespace vnx {
namespace query {

std::shared_ptr<const Field> field(const std::string& name);

template<typename T>
std::shared_ptr<const Value> value(const T& data) {
	auto out = Value::create();
	out->data = data;
	return out;
}

std::shared_ptr<const Unary> operator!(std::shared_ptr<const Expression> rhs);
std::shared_ptr<const Unary> is_null(std::shared_ptr<const Expression> rhs);
std::shared_ptr<const Unary> not_null(std::shared_ptr<const Expression> rhs);

std::shared_ptr<const Comparison> operator&&(std::shared_ptr<const Expression> lhs, std::shared_ptr<const Expression> rhs);
std::shared_ptr<const Comparison> operator||(std::shared_ptr<const Expression> lhs, std::shared_ptr<const Expression> rhs);
std::shared_ptr<const Comparison> equal(std::shared_ptr<const Expression> lhs, std::shared_ptr<const Expression> rhs);
std::shared_ptr<const Comparison> not_equal(std::shared_ptr<const Expression> lhs, std::shared_ptr<const Expression> rhs);
std::shared_ptr<const Comparison> less(std::shared_ptr<const Expression> lhs, std::shared_ptr<const Expression> rhs);
std::shared_ptr<const Comparison> less_equal(std::shared_ptr<const Expression> lhs, std::shared_ptr<const Expression> rhs);
std::shared_ptr<const Comparison> greater(std::shared_ptr<const Expression> lhs, std::shared_ptr<const Expression> rhs);
std::shared_ptr<const Comparison> greater_equal(std::shared_ptr<const Expression> lhs, std::shared_ptr<const Expression> rhs);

std::shared_ptr<const Min> min(std::shared_ptr<const Expression> rhs);
std::shared_ptr<const Max> max(std::shared_ptr<const Expression> rhs);
std::shared_ptr<const Sum> sum(std::shared_ptr<const Expression> rhs);
std::shared_ptr<const Average> avg(std::shared_ptr<const Expression> rhs);
std::shared_ptr<const Count> count();

std::shared_ptr<const GroupBy> group_by(const std::string& field);
std::shared_ptr<const OrderBy> order_by(const std::string& field, const int32_t& mode);
std::shared_ptr<const Limit> limit(const int64_t& num_rows, const int64_t& offset = 0);

std::shared_ptr<Select> select(	const std::string& from,
								const std::vector<std::string>& fields = {},
								std::shared_ptr<const Expression> where = nullptr,
								std::shared_ptr<const GroupBy> group_by = nullptr,
								std::shared_ptr<const Expression> having = nullptr,
								std::shared_ptr<const OrderBy> order_by = nullptr,
								std::shared_ptr<const Limit> limit = nullptr);

std::shared_ptr<Update> update(	const std::string& table,
								const Object& set = Object(),
								std::shared_ptr<const Expression> where = nullptr);

std::shared_ptr<Delete> delete_from(const std::string& from,
									std::shared_ptr<const Expression> where = nullptr);


} // query
} // vnx

#endif /* INCLUDE_VNX_QUERY_QUERY_H_ */
