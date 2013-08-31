/*!
 * @file
 * Defines `boost::mpl11::insert_range`.
 */

#ifndef BOOST_MPL11_INSERT_RANGE_HPP
#define BOOST_MPL11_INSERT_RANGE_HPP

#include <boost/mpl11/arg.hpp>
#include <boost/mpl11/begin.hpp>
#include <boost/mpl11/clear.hpp>
#include <boost/mpl11/copy.hpp>
#include <boost/mpl11/detail/doxygen_only.hpp>
#include <boost/mpl11/detail/optional.hpp>
#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/end.hpp>
#include <boost/mpl11/foldl.hpp>
#include <boost/mpl11/insert.hpp>
#include <boost/mpl11/is_same.hpp>
#include <boost/mpl11/lambda.hpp>
#include <boost/mpl11/next.hpp>
#include <boost/mpl11/tags.hpp>
#include <boost/mpl11/view/bounded_by.hpp>
#include <boost/mpl11/view/joined.hpp>


namespace boost { namespace mpl11 {
template <typename Sequence, typename PositionOrRange,
          typename RangeOrNothing = detail::optional>
struct insert_range;

namespace insert_range_detail {
template <typename Sequence, typename Position, typename Range,
          bool = is_same<Position, typename end<Sequence>::type>::value>
struct copy_insert
    : copy<
        view::joined<Sequence, Range>,
        typename clear<Sequence>::type
    >
{ };

template <typename Sequence, typename Position, typename Range>
struct copy_insert<Sequence, Position, Range, false>
    : copy<
        view::joined<
            view::bounded_by<
                typename begin<Sequence>::type, Position
            >,
            Range,
            view::bounded_by<
                typename next<Position>::type, typename end<Sequence>::type
            >
        >,
        typename clear<Sequence>::type
    >
{ };

template <typename Sequence, typename Position, typename Range>
struct insert_range_impl
    : copy_insert<Sequence, Position, Range>
{ };
} // end namespace insert_range_detail

/*!
 * Inserts a range of elements at an arbitrary position in a sequence.
 *
 * The default implementation is equivalent to copying the elements
 * in the ranges [`begin<Sequence>::type`, `Position`), `Range` and
 * [`next<Position>::type`, `end<Sequence>::type`).
 */
template <typename Sequence, typename Position, typename Range>
struct insert_range BOOST_MPL11_DOXYGEN_ONLY(<Sequence, Position, Range>)
    : detail::tag_dispatched<tag::insert_range, Sequence, Position, Range>
      ::template with_default<
        insert_range_detail::insert_range_impl<_1, _2, _3>
      >
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
      ::template with_default<
        foldl<_2, _1, typename lambda<insert<_1, _2>>::type>
      >
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INSERT_RANGE_HPP
