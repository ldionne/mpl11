/*!
 * @file
 * This file defines the `boost::mpl11::size` intrinsic.
 */

#ifndef BOOST_MPL11_INTRINSIC_SIZE_HPP
#define BOOST_MPL11_INTRINSIC_SIZE_HPP

#include <boost/mpl11/detail/tag_dispatched.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
namespace extension { template <typename Tag> struct size_impl; }

template <typename Sequence>
struct size
    : detail::tag_dispatched<
        extension::size_impl, Sequence
    >
{ };
}}}

#endif // !BOOST_MPL11_INTRINSIC_SIZE_HPP
