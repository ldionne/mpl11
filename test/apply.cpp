/*!
 * @file
 * Contains unit tests for `boost::mpl11::apply`.
 */

#include <boost/mpl11/apply.hpp>

#include <boost/mpl11/detail/is_same.hpp>


using namespace boost::mpl11;
using detail::is_same;

struct x; struct y;

struct variadic {
    template <typename ...>
    struct apply { struct type; };
};

static_assert(is_same<
    apply<variadic>::type,
    variadic::apply<>::type
>::value, "");

static_assert(is_same<
    apply<variadic, x>::type,
    variadic::apply<x>::type
>::value, "");

static_assert(is_same<
    apply<variadic, x, y>::type,
    variadic::apply<x, y>::type
>::value, "");



struct non_template {
    struct apply { struct type; };
};

static_assert(is_same<
    apply<non_template>::type,
    non_template::apply::type
>::value, "");



struct unary {
    template <typename>
    struct apply { struct type; };
};

static_assert(is_same<
    apply<unary, x>::type,
    unary::apply<x>::type
>::value, "");



struct unary_with_default {
    template <typename = struct default_parameter>
    struct apply { struct type; };
};

static_assert(is_same<
    apply<unary_with_default>::type,
    unary_with_default::apply<struct default_parameter>::type
>::value, "");

static_assert(is_same<
    apply<unary_with_default, x>::type,
    unary_with_default::apply<x>::type
>::value, "");



struct binary {
    template <typename, typename>
    struct apply { struct type; };
};

static_assert(is_same<
    apply<binary, x, y>::type,
    binary::apply<x, y>::type
>::value, "");


int main() { }
