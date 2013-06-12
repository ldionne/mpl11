/*!
 * @file
 * This file defines `boost::mpl11::insert_range` for facades.
 */

#ifndef BOOST_MPL11_FACADE_INSERT_RANGE_HPP
#define BOOST_MPL11_FACADE_INSERT_RANGE_HPP

#include <boost/mpl11/facade/base.hpp>
#include <boost/mpl11/intrinsic/insert_range.hpp>


namespace boost { namespace mpl11 { inline namespace v2 { namespace extension {
    template <typename T, typename = typename if_facade_enabled<T, insert_range>::type>
    struct insert_range_impl<facade_tag<T>> {
        template <typename Sequence, typename Position, typename Range>
        struct apply
            : Sequence::template insert_range<Position, Range>
        { };
    };
}}}}

#endif // !BOOST_MPL11_FACADE_INSERT_RANGE_HPP
