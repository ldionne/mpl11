/*!
 * @file
 * This file defines `boost::mpl11::first` for facades.
 */

#ifndef BOOST_MPL11_FACADE_FIRST_HPP
#define BOOST_MPL11_FACADE_FIRST_HPP

#include <boost/mpl11/facade/base.hpp>
#include <boost/mpl11/intrinsic/first.hpp>


namespace boost { namespace mpl11 { inline namespace v2 { namespace extension {
    template <typename T, typename = typename if_facade_enabled<T, first>::type>
    struct first_impl<facade_tag<T>> {
        template <typename Pair>
        struct apply : Pair::first { };
    };
}}}}

#endif // !BOOST_MPL11_FACADE_FIRST_HPP
