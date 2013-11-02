/*!
 * @file
 * Contains unit tests for `boost::mpl11::detail::variadic::at`.
 */

#include <boost/mpl11/detail/variadic/at.hpp>

#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/detail/variadic/pack.hpp>


using namespace boost::mpl11;
using namespace detail::variadic;
using detail::is_same;

template <int> struct t;
template <int ...i> using pack_c = pack<t<i>...>;

static_assert(is_same<
    at<pack_c<0>, 0>::type, t<0>
>::value, "");

static_assert(is_same<
    at<pack_c<0, 1>, 0>::type, t<0>
>::value, "");
static_assert(is_same<
    at<pack_c<0, 1>, 1>::type, t<1>
>::value, "");

static_assert(is_same<
    at<pack_c<0, 1, 2>, 0>::type, t<0>
>::value, "");
static_assert(is_same<
    at<pack_c<0, 1, 2>, 1>::type, t<1>
>::value, "");
static_assert(is_same<
    at<pack_c<0, 1, 2>, 2>::type, t<2>
>::value, "");

static_assert(is_same<
    at<pack_c<0, 1, 2, 3>, 0>::type, t<0>
>::value, "");
static_assert(is_same<
    at<pack_c<0, 1, 2, 3>, 1>::type, t<1>
>::value, "");
static_assert(is_same<
    at<pack_c<0, 1, 2, 3>, 2>::type, t<2>
>::value, "");
static_assert(is_same<
    at<pack_c<0, 1, 2, 3>, 3>::type, t<3>
>::value, "");


int main() { }
