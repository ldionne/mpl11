/*!
 * @file
 * Contains unit tests for `boost::mpl11::detail::vector_slice`.
 */

#include <boost/mpl11/detail/vector_slice.hpp>

#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/fwd/vector.hpp>


using namespace boost::mpl11;
using detail::vector_slice;
using detail::is_same;

template <int> struct type;
template <int ...i> using vector_t = vector<type<i>...>;

static_assert(is_same<
    vector_slice<vector_t<>, 0, 0>::type, vector_t<>
>::value, "");
static_assert(is_same<
    vector_slice<vector_t<0>, 0, 0>::type, vector_t<>
>::value, "");
static_assert(is_same<
    vector_slice<vector_t<0, 1>, 0, 0>::type, vector_t<>
>::value, "");
static_assert(is_same<
    vector_slice<vector_t<0, 1, 2>, 0, 0>::type, vector_t<>
>::value, "");

static_assert(is_same<
    vector_slice<vector_t<0>, 0, 1>::type, vector_t<0>
>::value, "");
static_assert(is_same<
    vector_slice<vector_t<0, 1>, 0, 1>::type, vector_t<0>
>::value, "");
static_assert(is_same<
    vector_slice<vector_t<0, 1, 2>, 0, 1>::type, vector_t<0>
>::value, "");

static_assert(is_same<
    vector_slice<vector_t<0>, 1, 1>::type, vector_t<>
>::value, "");
static_assert(is_same<
    vector_slice<vector_t<0, 1>, 1, 1>::type, vector_t<>
>::value, "");
static_assert(is_same<
    vector_slice<vector_t<0, 1, 2>, 1, 1>::type, vector_t<>
>::value, "");

static_assert(is_same<
    vector_slice<vector_t<0, 1>, 0, 2>::type, vector_t<0, 1>
>::value, "");
static_assert(is_same<
    vector_slice<vector_t<0, 1, 2>, 0, 2>::type, vector_t<0, 1>
>::value, "");
static_assert(is_same<
    vector_slice<vector_t<0, 1, 2, 3>, 0, 2>::type, vector_t<0, 1>
>::value, "");

static_assert(is_same<
    vector_slice<vector_t<0, 1>, 1, 2>::type, vector_t<1>
>::value, "");
static_assert(is_same<
    vector_slice<vector_t<0, 1, 2>, 1, 2>::type, vector_t<1>
>::value, "");
static_assert(is_same<
    vector_slice<vector_t<0, 1, 2, 3>, 1, 2>::type, vector_t<1>
>::value, "");

static_assert(is_same<
    vector_slice<vector_t<0, 1, 2, 3, 4, 5>, 2, 6>::type,
    vector_t<2, 3, 4, 5>
>::value, "");
static_assert(is_same<
    vector_slice<vector_t<0, 1, 2, 3, 4, 5, 6>, 2, 6>::type,
    vector_t<2, 3, 4, 5>
>::value, "");


int main() { }
