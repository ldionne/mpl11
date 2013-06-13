/*!
 * @file
 * This file defines the `boost::mpl11::front` intrinsic.
 */

#ifndef BOOST_MPL11_INTRINSIC_FRONT_HPP
#define BOOST_MPL11_INTRINSIC_FRONT_HPP

#include <boost/mpl11/detail/tag_dispatched.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
template <typename Sequence, typename ...Args>
struct front
    : detail::tag_dispatched<front, Sequence, Args...>
{ };
}}}

#endif // !BOOST_MPL11_INTRINSIC_FRONT_HPP
