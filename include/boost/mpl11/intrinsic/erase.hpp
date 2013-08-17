/*!
 * @file
 * This file defines the `boost::mpl11::erase` intrinsic.
 */

#ifndef BOOST_MPL11_INTRINSIC_ERASE_HPP
#define BOOST_MPL11_INTRINSIC_ERASE_HPP

#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/functional/apply_raw.hpp>


namespace boost { namespace mpl11 {
    namespace intrinsic {
        struct erase : detail::tag_dispatched<erase> {
            struct mpl11 {
                struct is_inplace_transformation;
            };
        };
    }

    template <typename Sequence, typename ...Args>
    struct erase
        : apply_raw<intrinsic::erase, Sequence, Args...>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INTRINSIC_ERASE_HPP
