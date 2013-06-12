/*!
 * @file
 * This file defines the `boost::mpl11::insert_range` intrinsic.
 */

#ifndef BOOST_MPL11_INTRINSIC_INSERT_RANGE_HPP
#define BOOST_MPL11_INTRINSIC_INSERT_RANGE_HPP

#include <boost/mpl11/detail/tag_dispatched.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
namespace extension { template <typename Tag> struct insert_range_impl; }

template <typename Sequence, typename Position, typename Range>
struct insert_range
    : detail::tag_dispatched<
        extension::insert_range_impl, Sequence, Position, Range
    >
{ };
}}}

#endif // !BOOST_MPL11_INTRINSIC_INSERT_RANGE_HPP
