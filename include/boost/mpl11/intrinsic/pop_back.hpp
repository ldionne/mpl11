/*!
 * @file
 * This file defines the `boost::mpl11::pop_back` intrinsic.
 */

#ifndef BOOST_MPL11_INTRINSIC_POP_BACK_HPP
#define BOOST_MPL11_INTRINSIC_POP_BACK_HPP

#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/functional/apply_raw.hpp>


namespace boost { namespace mpl11 {
    namespace intrinsic {
        struct pop_back : detail::tag_dispatched<pop_back> {
            struct mpl11 {
                struct is_inplace_transformation;
            };
        };
    }

    template <typename Sequence, typename ...Args>
    struct pop_back
        : apply_raw<intrinsic::pop_back, Sequence, Args...>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INTRINSIC_POP_BACK_HPP
