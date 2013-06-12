/*!
 * @file
 * This file defines the `boost::mpl11::insert` intrinsic.
 */

#ifndef BOOST_MPL11_INTRINSIC_INSERT_HPP
#define BOOST_MPL11_INTRINSIC_INSERT_HPP

#include <boost/mpl11/detail/none.hpp>
#include <boost/mpl11/detail/tag_dispatched.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
namespace extension { template <typename Tag> struct insert_impl; }

template <typename Sequence, typename Position, typename Element = detail::none>
struct insert
    : detail::tag_dispatched<
        extension::insert_impl, Sequence, Position, Element
    >
{ };

template <typename AssociativeSequence, typename Element>
struct insert<AssociativeSequence, Element, detail::none>
    : detail::tag_dispatched<
        extension::insert_impl, AssociativeSequence, Element
    >
{ };
}}}

#endif // !BOOST_MPL11_INTRINSIC_INSERT_HPP
