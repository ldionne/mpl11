/*!
 * @file
 * This file defines `boost::mpl11::begin` for facades.
 */

#ifndef BOOST_MPL11_FACADE_BEGIN_HPP
#define BOOST_MPL11_FACADE_BEGIN_HPP

#include <boost/mpl11/facade/base.hpp>
#include <boost/mpl11/intrinsic/begin.hpp>


namespace boost { namespace mpl11 { inline namespace v2 { namespace extension {
    template <typename T, typename = typename if_facade_enabled<T, begin>::type>
    struct begin_impl<facade_tag<T>> {
        template <typename Sequence>
        struct apply : Sequence::begin { };
    };
}}}}

#endif // !BOOST_MPL11_FACADE_BEGIN_HPP
