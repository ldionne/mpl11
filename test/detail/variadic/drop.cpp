/*!
 * @file
 * Contains unit tests for `boost::mpl11::detail::variadic::drop`.
 */

#include <boost/mpl11/detail/variadic/drop.hpp>

#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/detail/variadic/pack.hpp>


using namespace boost::mpl11;
using namespace detail::variadic;
using detail::is_same;

template <int> struct type;
template <int ...i> using pack_c = pack<type<i>...>;

static_assert(is_same<
    drop<pack_c<>, 0>::type, pack_c<>
>::value, "");

static_assert(is_same<
    drop<pack_c<0>, 0>::type, pack_c<0>
>::value, "");
static_assert(is_same<
    drop<pack_c<0>, 1>::type, pack_c<>
>::value, "");

static_assert(is_same<
    drop<pack_c<0, 1>, 0>::type, pack_c<0, 1>
>::value, "");
static_assert(is_same<
    drop<pack_c<0, 1>, 1>::type, pack_c<1>
>::value, "");
static_assert(is_same<
    drop<pack_c<0, 1>, 2>::type, pack_c<>
>::value, "");

static_assert(is_same<
    drop<pack_c<0, 1, 2>, 0>::type, pack_c<0, 1, 2>
>::value, "");
static_assert(is_same<
    drop<pack_c<0, 1, 2>, 1>::type, pack_c<1, 2>
>::value, "");
static_assert(is_same<
    drop<pack_c<0, 1, 2>, 2>::type, pack_c<2>
>::value, "");
static_assert(is_same<
    drop<pack_c<0, 1, 2>, 3>::type, pack_c<>
>::value, "");


int main() { }
