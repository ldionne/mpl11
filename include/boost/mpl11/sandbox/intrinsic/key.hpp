/*!
 * @file
 * This file defines the `boost::mpl11::key` intrinsic.
 */

#ifndef BOOST_MPL11_INTRINSIC_KEY_HPP
#define BOOST_MPL11_INTRINSIC_KEY_HPP

#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/functional/apply_raw.hpp>


namespace boost { namespace mpl11 {
    namespace intrinsic {
        struct key : detail::tag_dispatched<key> {

        };
    }

    template <typename AssociativeSequence, typename ...Args>
    struct key
        : apply_raw<intrinsic::key, AssociativeSequence, Args...>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INTRINSIC_KEY_HPP
