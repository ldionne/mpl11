/*!
 * @file
 * This file defines `boost::mpl11::front` for facades.
 */

#ifndef BOOST_MPL11_FACADE_FRONT_HPP
#define BOOST_MPL11_FACADE_FRONT_HPP

#include <boost/mpl11/facade/base.hpp>
#include <boost/mpl11/intrinsic/front.hpp>


namespace boost { namespace mpl11 { inline namespace v2 { namespace extension {
    template <typename T, typename = typename if_facade_enabled<T, front>::type>
    struct front_impl<facade_tag<T>> {
        template <typename Sequence>
        struct apply : Sequence::front { };
    };
}}}}

#endif // !BOOST_MPL11_FACADE_FRONT_HPP
