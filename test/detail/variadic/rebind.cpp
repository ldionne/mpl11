/*!
 * @file
 * Contains unit tests for `boost::mpl11::detail::variadic::rebind`.
 */

#include <boost/mpl11/detail/variadic/rebind.hpp>

#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/detail/variadic/pack.hpp>


using namespace boost::mpl11;
using namespace detail::variadic;
using detail::is_same;

template <int> struct type;
template <int ...i> using pack_c = pack<type<i>...>;

template <typename ...> struct other;
template <int ...i> using other_c = other<type<i>...>;

static_assert(is_same<
    rebind<pack_c<>, other>::type, other_c<>
>::value, "");
static_assert(is_same<
    rebind<pack_c<0>, other>::type, other_c<0>
>::value, "");
static_assert(is_same<
    rebind<pack_c<0, 1>, other>::type, other_c<0, 1>
>::value, "");
static_assert(is_same<
    rebind<pack_c<0, 1, 2>, other>::type, other_c<0, 1, 2>
>::value, "");
static_assert(is_same<
    rebind<pack_c<0, 1, 2, 3>, other>::type, other_c<0, 1, 2, 3>
>::value, "");


int main() { }
