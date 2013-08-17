/*!
 * @file
 * This file defines the `boost::mpl11::back` intrinsic.
 */

#ifndef BOOST_MPL11_INTRINSIC_BACK_HPP
#define BOOST_MPL11_INTRINSIC_BACK_HPP

#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/functional/apply_raw.hpp>


namespace boost { namespace mpl11 {
    namespace intrinsic {
        struct back : detail::tag_dispatched<back> {

        };
    }

    template <typename Sequence, typename ...Args>
    struct back
        : apply_raw<intrinsic::back, Sequence, Args...>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INTRINSIC_BACK_HPP
