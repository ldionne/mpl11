/*!
 * @file
 * This file defines the `boost::mpl11::deref` intrinsic.
 */

#ifndef BOOST_MPL11_INTRINSIC_DEREF_HPP
#define BOOST_MPL11_INTRINSIC_DEREF_HPP

#include <boost/mpl11/detail/tag_dispatched.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
template <typename Iterator, typename ...Args>
struct deref
    : detail::tag_dispatched<deref, Iterator, Args...>
{ };
}}}

#endif // !BOOST_MPL11_INTRINSIC_DEREF_HPP
