/*!
 * @file
 * This file defines `boost::mpl11::size` for facades.
 */

#ifndef BOOST_MPL11_FACADE_SIZE_HPP
#define BOOST_MPL11_FACADE_SIZE_HPP

#include <boost/mpl11/facade/base.hpp>
#include <boost/mpl11/intrinsic/size.hpp>


namespace boost { namespace mpl11 { inline namespace v2 { namespace extension {
    template <typename T, typename = typename if_facade_enabled<T, size>::type>
    struct size_impl<facade_tag<T>> {
        template <typename Sequence>
        struct apply : Sequence::size { };
    };
}}}}

#endif // !BOOST_MPL11_FACADE_SIZE_HPP
