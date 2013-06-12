/*!
 * @file
 * This file defines `boost::mpl11::deref` for facades.
 */

#ifndef BOOST_MPL11_FACADE_DEREF_HPP
#define BOOST_MPL11_FACADE_DEREF_HPP

#include <boost/mpl11/facade/base.hpp>
#include <boost/mpl11/intrinsic/deref.hpp>


namespace boost { namespace mpl11 { inline namespace v2 { namespace extension {
    template <typename T, typename = typename if_facade_enabled<T, deref>::type>
    struct deref_impl<facade_tag<T>> {
        template <typename Iterator>
        struct apply : Iterator::deref { };
    };
}}}}

#endif // !BOOST_MPL11_FACADE_DEREF_HPP
