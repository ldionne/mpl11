/*!
 * @file
 * This file defines `boost::mpl11::clear` for facades.
 */

#ifndef BOOST_MPL11_FACADE_CLEAR_HPP
#define BOOST_MPL11_FACADE_CLEAR_HPP

#include <boost/mpl11/facade/base.hpp>
#include <boost/mpl11/intrinsic/clear.hpp>


namespace boost { namespace mpl11 { inline namespace v2 { namespace extension {
    template <typename T, typename = typename if_facade_enabled<T, clear>::type>
    struct clear_impl<facade_tag<T>> {
        template <typename Sequence>
        struct apply : Sequence::clear { };
    };
}}}}

#endif // !BOOST_MPL11_FACADE_CLEAR_HPP
