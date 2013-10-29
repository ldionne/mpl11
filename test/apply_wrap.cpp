/*!
 * @file
 * Contains unit tests for `boost::mpl11::apply_wrap`.
 */

#include <boost/mpl11/apply_wrap.hpp>

#include <boost/mpl11/detail/is_same.hpp>


using namespace boost::mpl11;
using detail::is_same;

struct x; struct y;

struct variadic {
    template <typename ...>
    struct apply { struct type; };
};

static_assert(is_same<
    apply_wrap<variadic>::type,
    variadic::apply<>::type
>::value, "");

static_assert(is_same<
    apply_wrap<variadic, x>::type,
    variadic::apply<x>::type
>::value, "");

static_assert(is_same<
    apply_wrap<variadic, x, y>::type,
    variadic::apply<x, y>::type
>::value, "");



struct non_template {
    struct apply { struct type; };
};

static_assert(is_same<
    apply_wrap<non_template>::type,
    non_template::apply::type
>::value, "");



struct unary {
    template <typename>
    struct apply { struct type; };
};

static_assert(is_same<
    apply_wrap<unary, x>::type,
    unary::apply<x>::type
>::value, "");



struct unary_with_default {
    template <typename = struct default_parameter>
    struct apply { struct type; };
};

static_assert(is_same<
    apply_wrap<unary_with_default>::type,
    unary_with_default::apply<struct default_parameter>::type
>::value, "");

static_assert(is_same<
    apply_wrap<unary_with_default, x>::type,
    unary_with_default::apply<x>::type
>::value, "");



struct binary {
    template <typename, typename>
    struct apply { struct type; };
};

static_assert(is_same<
    apply_wrap<binary, x, y>::type,
    binary::apply<x, y>::type
>::value, "");


int main() { }
