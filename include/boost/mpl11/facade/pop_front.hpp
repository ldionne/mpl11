/*!
 * @file
 * This file defines `boost::mpl11::pop_front` for facades.
 */

#ifndef BOOST_MPL11_FACADE_POP_FRONT_HPP
#define BOOST_MPL11_FACADE_POP_FRONT_HPP

#include <boost/mpl11/facade/base.hpp>
#include <boost/mpl11/intrinsic/pop_front.hpp>


namespace boost { namespace mpl11 { inline namespace v2 { namespace extension {
    template <typename T, typename = typename if_facade_enabled<T, pop_front>::type>
    struct pop_front_impl<facade_tag<T>> {
        template <typename Sequence>
        struct apply : Sequence::pop_front { };
    };
}}}}

#endif // !BOOST_MPL11_FACADE_POP_FRONT_HPP
