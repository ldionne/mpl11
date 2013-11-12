/*!
 * @file
 * Contains unit tests for `boost::mpl11::Comparable`.
 */

#include <boost/mpl11/comparable.hpp>

#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/equal.hpp>
#include <boost/mpl11/not_equal.hpp>


using namespace boost::mpl11;

//! @todo Use a minimal Comparable here.
template <int>
struct x {
    struct mpl_class : Comparable {
        template <typename X, typename Y>
        struct equal_impl
            : detail::is_same<X, Y>
        { };
    };
};

// equal
static_assert(equal<x<0>, x<0>>::value, "");
static_assert(!equal<x<1>, x<0>>::value, "");
static_assert(!equal<x<0>, x<1>>::value, "");

// not_equal
static_assert(!not_equal<x<0>, x<0>>::value, "");
static_assert(not_equal<x<1>, x<0>>::value, "");
static_assert(not_equal<x<0>, x<1>>::value, "");


int main() { }
