/*!
 * @file
 * This file contains unit tests for `boost::mpl11::arg`.
 */

#include <boost/mpl11/functional/arg.hpp>
#include <boost/mpl11/functional/apply.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/is_same.hpp>


using namespace boost::mpl11;

static_assert(is_same<
    apply<identity<_1>, int>::type,
    identity<int>::type,
    int
>::value, "");

static_assert(is_same<
    apply<identity<_1>, int, float>::type,
    identity<int>::type,
    int
>::value, "");

static_assert(is_same<
    apply<identity<_2>, int, float>::type,
    identity<float>::type,
    float
>::value, "");


int main() { }
