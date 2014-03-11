/*!
 * @file
 * Contains unit tests for `boost::mpl11::cast` and `boost::mpl11::cast_to`.
 */

#include <boost/mpl11/core.hpp>

#include <boost/mpl11/detail/std_is_same.hpp>
#include <boost/mpl11/functional.hpp>


using namespace boost::mpl11;
using detail::std_is_same;

struct X;
struct x {
    using type = x;
    using mpl_datatype = X;
};

struct Y;
struct y {
    using type = y;
    using mpl_datatype = Y;
};

namespace boost { namespace mpl11 {
    template <>
    struct cast<X, Y> {
        using type = cast;
        template <typename>
        using apply = y;
    };
}}

static_assert(std_is_same<
    cast<X, X>::type::apply<x>::type,
    x::type
>::value, "");

static_assert(std_is_same<
    cast<X, Y>::type::apply<x>::type,
    y::type
>::value, "");

static_assert(std_is_same<
    cast_to<X>::type::apply<x>::type,
    x::type
>::value, "");

static_assert(std_is_same<
    cast_to<Y>::type::apply<x>::type,
    y::type
>::value, "");


int main() { }
