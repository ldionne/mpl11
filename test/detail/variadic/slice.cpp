/*!
 * @file
 * Contains unit tests for `boost::mpl11::detail::variadic::slice`.
 */

#include <boost/mpl11/detail/variadic/slice.hpp>

#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/detail/variadic/pack.hpp>


using namespace boost::mpl11;
using namespace detail::variadic;
using detail::is_same;

template <int> struct type;
template <int ...i> using pack_c = pack<type<i>...>;

static_assert(is_same<
    slice<pack_c<>, 0, 0>::type, pack_c<>
>::value, "");
static_assert(is_same<
    slice<pack_c<0>, 0, 0>::type, pack_c<>
>::value, "");
static_assert(is_same<
    slice<pack_c<0, 1>, 0, 0>::type, pack_c<>
>::value, "");
static_assert(is_same<
    slice<pack_c<0, 1, 2>, 0, 0>::type, pack_c<>
>::value, "");

static_assert(is_same<
    slice<pack_c<0>, 0, 1>::type, pack_c<0>
>::value, "");
static_assert(is_same<
    slice<pack_c<0, 1>, 0, 1>::type, pack_c<0>
>::value, "");
static_assert(is_same<
    slice<pack_c<0, 1, 2>, 0, 1>::type, pack_c<0>
>::value, "");

static_assert(is_same<
    slice<pack_c<0>, 1, 1>::type, pack_c<>
>::value, "");
static_assert(is_same<
    slice<pack_c<0, 1>, 1, 1>::type, pack_c<>
>::value, "");
static_assert(is_same<
    slice<pack_c<0, 1, 2>, 1, 1>::type, pack_c<>
>::value, "");

static_assert(is_same<
    slice<pack_c<0, 1>, 0, 2>::type, pack_c<0, 1>
>::value, "");
static_assert(is_same<
    slice<pack_c<0, 1, 2>, 0, 2>::type, pack_c<0, 1>
>::value, "");
static_assert(is_same<
    slice<pack_c<0, 1, 2, 3>, 0, 2>::type, pack_c<0, 1>
>::value, "");

static_assert(is_same<
    slice<pack_c<0, 1>, 1, 2>::type, pack_c<1>
>::value, "");
static_assert(is_same<
    slice<pack_c<0, 1, 2>, 1, 2>::type, pack_c<1>
>::value, "");
static_assert(is_same<
    slice<pack_c<0, 1, 2, 3>, 1, 2>::type, pack_c<1>
>::value, "");

static_assert(is_same<
    slice<pack_c<0, 1, 2, 3, 4, 5>, 2, 6>::type,
    pack_c<2, 3, 4, 5>
>::value, "");
static_assert(is_same<
    slice<pack_c<0, 1, 2, 3, 4, 5, 6>, 2, 6>::type,
    pack_c<2, 3, 4, 5>
>::value, "");


int main() { }
