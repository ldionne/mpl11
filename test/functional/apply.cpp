/*!
 * @file
 * Contains unit tests for `boost::mpl11::apply`.
 */

#include <boost/mpl11/functional.hpp>

#include <boost/mpl11/core.hpp>
#include <boost/mpl11/detail/std_is_same.hpp>


using boost::mpl11::detail::std_is_same;

// Make our life easier below.
template <typename F, typename ...Args>
using apply = boost::mpl11::apply<boost::mpl11::box<F>, Args...>;


// We leave those undefined voluntarily. They should not be evaluated.
struct x; struct y;

struct variadic {
    template <typename ...>
    struct apply { struct type; };
};

static_assert(std_is_same<
    apply<variadic>::type,
    variadic::apply<>::type
>::value, "");

static_assert(std_is_same<
    apply<variadic, x>::type,
    variadic::apply<x>::type
>::value, "");

static_assert(std_is_same<
    apply<variadic, x, y>::type,
    variadic::apply<x, y>::type
>::value, "");



struct unary {
    template <typename>
    struct apply { struct type; };
};

static_assert(std_is_same<
    apply<unary, x>::type,
    unary::apply<x>::type
>::value, "");



struct unary_with_default {
    template <typename = struct default_parameter>
    struct apply { struct type; };
};

static_assert(std_is_same<
    apply<unary_with_default>::type,
    unary_with_default::apply<struct default_parameter>::type
>::value, "");

static_assert(std_is_same<
    apply<unary_with_default, x>::type,
    unary_with_default::apply<x>::type
>::value, "");



struct binary {
    template <typename, typename>
    struct apply { struct type; };
};

static_assert(std_is_same<
    apply<binary, x, y>::type,
    binary::apply<x, y>::type
>::value, "");


int main() { }
