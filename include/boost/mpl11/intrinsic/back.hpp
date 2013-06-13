/*!
 * @file
 * This file defines the `boost::mpl11::back` intrinsic.
 */

#ifndef BOOST_MPL11_INTRINSIC_BACK_HPP
#define BOOST_MPL11_INTRINSIC_BACK_HPP

#include <boost/mpl11/detail/tag_dispatched.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
template <typename Sequence, typename ...Args>
struct back
    : detail::tag_dispatched<back, Sequence, Args...>
{ };
}}}

#endif // !BOOST_MPL11_INTRINSIC_BACK_HPP
