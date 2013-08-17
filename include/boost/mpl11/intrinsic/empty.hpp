/*!
 * @file
 * This file defines the `boost::mpl11::empty` intrinsic.
 */

#ifndef BOOST_MPL11_INTRINSIC_EMPTY_HPP
#define BOOST_MPL11_INTRINSIC_EMPTY_HPP

#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/functional/apply_raw.hpp>


namespace boost { namespace mpl11 {
    namespace intrinsic {
        struct empty : detail::tag_dispatched<empty> {
            template <typename ...Args>
            struct apply
                : bool_<
                    apply_raw<
                        detail::tag_dispatched<empty>, Args...
                    >::type::value
                >
            { };
        };
    } // end namespace intrinsic

    template <typename Sequence, typename ...Args>
    struct empty
        : apply_raw<intrinsic::empty, Sequence, Args...>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INTRINSIC_EMPTY_HPP
