/*!
 * @file
 * This file defines `boost::mpl11::second` for facades.
 */

#ifndef BOOST_MPL11_FACADE_SECOND_HPP
#define BOOST_MPL11_FACADE_SECOND_HPP

#include <boost/mpl11/facade/base.hpp>
#include <boost/mpl11/intrinsic/second.hpp>


namespace boost { namespace mpl11 { inline namespace v2 { namespace extension {
    template <typename T, typename = typename if_facade_enabled<T, second>::type>
    struct second_impl<facade_tag<T>> {
        template <typename Pair>
        struct apply : Pair::second { };
    };
}}}}

#endif // !BOOST_MPL11_FACADE_SECOND_HPP
