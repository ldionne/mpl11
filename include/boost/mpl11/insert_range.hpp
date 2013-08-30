/*!
 * @file
 * Defines `boost::mpl11::insert_range`.
 */

#ifndef BOOST_MPL11_INSERT_RANGE_HPP
#define BOOST_MPL11_INSERT_RANGE_HPP

#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
template <typename Sequence, typename Position, typename ...Range>
struct insert_range {
    static_assert(detail::always_false<Sequence, Position, Range...>::value,
    "Too many arguments to `insert_range`. "
    "Usage is `insert_range<Sequence, Position, Range>` or "
    "`insert_range<AssociativeSequence, Range>`.");

    struct type;
};

#error finish implementation

/*!
 * Inserts a range of elements at an arbitrary position in a sequence.
 *
 * The default implementation is equivalent to copying the elements
 * in the ranges [`begin<Sequence>::type`, `Position`), `Range` and
 * [`next<Position>::type`, `end<Sequence>::type`). To do so, `Sequence`
 * is first `clear` ed and then each element is  inserted using either
 * `push_back` or `push_front`, depending on the extensibility category
 * of `Sequence`.
 */
template <typename Sequence, typename Position, typename Range>
struct insert_range<Sequence, Position, Range>
    : detail::tag_dispatched<tag::insert_range, Sequence, Position, Range>
      ::template with_default<>
{ };

/*!
 * Inserts a range of elements in an associative sequence.
 *
 * The default implementation is equivalent to
 * `foldl<Range, AssociativeSequence, insert<_1, _2>>`.
 *
 * @warning
 * Differences from the original MPL:
 * - It is possible to use `insert_range` on associative sequences.
 */
template <typename AssociativeSequence, typename Range>
struct insert_range<AssociativeSequence, Range>
    : detail::tag_dispatched<tag::insert_range, AssociativeSequence, Range>
      ::template with_default<>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INSERT_RANGE_HPP
