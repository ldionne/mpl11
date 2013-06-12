/*!
 * @file
 * This file defines `boost::mpl11::next` for facades.
 */

#ifndef BOOST_MPL11_FACADE_NEXT_HPP
#define BOOST_MPL11_FACADE_NEXT_HPP

#include <boost/mpl11/facade/base.hpp>
#include <boost/mpl11/intrinsic/next.hpp>


namespace boost { namespace mpl11 { inline namespace v2 { namespace extension {
    template <typename T, typename = typename if_facade_enabled<T, next>::type>
    struct next_impl<facade_tag<T>> {
        template <typename Iterator>
        struct apply : Iterator::next { };
    };
}}}}

#endif // !BOOST_MPL11_FACADE_NEXT_HPP
