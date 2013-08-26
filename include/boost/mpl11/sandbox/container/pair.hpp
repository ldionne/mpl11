/*!
 * @file
 * This file defines the `boost::mpl11::pair` container.
 */

#ifndef BOOST_MPL11_CONTAINER_PAIR_HPP
#define BOOST_MPL11_CONTAINER_PAIR_HPP

#include <boost/mpl11/intrinsic/first.hpp>
#include <boost/mpl11/intrinsic/second.hpp>


namespace boost { namespace mpl11 {
template <typename First, typename Second>
class pair {
    struct implementation {
        template <typename Intrinsic, typename ...Args>
        struct apply;

        template <typename ...Ignore>
        struct apply<intrinsic::first, Ignore...> {
            using type = First;
        };

        template <typename ...Ignore>
        struct apply<intrinsic::second, Ignore...> {
            using type = Second;
        };
    };

public:
    struct mpl11 { using dispatcher = implementation; };
};
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_CONTAINER_PAIR_HPP
