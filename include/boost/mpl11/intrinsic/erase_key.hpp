/*!
 * @file
 * This file defines the `boost::mpl11::erase_key` intrinsic.
 */

#ifndef BOOST_MPL11_INTRINSIC_ERASE_KEY_HPP
#define BOOST_MPL11_INTRINSIC_ERASE_KEY_HPP

#include <boost/mpl11/detail/tag_dispatched.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
namespace extension { template <typename Tag> struct erase_key_impl; }

template <typename AssociativeSequence, typename Key>
struct erase_key
    : detail::tag_dispatched<
        extension::erase_key_impl, AssociativeSequence, Key
    >
{ };
}}}

#endif // !BOOST_MPL11_INTRINSIC_ERASE_KEY_HPP
