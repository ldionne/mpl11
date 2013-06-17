/*!
 * @file
 * This file defines the `boost::mpl11::begin` intrinsic.
 */

#ifndef BOOST_MPL11_INTRINSIC_BEGIN_HPP
#define BOOST_MPL11_INTRINSIC_BEGIN_HPP

#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/functional/apply_raw.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
namespace intrinsic {
    struct begin : detail::tag_dispatched<begin> {

    };
}

template <typename Sequence, typename ...Args>
struct begin
    : apply_raw<intrinsic::begin, Sequence, Args...>
{ };
}}}

#endif // !BOOST_MPL11_INTRINSIC_BEGIN_HPP
