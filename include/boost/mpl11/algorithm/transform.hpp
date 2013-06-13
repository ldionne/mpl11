/*!
 * @file
 * This file defines the `boost::mpl11::transform` algorithm.
 */

#ifndef BOOST_MPL11_ALGORITHM_TRANSFORM_HPP
#define BOOST_MPL11_ALGORITHM_TRANSFORM_HPP

#include <boost/mpl11/detail/tag_dispatched.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
template <typename Sequence, typename ...Args>
struct transform
    : detail::tag_dispatched<transform, Sequence, Args...>
{ };
}}}

#endif // !BOOST_MPL11_ALGORITHM_TRANSFORM_HPP
