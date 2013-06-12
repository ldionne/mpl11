/*!
 * @file
 * This file defines `boost::mpl11::pop_back` for facades.
 */

#ifndef BOOST_MPL11_FACADE_POP_BACK_HPP
#define BOOST_MPL11_FACADE_POP_BACK_HPP

#include <boost/mpl11/facade/base.hpp>
#include <boost/mpl11/intrinsic/pop_back.hpp>


namespace boost { namespace mpl11 { inline namespace v2 { namespace extension {
    template <typename T, typename = typename if_facade_enabled<T, pop_back>::type>
    struct pop_back_impl<facade_tag<T>> {
        template <typename Sequence>
        struct apply : Sequence::pop_back { };
    };
}}}}

#endif // !BOOST_MPL11_FACADE_POP_BACK_HPP
