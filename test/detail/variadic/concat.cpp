/*!
 * @file
 * Contains unit tests for `boost::mpl11::detail::variadic::concat`.
 */

#include <boost/mpl11/detail/variadic/concat.hpp>

#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/detail/variadic/pack.hpp>


using namespace boost::mpl11;
using namespace detail::variadic;
using detail::is_same;

template <int> struct type;
template <int ...i> using pack_c = pack<type<i>...>;

// 2 packs
static_assert(is_same<
    concat<pack_c<>, pack_c<>>::type,
    pack_c<>
>::value, "");
static_assert(is_same<
    concat<pack_c<>, pack_c<0>>::type,
    pack_c<0>
>::value, "");
static_assert(is_same<
    concat<pack_c<>, pack_c<0, 1>>::type,
    pack_c<0, 1>
>::value, "");
static_assert(is_same<
    concat<pack_c<>, pack_c<0, 1, 2>>::type,
    pack_c<0, 1, 2>
>::value, "");

static_assert(is_same<
    concat<pack_c<0>, pack_c<>>::type,
    pack_c<0>
>::value, "");
static_assert(is_same<
    concat<pack_c<0>, pack_c<1>>::type,
    pack_c<0, 1>
>::value, "");
static_assert(is_same<
    concat<pack_c<0>, pack_c<1, 2>>::type,
    pack_c<0, 1, 2>
>::value, "");
static_assert(is_same<
    concat<pack_c<0>, pack_c<1, 2, 3>>::type,
    pack_c<0, 1, 2, 3>
>::value, "");

static_assert(is_same<
    concat<pack_c<0, 1>, pack_c<>>::type,
    pack_c<0, 1>
>::value, "");
static_assert(is_same<
    concat<pack_c<0, 1>, pack_c<2>>::type,
    pack_c<0, 1, 2>
>::value, "");
static_assert(is_same<
    concat<pack_c<0, 1>, pack_c<2, 3>>::type,
    pack_c<0, 1, 2, 3>
>::value, "");
static_assert(is_same<
    concat<pack_c<0, 1>, pack_c<2, 3, 4>>::type,
    pack_c<0, 1, 2, 3, 4>
>::value, "");


// 3+ packs
static_assert(is_same<
    concat<pack_c<0>, pack_c<1>, pack_c<2>>::type,
    pack_c<0, 1, 2>
>::value, "");

static_assert(is_same<
    concat<pack_c<>, pack_c<>, pack_c<>>::type,
    pack_c<>
>::value, "");

static_assert(is_same<
    concat<pack_c<0>, pack_c<1, 2>, pack_c<3>, pack_c<4, 5, 6, 7>>::type,
    pack_c<0, 1, 2, 3, 4, 5, 6, 7>
>::value, "");

static_assert(is_same<
    concat<pack_c<0>, pack_c<1, 2>, pack_c<>, pack_c<3, 4, 5>>::type,
    pack_c<0, 1, 2, 3, 4, 5>
>::value, "");


int main() { }
