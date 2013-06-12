/*!
 * @file
 * This file defines the `boost::mpl11::second` intrinsic.
 */

#ifndef BOOST_MPL11_INTRINSIC_SECOND_HPP
#define BOOST_MPL11_INTRINSIC_SECOND_HPP

#include <boost/mpl11/detail/tag_dispatched.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
namespace extension { template <typename Tag> struct second_impl; }

template <typename Pair>
struct second
    : detail::tag_dispatched<
        extension::second_impl, Pair
    >
{ };
}}}

#endif // !BOOST_MPL11_INTRINSIC_SECOND_HPP
