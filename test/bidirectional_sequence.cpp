/*!
 * @file
 * Contains unit tests for `boost::mpl11::BidirectionalSequence`.
 */

#include <boost/mpl11/bidirectional_sequence.hpp>

#include <boost/mpl11/back.hpp>
#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/vector.hpp>

#include "minimal_requirements.hpp"


using namespace boost::mpl11;
using detail::is_same;

template <int> struct x;
template <int ...i>
using sequence = test::wrapper<
    test::minimal_requirements<BidirectionalSequence>, vector<x<i>...>
>;

// back
static_assert(is_same<back<sequence<0>>::type, x<0>>::value, "");
static_assert(is_same<back<sequence<0, 1>>::type, x<1>>::value, "");
static_assert(is_same<back<sequence<0, 1, 2>>::type, x<2>>::value, "");


int main() { }
