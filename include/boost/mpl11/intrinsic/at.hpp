/*!
 * @file
 * This file defines the `boost::mpl11::at` intrinsic.
 */

#ifndef BOOST_MPL11_INTRINSIC_AT_HPP
#define BOOST_MPL11_INTRINSIC_AT_HPP

#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/functional/apply_raw.hpp>
#include <boost/mpl11/size_t.hpp>

#include <cstddef>


namespace boost { namespace mpl11 {
    namespace intrinsic {
        struct at : detail::tag_dispatched<at> {

        };
    }

    template <typename Sequence, typename ...Args>
    struct at
        : apply_raw<intrinsic::at, Sequence, Args...>
    { };

    template <typename Sequence, std::size_t N>
    struct at_c
        : at<Sequence, size_t<N>>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INTRINSIC_AT_HPP
