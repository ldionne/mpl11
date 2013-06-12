/*!
 * @file
 * This file defines the `boost::mpl11::push_front` intrinsic.
 */

#ifndef BOOST_MPL11_INTRINSIC_PUSH_FRONT_HPP
#define BOOST_MPL11_INTRINSIC_PUSH_FRONT_HPP

#include <boost/mpl11/detail/tag_dispatched.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
namespace extension { template <typename Tag> struct push_front_impl; }

template <typename Sequence, typename Element>
struct push_front
    : detail::tag_dispatched<
        extension::push_front_impl, Sequence, Element
    >
{ };
}}}

#endif // !BOOST_MPL11_INTRINSIC_PUSH_FRONT_HPP
