/*!
 * @file
 * This file defines the `boost::mpl11::deref` intrinsic.
 */

#ifndef BOOST_MPL11_INTRINSIC_DEREF_HPP
#define BOOST_MPL11_INTRINSIC_DEREF_HPP

#include <boost/mpl11/detail/tag_dispatched.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
namespace extension { template <typename Tag> struct deref_impl; }

template <typename Iterator>
struct deref
    : detail::tag_dispatched<
        extension::deref_impl, Iterator
    >
{ };
}}}

#endif // !BOOST_MPL11_INTRINSIC_DEREF_HPP
