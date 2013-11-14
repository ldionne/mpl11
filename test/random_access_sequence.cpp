/*!
 * @file
 * Contains unit tests for `boost::mpl11::RandomAccessSequence`.
 */

#include <boost/mpl11/random_access_sequence.hpp>

#include <boost/mpl11/at.hpp>
#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/vector.hpp>

#include "minimal_requirements.hpp"


using namespace boost::mpl11;
using detail::is_same;

template <int> struct x;
template <int ...i>
using seq = test::wrapper<
    test::minimal_requirements<RandomAccessSequence>, vector<x<i>...>
>;

// at/at_c
static_assert(is_same<at_c<seq<0>, 0>::type, x<0>>::value, "");

static_assert(is_same<at_c<seq<0, 1>, 0>::type, x<0>>::value, "");
static_assert(is_same<at_c<seq<0, 1>, 1>::type, x<1>>::value, "");

static_assert(is_same<at_c<seq<0, 1, 2>, 0>::type, x<0>>::value, "");
static_assert(is_same<at_c<seq<0, 1, 2>, 1>::type, x<1>>::value, "");
static_assert(is_same<at_c<seq<0, 1, 2>, 2>::type, x<2>>::value, "");

static_assert(is_same<at_c<seq<0, 1, 2, 3>, 0>::type, x<0>>::value, "");
static_assert(is_same<at_c<seq<0, 1, 2, 3>, 1>::type, x<1>>::value, "");
static_assert(is_same<at_c<seq<0, 1, 2, 3>, 2>::type, x<2>>::value, "");
static_assert(is_same<at_c<seq<0, 1, 2, 3>, 3>::type, x<3>>::value, "");


int main() { }
