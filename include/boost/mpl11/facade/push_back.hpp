/*!
 * @file
 * This file defines `boost::mpl11::push_back` for facades.
 */

#ifndef BOOST_MPL11_FACADE_PUSH_BACK_HPP
#define BOOST_MPL11_FACADE_PUSH_BACK_HPP

#include <boost/mpl11/facade/base.hpp>
#include <boost/mpl11/intrinsic/push_back.hpp>


namespace boost { namespace mpl11 { inline namespace v2 { namespace extension {
    template <typename T, typename = typename if_facade_enabled<T, push_back>::type>
    struct push_back_impl<facade_tag<T>> {
        template <typename Sequence, typename Element>
        struct apply : Sequence::template push_back<Element> { };
    };
}}}}

#endif // !BOOST_MPL11_FACADE_PUSH_BACK_HPP
