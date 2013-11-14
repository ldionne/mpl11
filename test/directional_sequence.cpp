/*!
 * @file
 * Contains unit tests for `boost::mpl11::DirectionalSequence`.
 */

#include <boost/mpl11/directional_sequence.hpp>

#include <boost/mpl11/at.hpp>
#include <boost/mpl11/comparable.hpp>
#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/equal.hpp>
#include <boost/mpl11/forward_iterator.hpp>
#include <boost/mpl11/front.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/less.hpp>
#include <boost/mpl11/orderable.hpp>
#include <boost/mpl11/vector.hpp>


using namespace boost::mpl11;
using detail::is_same;

template <typename ...Elements>
struct sequence {
    template <unsigned long Position>
    struct iterator {
        static constexpr auto position = Position;

        struct mpl_class : ForwardIterator {
            template <typename Self, typename Other>
            struct equal_impl
                : bool_<Self::position == Other::position>
            { };

            template <typename Self>
            struct next_impl {
                using type = iterator<Self::position + 1>;
            };

            template <typename Self>
            struct deref_impl
                : at_c<vector<Elements...>, Self::position>
            { };
        };
    };

    struct mpl_class : DirectionalSequence {
        template <typename Self>
        struct begin_impl { using type = iterator<0>; };

        template <typename Self>
        struct end_impl { using type = iterator<sizeof...(Elements)>; };
    };
};

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

template <int ...i>
using seq = sequence<x<i>...>;

// front
static_assert(is_same<front<seq<0>>::type, x<0>>::value, "");
static_assert(is_same<front<seq<0, 1>>::type, x<0>>::value, "");
static_assert(is_same<front<seq<0, 1, 2>>::type, x<0>>::value, "");


// equal
static_assert(equal<seq<>, seq<>>::value, "");
static_assert(equal<seq<0>, seq<0>>::value, "");
static_assert(equal<seq<0, 1>, seq<0, 1>>::value, "");

static_assert(!equal<seq<>, seq<0>>::value, "");
static_assert(!equal<seq<0>, seq<>>::value, "");
static_assert(!equal<seq<0>, seq<0, 1>>::value, "");
static_assert(!equal<seq<0, 1>, seq<0>>::value, "");

static_assert(!equal<seq<0>, seq<1>>::value, "");
static_assert(!equal<seq<0, 1>, seq<0, 2>>::value, "");
static_assert(!equal<seq<0, 1, 2>, seq<0, 1, 3>>::value, "");


// less
static_assert(!less<seq<>, seq<>>::value, "");
static_assert( less<seq<>, seq<0>>::value, "");
static_assert( less<seq<>, seq<0, 1>>::value, "");

static_assert(!less<seq<0>, seq<>>::value, "");
static_assert(!less<seq<0>, seq<0>>::value, "");
static_assert( less<seq<0>, seq<1>>::value, "");
static_assert( less<seq<0>, seq<0, 1>>::value, "");

static_assert(!less<seq<0, 1>, seq<>>::value, "");
static_assert(!less<seq<0, 1>, seq<0>>::value, "");
static_assert( less<seq<0, 1>, seq<1>>::value, "");
static_assert(!less<seq<0, 1>, seq<0, 1>>::value, "");
static_assert( less<seq<0, 1>, seq<0, 1, 2>>::value, "");
static_assert(!less<seq<0, 2>, seq<0, 1>>::value, "");
static_assert(!less<seq<0, 2>, seq<0, 1, 2>>::value, "");

// miscellaneous tests for less
static_assert( less<seq<0, 1, 2, 3, 4>, seq<0, 1, 4, 1>>::value, "");
static_assert(!less<seq<0, 1, 4, 3, 4>, seq<0, 1, 2, 3, 4>>::value, "");


int main() { }
