/*!
 * @file
 * This file defines `boost::mpl11::push_front` for facades.
 */

#ifndef BOOST_MPL11_FACADE_PUSH_FRONT_HPP
#define BOOST_MPL11_FACADE_PUSH_FRONT_HPP

#include <boost/mpl11/facade/base.hpp>
#include <boost/mpl11/intrinsic/push_front.hpp>


namespace boost { namespace mpl11 { inline namespace v2 { namespace extension {
    template <typename T, typename = typename if_facade_enabled<T, push_front>::type>
    struct push_front_impl<facade_tag<T>> {
        template <typename Sequence, typename Element>
        struct apply : Sequence::template push_front<Element> { };
    };
}}}}

#endif // !BOOST_MPL11_FACADE_PUSH_FRONT_HPP
