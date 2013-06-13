/*!
 * @file
 * This file defines the `boost::mpl11::key` intrinsic.
 */

#ifndef BOOST_MPL11_INTRINSIC_KEY_HPP
#define BOOST_MPL11_INTRINSIC_KEY_HPP

#include <boost/mpl11/detail/tag_dispatched.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
template <typename AssociativeSequence, typename ...Args>
struct key
    : detail::tag_dispatched<key, AssociativeSequence, Args...>
{ };
}}}

#endif // !BOOST_MPL11_INTRINSIC_KEY_HPP
