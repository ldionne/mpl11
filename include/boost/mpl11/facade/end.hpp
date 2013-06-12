/*!
 * @file
 * This file defines `boost::mpl11::end` for facades.
 */

#ifndef BOOST_MPL11_FACADE_END_HPP
#define BOOST_MPL11_FACADE_END_HPP

#include <boost/mpl11/facade/base.hpp>
#include <boost/mpl11/intrinsic/end.hpp>


namespace boost { namespace mpl11 { inline namespace v2 { namespace extension {
    template <typename T, typename = typename if_facade_enabled<T, end>::type>
    struct end_impl<facade_tag<T>> {
        template <typename Sequence>
        struct apply : Sequence::end { };
    };
}}}}

#endif // !BOOST_MPL11_FACADE_END_HPP
