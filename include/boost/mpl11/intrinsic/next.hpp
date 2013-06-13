/*!
 * @file
 * This file defines the `boost::mpl11::next` intrinsic.
 */

#ifndef BOOST_MPL11_INTRINSIC_NEXT_HPP
#define BOOST_MPL11_INTRINSIC_NEXT_HPP

#include <boost/mpl11/detail/tag_dispatched.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
template <typename Iterator, typename ...Args>
struct next
    : detail::tag_dispatched<next, Iterator, Args...>
{ };
}}}

#endif // !BOOST_MPL11_INTRINSIC_NEXT_HPP
