/*!
 * @file
 * This file defines `boost::mpl11::empty` for facades.
 */

#ifndef BOOST_MPL11_FACADE_EMPTY_HPP
#define BOOST_MPL11_FACADE_EMPTY_HPP

#include <boost/mpl11/facade/base.hpp>
#include <boost/mpl11/intrinsic/empty.hpp>


namespace boost { namespace mpl11 { inline namespace v2 { namespace extension {
    template <typename T, typename = typename if_facade_enabled<T, empty>::type>
    struct empty_impl<facade_tag<T>> {
        template <typename Sequence>
        struct apply : Sequence::empty { };
    };
}}}}

#endif // !BOOST_MPL11_FACADE_EMPTY_HPP
