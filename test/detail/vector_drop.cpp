/*!
 * @file
 * Contains unit tests for `boost::mpl11::detail::vector_drop`.
 */

#include <boost/mpl11/detail/vector_drop.hpp>

#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/fwd/vector.hpp>


using namespace boost::mpl11;
using detail::vector_drop;
using detail::is_same;

template <int> struct type;
template <int ...i> using vector_t = vector<type<i>...>;

static_assert(is_same<
    vector_drop<vector_t<>, 0>::type, vector_t<>
>::value, "");

static_assert(is_same<
    vector_drop<vector_t<0>, 0>::type, vector_t<0>
>::value, "");
static_assert(is_same<
    vector_drop<vector_t<0>, 1>::type, vector_t<>
>::value, "");

static_assert(is_same<
    vector_drop<vector_t<0, 1>, 0>::type, vector_t<0, 1>
>::value, "");
static_assert(is_same<
    vector_drop<vector_t<0, 1>, 1>::type, vector_t<1>
>::value, "");
static_assert(is_same<
    vector_drop<vector_t<0, 1>, 2>::type, vector_t<>
>::value, "");

static_assert(is_same<
    vector_drop<vector_t<0, 1, 2>, 0>::type, vector_t<0, 1, 2>
>::value, "");
static_assert(is_same<
    vector_drop<vector_t<0, 1, 2>, 1>::type, vector_t<1, 2>
>::value, "");
static_assert(is_same<
    vector_drop<vector_t<0, 1, 2>, 2>::type, vector_t<2>
>::value, "");
static_assert(is_same<
    vector_drop<vector_t<0, 1, 2>, 3>::type, vector_t<>
>::value, "");


int main() { }
