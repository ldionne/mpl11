/*!
 * @file
 * This file defines the `boost::mpl11::pair` container.
 */

#ifndef BOOST_MPL11_CONTAINER_PAIR_HPP
#define BOOST_MPL11_CONTAINER_PAIR_HPP

#include <boost/mpl11/intrinsic/first.hpp>
#include <boost/mpl11/intrinsic/second.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
template <typename First, typename Second>
class pair {
    struct implementation {
        template <template <typename ...> class Intrinsic, typename ...Args>
        struct apply;

        template <typename Pair>
        struct apply<first, Pair> {
            using type = First;
        };

        template <typename Pair>
        struct apply<second, Pair> {
            using type = Second;
        };
    };

public:
    struct mpl11 { using dispatcher = implementation; };
};
}}}

#endif // !BOOST_MPL11_CONTAINER_PAIR_HPP
