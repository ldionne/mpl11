/*!
 * @file
 * This file contains unit tests for `boost::mpl11::always`.
 */

#include <boost/mpl11/always.hpp>

#include <boost/mpl11/apply_wrap.hpp>
#include <boost/mpl11/is_same.hpp>


using namespace boost::mpl11;

static_assert(is_same<
    apply_wrap<always<struct anything>>::type,
    struct anything
>::value, "");

static_assert(is_same<
    apply_wrap<always<struct anything>, struct a0>::type,
    struct anything
>::value, "");

static_assert(is_same<
    apply_wrap<always<struct anything>, struct a0, struct a1>::type,
    struct anything
>::value, "");


int main() { }
