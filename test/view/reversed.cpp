/*!
 * @file
 * Contains unit tests for `boost::mpl11::reversed_view`.
 */

#include <boost/mpl11/reversed_view.hpp>

#include <boost/mpl11/equal_to.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/vector.hpp>


using namespace boost::mpl11;

template <int ...Values>
using vector_c = vector<int_<Values>...>;

static_assert(equal_to<
    reversed_view<vector_c<>>,
    vector_c<>
>::type::value, "");

static_assert(equal_to<
    reversed_view<vector_c<0>>,
    vector_c<0>
>::type::value, "");

static_assert(equal_to<
    reversed_view<vector_c<0, 1>>,
    vector_c<1, 0>
>::type::value, "");

static_assert(equal_to<
    reversed_view<vector_c<0, 1, 2, 3>>,
    vector_c<3, 2, 1, 0>
>::type::value, "");


int main() { }
