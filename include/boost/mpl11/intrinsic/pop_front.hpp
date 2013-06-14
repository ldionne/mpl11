/*!
 * @file
 * This file defines the `boost::mpl11::pop_front` intrinsic.
 */

#ifndef BOOST_MPL11_INTRINSIC_POP_FRONT_HPP
#define BOOST_MPL11_INTRINSIC_POP_FRONT_HPP

#include <boost/mpl11/apply_raw.hpp>
#include <boost/mpl11/detail/tag_dispatched.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
namespace intrinsic {
    struct pop_front : detail::tag_dispatched<pop_front> {

    };
}

template <typename Sequence, typename ...Args>
struct pop_front
    : apply_raw<intrinsic::pop_front, Sequence, Args...>
{ };
}}}

#endif // !BOOST_MPL11_INTRINSIC_POP_FRONT_HPP
