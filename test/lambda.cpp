/**
 * This file defines unit tests for the lambda metafunction.
 */

#include <duck/lambda.hpp>

#include <duck/pack.hpp>
#include <duck/placeholders.hpp>

#include <type_traits>


template <int i>
using int_ = std::integral_constant<int, i>;

template <typename X, typename Y>
struct add : int_<X::value + Y::value> { };

// lambda with nested placeholder expressions.
using triple = duck::lambda<add<
                                add<duck::_1, duck::_1>,
                                duck::_1
                            >
               >::type;
static_assert(triple::apply<int_<4>>::value == 12, "");

// lambda with an non lambda expression.
using expression_without_placeholders = add<int_<1>, add<int_<2>, int_<3>>>;
static_assert(std::is_same<
                duck::lambda<expression_without_placeholders>::type,
                expression_without_placeholders
              >::value, "");

// lambda with many mixed placeholders.
using reversed = duck::lambda<duck::pack<duck::_3, duck::_2, duck::_1>>::type;
static_assert(std::is_same<
                reversed::apply<int, float, char>::type,
                duck::pack<char, float, int>
              >::value, "");
