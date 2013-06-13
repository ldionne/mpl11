/*!
 * @file
 * This file defines the `boost::mpl11::clear` intrinsic.
 */

#ifndef BOOST_MPL11_INTRINSIC_CLEAR_HPP
#define BOOST_MPL11_INTRINSIC_CLEAR_HPP

#include <boost/mpl11/detail/tag_dispatched.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
template <typename Sequence, typename ...Args>
struct clear
    : detail::tag_dispatched<clear, Sequence, Args...>
{ };
}}}

#endif // !BOOST_MPL11_INTRINSIC_CLEAR_HPP
