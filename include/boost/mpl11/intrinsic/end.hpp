/*!
 * @file
 * This file defines the `boost::mpl11::end` intrinsic.
 */

#ifndef BOOST_MPL11_INTRINSIC_END_HPP
#define BOOST_MPL11_INTRINSIC_END_HPP

#include <boost/mpl11/detail/tag_dispatched.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
namespace extension { template <typename Tag> struct end_impl; }

template <typename Sequence>
struct end
    : detail::tag_dispatched<
        extension::end_impl, Sequence
    >
{ };
}}}

#endif // !BOOST_MPL11_INTRINSIC_END_HPP
