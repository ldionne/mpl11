/*!
 * @file
 * This file defines the `boost::mpl11::first` intrinsic.
 */

#ifndef BOOST_MPL11_INTRINSIC_FIRST_HPP
#define BOOST_MPL11_INTRINSIC_FIRST_HPP

#include <boost/mpl11/detail/tag_dispatched.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
namespace extension { template <typename Tag> struct first_impl; }

template <typename Pair>
struct first
    : detail::tag_dispatched<
        extension::first_impl, Pair
    >
{ };
}}}

#endif // !BOOST_MPL11_INTRINSIC_FIRST_HPP
