/*!
 * @file
 * This file defines the `boost::mpl11::front` intrinsic.
 */

#ifndef BOOST_MPL11_INTRINSIC_FRONT_HPP
#define BOOST_MPL11_INTRINSIC_FRONT_HPP

#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/functional/apply_raw.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
namespace intrinsic {
    struct front : detail::tag_dispatched<front> {

    };
}

template <typename Sequence, typename ...Args>
struct front
    : apply_raw<intrinsic::front, Sequence, Args...>
{ };
}}}

#endif // !BOOST_MPL11_INTRINSIC_FRONT_HPP
