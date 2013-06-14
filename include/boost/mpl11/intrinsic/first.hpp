/*!
 * @file
 * This file defines the `boost::mpl11::first` intrinsic.
 */

#ifndef BOOST_MPL11_INTRINSIC_FIRST_HPP
#define BOOST_MPL11_INTRINSIC_FIRST_HPP

#include <boost/mpl11/apply_raw.hpp>
#include <boost/mpl11/detail/tag_dispatched.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
namespace intrinsic {
    struct first : detail::tag_dispatched<first> {

    };
}

template <typename Pair, typename ...Args>
struct first
    : apply_raw<intrinsic::first, Pair, Args...>
{ };
}}}

#endif // !BOOST_MPL11_INTRINSIC_FIRST_HPP
