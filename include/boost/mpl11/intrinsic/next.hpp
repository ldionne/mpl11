/*!
 * @file
 * This file defines the `boost::mpl11::next` intrinsic.
 */

#ifndef BOOST_MPL11_INTRINSIC_NEXT_HPP
#define BOOST_MPL11_INTRINSIC_NEXT_HPP

#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/functional/apply_raw.hpp>


namespace boost { namespace mpl11 {
    namespace intrinsic {
        struct next : detail::tag_dispatched<next> {
            struct mpl11 {
                struct is_inplace_transformation;
            };
        };
    }

    template <typename Iterator, typename ...Args>
    struct next
        : apply_raw<intrinsic::next, Iterator, Args...>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INTRINSIC_NEXT_HPP
