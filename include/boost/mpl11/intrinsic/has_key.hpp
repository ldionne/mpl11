/*!
 * @file
 * This file defines the `boost::mpl11::has_key` intrinsic.
 */

#ifndef BOOST_MPL11_INTRINSIC_HAS_KEY_HPP
#define BOOST_MPL11_INTRINSIC_HAS_KEY_HPP

#include <boost/mpl11/detail/tag_dispatched.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
namespace extension { template <typename Tag> struct has_key_impl; }

template <typename AssociativeSequence, typename Key>
struct has_key
    : detail::tag_dispatched<
        extension::has_key_impl, AssociativeSequence, Key
    >
{ };
}}}

#endif // !BOOST_MPL11_INTRINSIC_HAS_KEY_HPP
