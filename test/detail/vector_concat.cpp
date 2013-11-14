/*!
 * @file
 * Contains unit tests for `boost::mpl11::detail::vector_concat`.
 */

#include <boost/mpl11/detail/vector_concat.hpp>

#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/fwd/vector.hpp>


using namespace boost::mpl11;
using detail::vector_concat;
using detail::is_same;

template <int> struct type;
template <int ...i> using vector_t = vector<type<i>...>;

// 2 packs
static_assert(is_same<
    vector_concat<vector_t<>, vector_t<>>::type,
    vector_t<>
>::value, "");
static_assert(is_same<
    vector_concat<vector_t<>, vector_t<0>>::type,
    vector_t<0>
>::value, "");
static_assert(is_same<
    vector_concat<vector_t<>, vector_t<0, 1>>::type,
    vector_t<0, 1>
>::value, "");
static_assert(is_same<
    vector_concat<vector_t<>, vector_t<0, 1, 2>>::type,
    vector_t<0, 1, 2>
>::value, "");

static_assert(is_same<
    vector_concat<vector_t<0>, vector_t<>>::type,
    vector_t<0>
>::value, "");
static_assert(is_same<
    vector_concat<vector_t<0>, vector_t<1>>::type,
    vector_t<0, 1>
>::value, "");
static_assert(is_same<
    vector_concat<vector_t<0>, vector_t<1, 2>>::type,
    vector_t<0, 1, 2>
>::value, "");
static_assert(is_same<
    vector_concat<vector_t<0>, vector_t<1, 2, 3>>::type,
    vector_t<0, 1, 2, 3>
>::value, "");

static_assert(is_same<
    vector_concat<vector_t<0, 1>, vector_t<>>::type,
    vector_t<0, 1>
>::value, "");
static_assert(is_same<
    vector_concat<vector_t<0, 1>, vector_t<2>>::type,
    vector_t<0, 1, 2>
>::value, "");
static_assert(is_same<
    vector_concat<vector_t<0, 1>, vector_t<2, 3>>::type,
    vector_t<0, 1, 2, 3>
>::value, "");
static_assert(is_same<
    vector_concat<vector_t<0, 1>, vector_t<2, 3, 4>>::type,
    vector_t<0, 1, 2, 3, 4>
>::value, "");


// 3+ packs
static_assert(is_same<
    vector_concat<vector_t<0>, vector_t<1>, vector_t<2>>::type,
    vector_t<0, 1, 2>
>::value, "");

static_assert(is_same<
    vector_concat<vector_t<>, vector_t<>, vector_t<>>::type,
    vector_t<>
>::value, "");

static_assert(is_same<
    vector_concat<vector_t<0>, vector_t<1, 2>, vector_t<3>, vector_t<4, 5, 6, 7>>::type,
    vector_t<0, 1, 2, 3, 4, 5, 6, 7>
>::value, "");

static_assert(is_same<
    vector_concat<vector_t<0>, vector_t<1, 2>, vector_t<>, vector_t<3, 4, 5>>::type,
    vector_t<0, 1, 2, 3, 4, 5>
>::value, "");


int main() { }
