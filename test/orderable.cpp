/*!
 * @file
 * Contains unit tests for `boost::mpl11::Orderable`.
 */

#include <boost/mpl11/orderable.hpp>

#include <boost/mpl11/greater.hpp>
#include <boost/mpl11/greater_equal.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/less.hpp>
#include <boost/mpl11/less_equal.hpp>


using namespace boost::mpl11;

template <int i>
struct x {
    static constexpr auto value = i;

    struct mpl_class : Orderable {
        template <typename X, typename Y>
        struct less_impl
            : bool_<X::value < Y::value>
        { };
    };
};

// less
static_assert(!less<x<0>, x<0>>::value, "");
static_assert(less<x<0>,  x<1>>::value, "");
static_assert(less<x<0>,  x<2>>::value, "");

static_assert(!less<x<1>, x<0>>::value, "");
static_assert(!less<x<1>, x<1>>::value, "");
static_assert(less<x<1>,  x<2>>::value, "");

static_assert(!less<x<2>, x<0>>::value, "");
static_assert(!less<x<2>, x<1>>::value, "");
static_assert(!less<x<2>, x<2>>::value, "");


// less_equal
static_assert(less_equal<x<0>, x<0>>::value, "");
static_assert(less_equal<x<0>, x<1>>::value, "");
static_assert(less_equal<x<0>, x<2>>::value, "");

static_assert(!less_equal<x<1>, x<0>>::value, "");
static_assert(less_equal<x<1>,  x<1>>::value, "");
static_assert(less_equal<x<1>,  x<2>>::value, "");

static_assert(!less_equal<x<2>, x<0>>::value, "");
static_assert(!less_equal<x<2>, x<1>>::value, "");
static_assert(less_equal<x<2>,  x<2>>::value, "");


// greater
static_assert(!greater<x<0>, x<0>>::value, "");
static_assert(greater<x<1>,  x<0>>::value, "");
static_assert(greater<x<2>,  x<0>>::value, "");

static_assert(!greater<x<0>, x<1>>::value, "");
static_assert(!greater<x<1>, x<1>>::value, "");
static_assert(greater<x<2>,  x<1>>::value, "");

static_assert(!greater<x<0>, x<2>>::value, "");
static_assert(!greater<x<1>, x<2>>::value, "");
static_assert(!greater<x<2>, x<2>>::value, "");


// greater_equal
static_assert(greater_equal<x<0>,  x<0>>::value, "");
static_assert(greater_equal<x<1>,  x<0>>::value, "");
static_assert(greater_equal<x<2>,  x<0>>::value, "");

static_assert(!greater_equal<x<0>, x<1>>::value, "");
static_assert(greater_equal<x<1>,  x<1>>::value, "");
static_assert(greater_equal<x<2>,  x<1>>::value, "");

static_assert(!greater_equal<x<0>, x<2>>::value, "");
static_assert(!greater_equal<x<1>, x<2>>::value, "");
static_assert(greater_equal<x<2>,  x<2>>::value, "");


int main() { }
