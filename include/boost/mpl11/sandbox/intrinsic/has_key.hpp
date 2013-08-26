/*!
 * @file
 * This file defines the `boost::mpl11::has_key` intrinsic.
 */

#ifndef BOOST_MPL11_INTRINSIC_HAS_KEY_HPP
#define BOOST_MPL11_INTRINSIC_HAS_KEY_HPP

#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/functional/apply_raw.hpp>


namespace boost { namespace mpl11 {
    namespace intrinsic {
        struct has_key : detail::tag_dispatched<has_key> {
            template <typename ...Args>
            struct apply
                : bool_<
                    apply_raw<
                        detail::tag_dispatched<has_key>, Args...
                    >::type::value
                >
            { };
        };
    } // end namespace intrinsic

    template <typename AssociativeSequence, typename ...Args>
    struct has_key
        : apply_raw<intrinsic::has_key, AssociativeSequence, Args...>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INTRINSIC_HAS_KEY_HPP
