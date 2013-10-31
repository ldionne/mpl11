/*!
 * @file
 * Contains unit tests for `boost::mpl11::BidirectionalSequence`.
 */

#include <boost/mpl11/bidirectional_sequence.hpp>

#include <boost/mpl11/back.hpp>
#include <boost/mpl11/bidirectional_iterator.hpp>
#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/detail/variadic_at.hpp>
#include <boost/mpl11/integral_c.hpp>


using namespace boost::mpl11;
using detail::is_same;

template <typename ...Elements>
struct sequence {
    template <unsigned long Position>
    struct iterator {
        static constexpr auto position = Position;

        struct mpl_class : BidirectionalIterator {
            template <typename Self, typename Other>
            struct equal_impl
                : bool_<Self::position == Other::position>
            { };

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

    struct mpl_class : BidirectionalSequence {
        template <typename Self>
        struct begin_impl { using type = iterator<0>; };

        template <typename Self>
        struct end_impl { using type = iterator<sizeof...(Elements)>; };
    };
};

template <int> struct x;

// back
static_assert(is_same<back<sequence<x<0>>>::type, x<0>>::value, "");
static_assert(is_same<back<sequence<x<0>, x<1>>>::type, x<1>>::value, "");
static_assert(is_same<back<sequence<x<0>, x<1>, x<2>>>::type, x<2>>::value, "");


int main() { }
