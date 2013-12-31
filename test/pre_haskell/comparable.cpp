/*!
 * @file
 * Contains unit tests for `boost::mpl11::Comparable`.
 */

#include <boost/mpl11/comparable.hpp>

#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/not_equal.hpp>

#include "minimal_requirements.hpp"


using namespace boost::mpl11;

template <int i>
using x = test::wrapper<
    test::minimal_requirements<Comparable>,
    int_<i>
>;

// not_equal
static_assert(!not_equal<x<0>, x<0>>::value, "");
static_assert( not_equal<x<1>, x<0>>::value, "");
static_assert( not_equal<x<0>, x<1>>::value, "");


int main() { }
