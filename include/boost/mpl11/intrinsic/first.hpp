/*!
 * @file
 * This file defines the `boost::mpl11::first` intrinsic.
 */

#ifndef BOOST_MPL11_INTRINSIC_FIRST_HPP
#define BOOST_MPL11_INTRINSIC_FIRST_HPP

#include <boost/mpl11/detail/tag_dispatched.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
template <typename Pair, typename ...Args>
struct first
    : detail::tag_dispatched<first, Pair, Args...>
{ };
}}}

#endif // !BOOST_MPL11_INTRINSIC_FIRST_HPP
