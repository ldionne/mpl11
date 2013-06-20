/*!
 * @file
 * This file defines the `boost::mpl11::distance` algorithm.
 */

#ifndef BOOST_MPL11_ALGORITHM_DISTANCE_HPP
#define BOOST_MPL11_ALGORITHM_DISTANCE_HPP

#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/eval.hpp>
#include <boost/mpl11/functional/apply_raw.hpp>
#include <boost/mpl11/if.hpp>
#include <boost/mpl11/intrinsic/next.hpp>
#include <boost/mpl11/is_same.hpp>
#include <boost/mpl11/long.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
namespace distance_detail {
    template <typename First, typename Last, typename N>
    struct default_impl
        : if_<is_same<First, Last>,
            N,
            eval<default_impl<
                eval<next<First>>, Last, eval<next<N>>
            >>
        >
    { };
}

namespace algorithm {
    struct distance : detail::tag_dispatched<distance> {
        struct mpl11 {
            struct returns_integral_c;

            struct default_implementation {
                template <typename First, typename Last>
                struct apply
                    : distance_detail::default_impl<First, Last, long_<0>>
                { };
            };
        };
    };
}

template <typename First, typename Last>
struct distance
    : apply_raw<algorithm::distance, First, Last>
{ };
}}}

#endif // !BOOST_MPL11_ALGORITHM_DISTANCE_HPP
