/*!
 * @file
 * This file defines `boost::mpl11::pair`.
 */

#ifndef BOOST_MPL11_PAIR_HPP
#define BOOST_MPL11_PAIR_HPP

#include <boost/mpl11/intrinsic/first.hpp>
#include <boost/mpl11/intrinsic/second.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
template <typename First, typename Second>
struct pair {
    struct mpl11 { using tag = pair; };
};

namespace extension {
    template <typename First, typename Second>
    struct first_impl<pair<First, Second>> {
        template <typename Pair>
        struct apply { using type = First; };
    };

    template <typename First, typename Second>
    struct second_impl<pair<First, Second>> {
        template <typename Pair>
        struct apply { using type = Second; };
    };
}
}}}

#endif // !BOOST_MPL11_PAIR_HPP
