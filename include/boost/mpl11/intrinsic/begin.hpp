/*!
 * @file
 * This file defines the `boost::mpl11::begin` intrinsic.
 */

#ifndef BOOST_MPL11_INTRINSIC_BEGIN_HPP
#define BOOST_MPL11_INTRINSIC_BEGIN_HPP

#include <boost/mpl11/detail/tag_dispatched.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
namespace extension { template <typename Tag> struct begin_impl; }

template <typename Sequence>
struct begin
    : detail::tag_dispatched<
        extension::begin_impl, Sequence
    >
{ };
}}}

#endif // !BOOST_MPL11_INTRINSIC_BEGIN_HPP
