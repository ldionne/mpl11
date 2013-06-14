/*!
 * @file
 * This file defines the `boost::mpl11::insert_range` intrinsic.
 */

#ifndef BOOST_MPL11_INTRINSIC_INSERT_RANGE_HPP
#define BOOST_MPL11_INTRINSIC_INSERT_RANGE_HPP

#include <boost/mpl11/apply_raw.hpp>
#include <boost/mpl11/detail/tag_dispatched.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
namespace intrinsic {
    struct insert_range : detail::tag_dispatched<insert_range> {
        struct mpl11 {
            struct is_inplace_transformation;
        };
    };
}

template <typename Sequence, typename ...Args>
struct insert_range
    : apply_raw<intrinsic::insert_range, Sequence, Args...>
{ };
}}}

#endif // !BOOST_MPL11_INTRINSIC_INSERT_RANGE_HPP
