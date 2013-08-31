/*!
 * @file
 * Defines `boost::mpl11::insert`.
 */

#ifndef BOOST_MPL11_INSERT_HPP
#define BOOST_MPL11_INSERT_HPP

#include <boost/mpl11/arg.hpp>
#include <boost/mpl11/detail/doxygen_only.hpp>
#include <boost/mpl11/detail/optional.hpp>
#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/insert_range.hpp>
#include <boost/mpl11/tags.hpp>
#include <boost/mpl11/view/single_element.hpp>


namespace boost { namespace mpl11 {
template <typename Sequence, typename Position,
          typename Element = detail::optional>
struct insert;

/*!
 * Inserts an element at an arbitrary position in a sequence.
 *
 * The default implementation is equivalent to
 * `insert_range<Sequence, Position, view::single_element<Element>>`.
 *
 * @warning
 * Differences from the original MPL:
 * - The default implementation differs.
 */
template <typename Sequence, typename Position, typename Element>
struct insert BOOST_MPL11_DOXYGEN_ONLY(<Sequence, Position, Element>)
    : detail::tag_dispatched<tag::insert, Sequence, Position, Element>
      ::template with_default<insert_range<_1, _2, view::single_element<_3>>>
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
