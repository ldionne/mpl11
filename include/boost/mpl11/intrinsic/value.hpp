/*!
 * @file
 * This file defines the `boost::mpl11::value` intrinsic.
 */

#ifndef BOOST_MPL11_INTRINSIC_VALUE_HPP
#define BOOST_MPL11_INTRINSIC_VALUE_HPP

#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/functional/apply_raw.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
namespace intrinsic {
    struct value : detail::tag_dispatched<value> {

    };
}

template <typename AssociativeSequence, typename ...Args>
struct value
    : apply_raw<intrinsic::value, AssociativeSequence, Args...>
{ };
}}}

#endif // !BOOST_MPL11_INTRINSIC_VALUE_HPP
