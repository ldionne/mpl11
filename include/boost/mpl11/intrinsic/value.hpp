/*!
 * @file
 * This file defines the `boost::mpl11::value` intrinsic.
 */

#ifndef BOOST_MPL11_INTRINSIC_VALUE_HPP
#define BOOST_MPL11_INTRINSIC_VALUE_HPP

#include <boost/mpl11/detail/tag_dispatched.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
namespace extension { template <typename Tag> struct value_impl; }

template <typename AssociativeSequence, typename Element>
struct value
    : detail::tag_dispatched<
        extension::value_impl, AssociativeSequence, Element
    >
{ };
}}}

#endif // !BOOST_MPL11_INTRINSIC_VALUE_HPP
