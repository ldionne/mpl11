/*!
 * @file
 * Contains unit tests for `boost::mpl11::view::reversed`.
 */

#include <boost/mpl11/view/reversed.hpp>

#include <boost/mpl11/container/vector.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/operator/equal_to.hpp>


using namespace boost::mpl11;
using view::reversed;

template <int ...Values>
using vector_c = container::vector<int_<Values>...>;

static_assert(equal_to<
    reversed<vector_c<>>,
    vector_c<>
>::type::value, "");

static_assert(equal_to<
    reversed<vector_c<0>>,
    vector_c<0>
>::type::value, "");

static_assert(equal_to<
    reversed<vector_c<0, 1>>,
    vector_c<1, 0>
>::type::value, "");

static_assert(equal_to<
    reversed<vector_c<0, 1, 2, 3>>,
    vector_c<3, 2, 1, 0>
>::type::value, "");


int main() { }
