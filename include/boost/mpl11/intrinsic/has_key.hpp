/*!
 * @file
 * This file defines the `boost::mpl11::has_key` intrinsic.
 */

#ifndef BOOST_MPL11_INTRINSIC_HAS_KEY_HPP
#define BOOST_MPL11_INTRINSIC_HAS_KEY_HPP

#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/detail/tag_dispatched.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
template <typename AssociativeSequence, typename ...Args>
struct has_key
    : bool_<
        detail::tag_dispatched<
            has_key, AssociativeSequence, Args...
        >::type::value
    >
{ };
}}}

#endif // !BOOST_MPL11_INTRINSIC_HAS_KEY_HPP
