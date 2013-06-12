/*!
 * @file
 * This file defines the `boost::mpl11::push_back` intrinsic.
 */

#ifndef BOOST_MPL11_INTRINSIC_PUSH_BACK_HPP
#define BOOST_MPL11_INTRINSIC_PUSH_BACK_HPP

#include <boost/mpl11/detail/tag_dispatched.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
namespace extension { template <typename Tag> struct push_back_impl; }

template <typename Sequence, typename Element>
struct push_back
    : detail::tag_dispatched<
        extension::push_back_impl, Sequence, Element
    >
{ };
}}}

#endif // !BOOST_MPL11_INTRINSIC_PUSH_BACK_HPP
