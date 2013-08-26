/*!
 * @file
 * This file contains unit tests for `boost::mpl11::kwarg`.
 */

#include <boost/mpl11/functional/kwarg.hpp>
#include <boost/mpl11/functional/apply.hpp>
#include <boost/mpl11/functional/named_argument.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/is_same.hpp>


using namespace boost::mpl11;

static_assert(is_same<
    apply<
        identity<kwarg<struct tag>>,
        named_argument<struct tag, int>
    >::type,
    identity<int>::type,
    int
>::value, "");

static_assert(is_same<
    apply<
        identity<kwarg<struct float_tag>>,
        named_argument<struct int_tag, int>,
        named_argument<struct float_tag, float>
    >::type,
    identity<float>::type,
    float
>::value, "");


int main() { }
