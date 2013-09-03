/*!
 * @file
 * Defines `boost::mpl11::intrinsic::insert_range`.
 */

#ifndef BOOST_MPL11_INTRINSIC_INSERT_RANGE_HPP
#define BOOST_MPL11_INTRINSIC_INSERT_RANGE_HPP

#include <boost/mpl11/algorithm/copy.hpp>
#include <boost/mpl11/algorithm/foldl.hpp>
#include <boost/mpl11/detail/doxygen_only.hpp>
#include <boost/mpl11/detail/forward_decls.hpp>
#include <boost/mpl11/detail/optional.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/intrinsic/begin.hpp>
#include <boost/mpl11/intrinsic/clear.hpp>
#include <boost/mpl11/intrinsic/end.hpp>
#include <boost/mpl11/intrinsic/equal_to.hpp>
#include <boost/mpl11/intrinsic/insert.hpp>
#include <boost/mpl11/quote.hpp>
#include <boost/mpl11/tags.hpp>
#include <boost/mpl11/view/bounded_by.hpp>
#include <boost/mpl11/view/joined.hpp>


namespace boost { namespace mpl11 {
namespace intrinsic {
    /*!
     * @ingroup intrinsic
     *
     * Overloaded intrinsic for inserting a range of elements in a sequence.
     */
    template <typename SequenceOrAssociativeSequence,
              typename PositionOrRange,
              typename RangeOrNothing = detail::optional>
    struct insert_range;

    /*!
     * @ingroup intrinsic
     *
     * Inserts a range of elements at an arbitrary position in a sequence.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to copying the elements from the ranges
     * [`begin<Sequence>::type`, `Position`), `Range` and
     * [`Position`, `end<Sequence>::type`) into `clear<Sequence>::type`
     */
    template <typename Sequence, typename Position, typename Range>
    struct insert_range BOOST_MPL11_DOXYGEN_ONLY(<Sequence, Position, Range>)
        : dispatch<tag::insert_range, Sequence, Position, Range>
    { };

    /*!
     * @ingroup intrinsic
     *
     * Inserts a range of elements in an `AssociativeSequence`.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to `foldl<Range, Sequence, insert<_1, _2>>`.
     *
     *
     * @warning
     * Differences from the original MPL:
     * - It is possible to use `insert_range` on `AssociativeSequence`s.
     */
    template <typename Sequence, typename Range>
    struct insert_range<Sequence, Range>
        : dispatch<tag::insert_range, Sequence, Range>
    { };
} // end namespace intrinsic

namespace insert_range_detail {
    template <typename Sequence, typename Position, typename Range,
              bool = intrinsic::equal_to<
                Position, typename intrinsic::end<Sequence>::type
              >::type::value>
    struct insert_range_impl
        : algorithm::copy<
            view::joined<Sequence, Range>,
            typename intrinsic::clear<Sequence>::type
        >
    { };

    template <typename Sequence, typename Position, typename Range>
    struct insert_range_impl<Sequence, Position, Range, false>
        : algorithm::copy<
            view::joined<
                view::bounded_by<
                    typename intrinsic::begin<Sequence>::type, Position
                >,
                Range,
                view::bounded_by<
                    Position, typename intrinsic::end<Sequence>::type
                >
            >,
            typename intrinsic::clear<Sequence>::type
        >
    { };
} // end namespace insert_range_detail

template <typename Sequence, typename Range>
struct dispatch<detail::default_<tag::insert_range>, Sequence, Range>
    : algorithm::foldl<Range, Sequence, quote<intrinsic::insert>>
{ };

template <typename Sequence, typename Position, typename Range>
struct dispatch<detail::default_<tag::insert_range>, Sequence, Position, Range>
    : insert_range_detail::insert_range_impl<Sequence, Position, Range>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INTRINSIC_INSERT_RANGE_HPP
