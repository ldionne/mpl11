/*!
 * @file
 * This file defines the `boost::mpl11::value` intrinsic.
 */

#ifndef BOOST_MPL11_INTRINSIC_VALUE_HPP
#define BOOST_MPL11_INTRINSIC_VALUE_HPP

#include <boost/mpl11/detail/tag_dispatched.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
template <typename AssociativeSequence, typename ...Args>
struct value
    : detail::tag_dispatched<value, AssociativeSequence, Args...>
{ };
}}}

#endif // !BOOST_MPL11_INTRINSIC_VALUE_HPP
