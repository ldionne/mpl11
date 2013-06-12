/*!
 * @file
 * This file defines `boost::mpl11::back` for facades.
 */

#ifndef BOOST_MPL11_FACADE_BACK_HPP
#define BOOST_MPL11_FACADE_BACK_HPP

#include <boost/mpl11/facade/base.hpp>
#include <boost/mpl11/intrinsic/back.hpp>


namespace boost { namespace mpl11 { inline namespace v2 { namespace extension {
    template <typename T, typename = typename if_facade_enabled<T, back>::type>
    struct back_impl<facade_tag<T>> {
        template <typename Sequence>
        struct apply : Sequence::back { };
    };
}}}}

#endif // !BOOST_MPL11_FACADE_BACK_HPP
