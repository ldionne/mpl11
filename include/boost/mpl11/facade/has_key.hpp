/*!
 * @file
 * This file defines `boost::mpl11::has_key` for facades.
 */

#ifndef BOOST_MPL11_FACADE_HAS_KEY_HPP
#define BOOST_MPL11_FACADE_HAS_KEY_HPP

#include <boost/mpl11/facade/base.hpp>
#include <boost/mpl11/intrinsic/has_key.hpp>


namespace boost { namespace mpl11 { inline namespace v2 { namespace extension {
    template <typename T, typename = typename if_facade_enabled<T, has_key>::type>
    struct has_key_impl<facade_tag<T>> {
        template <typename AssociativeSequence, typename Key>
        struct apply
            : AssociativeSequence::template has_key<Key>
        { };
    };
}}}}

#endif // !BOOST_MPL11_FACADE_HAS_KEY_HPP
