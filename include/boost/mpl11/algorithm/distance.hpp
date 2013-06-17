/*!
 * @file
 * This file defines the `boost::mpl11::distance` algorithm.
 */

#ifndef BOOST_MPL11_ALGORITHM_DISTANCE_HPP
#define BOOST_MPL11_ALGORITHM_DISTANCE_HPP

#include <boost/mpl11/apply_raw.hpp>
#include <boost/mpl11/detail/tag_dispatched.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
namespace algorithm {
    struct distance : detail::tag_dispatched<distance> {

    };
}

template <typename First, typename Last, typename ...Args>
struct distance
    : apply_raw<algorithm::distance, First, Last, Args...>
{ };
}}}

#endif // !BOOST_MPL11_ALGORITHM_DISTANCE_HPP
