/*!
 * @file
 * This file defines the `boost::mpl11::clear` intrinsic.
 */

#ifndef BOOST_MPL11_INTRINSIC_CLEAR_HPP
#define BOOST_MPL11_INTRINSIC_CLEAR_HPP

#include <boost/mpl11/apply_raw.hpp>
#include <boost/mpl11/detail/tag_dispatched.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
namespace intrinsic {
    struct clear : detail::tag_dispatched<clear> {

    };
}

template <typename Sequence, typename ...Args>
struct clear
    : apply_raw<intrinsic::clear, Sequence, Args...>
{ };
}}}

#endif // !BOOST_MPL11_INTRINSIC_CLEAR_HPP
