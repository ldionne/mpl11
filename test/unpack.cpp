/*!
 * @file
 * Contains unit tests for `boost::mpl11::unpack`.
 */

#include <boost/mpl11/unpack.hpp>

#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/vector.hpp>


using namespace boost::mpl11;
using detail::is_same;

struct f { template <typename ...> struct apply { struct type; }; };
template <int> struct x;

static_assert(is_same<
    unpack<vector<>, f>::type,
    f::apply<>::type
>::value, "");

static_assert(is_same<
    unpack<vector<x<0>>, f>::type,
    f::apply<x<0>>::type
>::value, "");

static_assert(is_same<
    unpack<vector<x<0>, x<1>>, f>::type,
    f::apply<x<0>, x<1>>::type
>::value, "");

static_assert(is_same<
    unpack<vector<x<0>, x<1>, x<2>>, f>::type,
    f::apply<x<0>, x<1>, x<2>>::type
>::value, "");

static_assert(is_same<
    unpack<vector<x<0>, x<1>, x<2>, x<3>>, f>::type,
    f::apply<x<0>, x<1>, x<2>, x<3>>::type
>::value, "");


int main() { }
