/*!
 * @file
 * This file defines the `boost::mpl11::second` intrinsic.
 */

#ifndef BOOST_MPL11_INTRINSIC_SECOND_HPP
#define BOOST_MPL11_INTRINSIC_SECOND_HPP

#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/functional/apply_raw.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
namespace intrinsic {
    struct second : detail::tag_dispatched<second> {

    };
}

template <typename Pair, typename ...Args>
struct second
    : apply_raw<intrinsic::second, Pair, Args...>
{ };
}}}

#endif // !BOOST_MPL11_INTRINSIC_SECOND_HPP
