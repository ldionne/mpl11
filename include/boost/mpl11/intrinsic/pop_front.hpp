/*!
 * @file
 * This file defines the `boost::mpl11::pop_front` intrinsic.
 */

#ifndef BOOST_MPL11_INTRINSIC_POP_FRONT_HPP
#define BOOST_MPL11_INTRINSIC_POP_FRONT_HPP

#include <boost/mpl11/detail/tag_dispatched.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
namespace extension { template <typename Tag> struct pop_front_impl; }

template <typename Sequence>
struct pop_front
    : detail::tag_dispatched<
        extension::pop_front_impl, Sequence
    >
{ };
}}}

#endif // !BOOST_MPL11_INTRINSIC_POP_FRONT_HPP
