/*!
 * @file
 * This file defines the `boost::mpl11::back` intrinsic.
 */

#ifndef BOOST_MPL11_INTRINSIC_BACK_HPP
#define BOOST_MPL11_INTRINSIC_BACK_HPP

#include <boost/mpl11/detail/tag_dispatched.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
namespace extension { template <typename Tag> struct back_impl; }

template <typename Sequence>
struct back
    : detail::tag_dispatched<
        extension::back_impl, Sequence
    >
{ };
}}}

#endif // !BOOST_MPL11_INTRINSIC_BACK_HPP
