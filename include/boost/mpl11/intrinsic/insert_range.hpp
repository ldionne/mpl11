/*!
 * @file
 * This file defines the `boost::mpl11::insert_range` intrinsic.
 */

#ifndef BOOST_MPL11_INTRINSIC_INSERT_RANGE_HPP
#define BOOST_MPL11_INTRINSIC_INSERT_RANGE_HPP

#include <boost/mpl11/detail/tag_dispatched.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
template <typename Sequence, typename ...Args>
struct insert_range
    : detail::tag_dispatched<insert_range, Sequence, Args...>
{ };
}}}

#endif // !BOOST_MPL11_INTRINSIC_INSERT_RANGE_HPP
