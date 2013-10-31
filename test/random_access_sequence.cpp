/*!
 * @file
 * Contains unit tests for `boost::mpl11::RandomAccessSequence`.
 */

#include <boost/mpl11/random_access_sequence.hpp>

#include <boost/mpl11/at.hpp>
#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/detail/variadic_at.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/random_access_iterator.hpp>


using namespace boost::mpl11;
using detail::is_same;

template <typename ...Elements>
struct sequence {
    template <unsigned long Position>
    struct iterator {
        static constexpr auto position = Position;

        struct mpl_class : RandomAccessIterator {
            template <typename Self, typename Other>
            struct equal_impl
                : bool_<Self::position == Other::position>
            { };

            template <typename Self, typename Other>
            struct less_impl
                : bool_<Self::position < Other::position>
            { };

            template <typename Self, typename Other>
            struct distance_impl
                : longlong<Other::position - Self::position>
            {
                static_assert(Self::position <= Other::position,
                "invalid arguments to distance");
            };

            template <typename Self, typename N>
            struct advance_impl {
                using type = iterator<Self::position + N::value>;
            };

            template <typename Self>
            struct next_impl {
                using type = iterator<Self::position + 1>;
            };

            template <typename Self>
            struct prev_impl {
                using type = iterator<Self::position - 1>;
            };

            template <typename Self>
            struct deref_impl
                : detail::variadic_at_c<Self::position, Elements...>
            { };
        };
    };

    struct mpl_class : RandomAccessSequence {
        template <typename Self>
        struct begin_impl { using type = iterator<0>; };

        template <typename Self>
        struct end_impl { using type = iterator<sizeof...(Elements)>; };
    };
};

template <int> struct x;

template <int ...i>
using seq = sequence<x<i>...>;

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
