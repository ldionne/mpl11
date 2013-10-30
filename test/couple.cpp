/*!
 * @file
 * Contains unit tests for `boost::mpl11::Couple`.
 */

#include <boost/mpl11/couple.hpp>

#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/equal.hpp>
#include <boost/mpl11/first.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/less.hpp>
#include <boost/mpl11/second.hpp>


using namespace boost::mpl11;
using detail::is_same;

template <int i>
struct x {
    static constexpr auto value = i;

    struct mpl_class : Orderable, Comparable {
        template <typename Self, typename Other>
        struct equal_impl
            : bool_<Self::value == Other::value>
        { };

        template <typename Self, typename Other>
        struct less_impl
            : bool_<Self::value < Other::value>
        { };
    };
};

template <typename X, typename Y>
struct couple {
    using first = X;
    using second = Y;

    struct mpl_class : Couple {
        template <typename Self>
        struct first_impl { using type = typename Self::first; };
        template <typename Self>
        struct second_impl { using type = typename Self::second; };
    };
};

struct First; struct Second;

// first
static_assert(is_same<first<couple<First, Second>>::type, First>::value, "");


// second
static_assert(is_same<second<couple<First, Second>>::type, Second>::value, "");


// equal
static_assert( equal<couple<x<0>, x<0>>, couple<x<0>, x<0>>>::value, "");
static_assert(!equal<couple<x<1>, x<0>>, couple<x<0>, x<0>>>::value, "");
static_assert(!equal<couple<x<0>, x<1>>, couple<x<0>, x<0>>>::value, "");
static_assert(!equal<couple<x<0>, x<0>>, couple<x<1>, x<0>>>::value, "");
static_assert(!equal<couple<x<0>, x<0>>, couple<x<0>, x<1>>>::value, "");


// less
static_assert(!less<couple<x<0>, x<0>>, couple<x<0>, x<0>>>::value, "");
static_assert( less<couple<x<0>, x<0>>, couple<x<0>, x<1>>>::value, "");
static_assert( less<couple<x<0>, x<0>>, couple<x<1>, x<0>>>::value, "");
static_assert( less<couple<x<0>, x<0>>, couple<x<1>, x<1>>>::value, "");

static_assert(!less<couple<x<0>, x<1>>, couple<x<0>, x<0>>>::value, "");
static_assert(!less<couple<x<0>, x<1>>, couple<x<0>, x<1>>>::value, "");
static_assert( less<couple<x<0>, x<1>>, couple<x<1>, x<0>>>::value, "");
static_assert( less<couple<x<0>, x<1>>, couple<x<1>, x<1>>>::value, "");

static_assert(!less<couple<x<1>, x<0>>, couple<x<0>, x<0>>>::value, "");
static_assert(!less<couple<x<1>, x<0>>, couple<x<0>, x<1>>>::value, "");
static_assert(!less<couple<x<1>, x<0>>, couple<x<1>, x<0>>>::value, "");
static_assert( less<couple<x<1>, x<0>>, couple<x<1>, x<1>>>::value, "");

static_assert(!less<couple<x<1>, x<1>>, couple<x<0>, x<0>>>::value, "");
static_assert(!less<couple<x<1>, x<1>>, couple<x<0>, x<1>>>::value, "");
static_assert(!less<couple<x<1>, x<1>>, couple<x<1>, x<0>>>::value, "");
static_assert(!less<couple<x<1>, x<1>>, couple<x<1>, x<1>>>::value, "");


int main() { }
