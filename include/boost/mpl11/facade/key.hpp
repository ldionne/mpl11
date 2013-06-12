/*!
 * @file
 * This file defines `boost::mpl11::key` for facades.
 */

#ifndef BOOST_MPL11_FACADE_KEY_HPP
#define BOOST_MPL11_FACADE_KEY_HPP

#include <boost/mpl11/facade/base.hpp>
#include <boost/mpl11/intrinsic/key.hpp>


namespace boost { namespace mpl11 { inline namespace v2 { namespace extension {
    template <typename T, typename = typename if_facade_enabled<T, key>::type>
    struct key_impl<facade_tag<T>> {
        template <typename AssociativeSequence, typename Element>
        struct apply
            : AssociativeSequence::template key<Element>
        { };
    };
}}}}

#endif // !BOOST_MPL11_FACADE_KEY_HPP
