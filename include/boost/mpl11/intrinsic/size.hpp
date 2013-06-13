/*!
 * @file
 * This file defines the `boost::mpl11::size` intrinsic.
 */

#ifndef BOOST_MPL11_INTRINSIC_SIZE_HPP
#define BOOST_MPL11_INTRINSIC_SIZE_HPP

#include <boost/mpl11/detail/tag_dispatched.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
template <typename Sequence, typename ...Args>
struct size
    : detail::tag_dispatched<size, Sequence, Args...>
{ };
}}}

#endif // !BOOST_MPL11_INTRINSIC_SIZE_HPP
