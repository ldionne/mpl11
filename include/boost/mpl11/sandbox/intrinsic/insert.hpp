/*!
 * @file
 * This file defines the `boost::mpl11::insert` intrinsic.
 */

#ifndef BOOST_MPL11_INTRINSIC_INSERT_HPP
#define BOOST_MPL11_INTRINSIC_INSERT_HPP

#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/functional/apply_raw.hpp>


namespace boost { namespace mpl11 {
    namespace intrinsic {
        struct insert : detail::tag_dispatched<insert> {
            struct mpl11 {
                struct is_inplace_transformation;
            };
        };
    }

    template <typename Sequence, typename ...Args>
    struct insert
        : apply_raw<intrinsic::insert, Sequence, Args...>
    { };
}}

#endif // !BOOST_MPL11_INTRINSIC_INSERT_HPP
