/**
 * This file defines unit tests for the lambda metafunction.
 */

#include <mpl11/lambda.hpp>
#include <mpl11/apply.hpp>
#include <mpl11/bind.hpp>
#include <mpl11/int.hpp>
#include <mpl11/pack.hpp>
#include <mpl11/placeholders.hpp>
#include <mpl11/quote.hpp>

#include <type_traits>


using namespace mpl11;

template <typename X, typename Y>
struct add : int_<X::value + Y::value> { };

// lambda with nested placeholder expressions.
using triple = lambda<add<add<_1, _1>, _1>>::type;
static_assert(triple::apply<int_<4>>::value == 12, "");

// lambda with a non lambda expression.
using expression_without_placeholders = add<int_<1>, add<int_<2>, int_<3>>>;
static_assert(std::is_same<
                lambda<expression_without_placeholders>::type,
                expression_without_placeholders
              >::value, "");

// lambda with many mixed placeholders.
using reversed = lambda<pack<_3, _2, _1>>::type;
static_assert(std::is_same<
                reversed::apply<int, float, char>::type,
                pack<char, float, int>
              >::value, "");

// lambda with the special _all placeholder.
static_assert(std::is_same<
                apply<
                    lambda<pack<_all>>::type,
                    int, float, char
                >::type,
                pack<int, float, char>
              >::value, "");

// lambda with bind expressions.
using bound_add = bind<quote<add>, _1, _2>;
static_assert(std::is_same<
                lambda<bound_add>::type,
                bound_add
              >::value, "");

static_assert(std::is_same<
                apply<bound_add, int_<1>, int_<2>>::type,
                int_<3>
              >::value, "");

static_assert(std::is_same<
                apply<lambda<bound_add>::type, int_<1>, int_<2>>::type,
                int_<3>
              >::value, "");
