/*!
 * @file
 * Defines `boost::mpl11::insert`.
 */

#ifndef BOOST_MPL11_INSERT_HPP
#define BOOST_MPL11_INSERT_HPP

#include <boost/mpl11/arg.hpp>
#include <boost/mpl11/detail/always_false.hpp>
#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/insert_range.hpp>
#include <boost/mpl11/single_view.hpp>


namespace boost { namespace mpl11 {
namespace tag { struct insert; }

template <typename Sequence, typename Position, typename ...Element>
struct insert {
    static_assert(detail::always_false<Sequence, Position, Element...>::value,
    "Too many arguments to `insert`. "
    "Usage is `insert<Sequence, Position, Element>` or "
    "`insert<AssociativeSequence, Element>`.");

    struct type;
};

/*!
 * Inserts an element at an arbitrary position in a sequence.
 *
 * The default implementation is equivalent to
 * `insert_range<Sequence, Position, single_view<Element>>`.
 *
 * @warning
 * Differences from the original MPL:
 * - The default implementation differs.
 */
template <typename Sequence, typename Position, typename Element>
struct insert<Sequence, Position, Element>
    : detail::tag_dispatched<tag::insert, Sequence, Position, Element>
      ::template with_default<insert_range<_2, _3, single_view<_4>>>
{ };

/*!
 * Inserts an element in an associative sequence.
 *
 * No default implementation is provided for this operation.
 */
template <typename AssociativeSequence, typename Element>
struct insert<AssociativeSequence, Element>
    : detail::tag_dispatched<tag::insert, AssociativeSequence, Element>
      ::template with_default<>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INSERT_HPP
