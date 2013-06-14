/*!
 * @file
 * This file defines the `boost::mpl11::end` intrinsic.
 */

#ifndef BOOST_MPL11_INTRINSIC_END_HPP
#define BOOST_MPL11_INTRINSIC_END_HPP

#include <boost/mpl11/apply_raw.hpp>
#include <boost/mpl11/detail/tag_dispatched.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
namespace intrinsic {
    struct end : detail::tag_dispatched<end> {

    };
}

template <typename Sequence, typename ...Args>
struct end
    : apply_raw<intrinsic::end, Sequence, Args...>
{ };
}}}

#endif // !BOOST_MPL11_INTRINSIC_END_HPP
