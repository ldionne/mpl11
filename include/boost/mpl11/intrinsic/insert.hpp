/*!
 * @file
 * This file defines the `boost::mpl11::insert` intrinsic.
 */

#ifndef BOOST_MPL11_INTRINSIC_INSERT_HPP
#define BOOST_MPL11_INTRINSIC_INSERT_HPP

#include <boost/mpl11/detail/tag_dispatched.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
template <typename Sequence, typename ...Args>
struct insert
    : detail::tag_dispatched<insert, Sequence, Args...>
{ };
}}}

#endif // !BOOST_MPL11_INTRINSIC_INSERT_HPP
