/*!
 * @file
 * This file defines the `boost::mpl11::empty` intrinsic.
 */

#ifndef BOOST_MPL11_INTRINSIC_EMPTY_HPP
#define BOOST_MPL11_INTRINSIC_EMPTY_HPP

#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/detail/tag_dispatched.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
template <typename Sequence, typename ...Args>
struct empty
    : bool_<detail::tag_dispatched<empty, Sequence, Args...>::type::value>
{ };
}}}

#endif // !BOOST_MPL11_INTRINSIC_EMPTY_HPP
