/*!
 * @file
 * Defines `boost::mpl11::intrinsic::insert_range`.
 */

#ifndef BOOST_MPL11_INTRINSIC_INSERT_RANGE_HPP
#define BOOST_MPL11_INTRINSIC_INSERT_RANGE_HPP

#include <boost/mpl11/algorithm/copy.hpp>
#include <boost/mpl11/algorithm/foldl.hpp>
#include <boost/mpl11/always.hpp>
#include <boost/mpl11/arg.hpp>
#include <boost/mpl11/detail/doxygen_only.hpp>
#include <boost/mpl11/detail/optional.hpp>
#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/intrinsic/begin.hpp>
#include <boost/mpl11/intrinsic/clear.hpp>
#include <boost/mpl11/intrinsic/end.hpp>
#include <boost/mpl11/intrinsic/equal_to.hpp>
#include <boost/mpl11/intrinsic/insert.hpp>
#include <boost/mpl11/intrinsic/next.hpp>
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
                    typename intrinsic::next<Position>::type,
                    typename intrinsic::end<Sequence>::type
                >
            >,
            typename intrinsic::clear<Sequence>::type
        >
    { };
} // end namespace insert_range_detail

namespace intrinsic {
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
     * [`next<Position>::type`, `end<Sequence>::type`) into
     * `clear<Sequence>::type`
     */
    template <typename Sequence, typename Position, typename Range>
    struct insert_range BOOST_MPL11_DOXYGEN_ONLY(<Sequence, Position, Range>)
        : detail::tag_dispatched<tag::insert_range, Sequence, Position, Range>
          ::template with_default<
            lazy_always<
                insert_range_detail::insert_range_impl<
                    Sequence, Position, Range
                >
            >
          >
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
        : detail::tag_dispatched<tag::insert_range, Sequence, Range>
          ::template with_default<
            lazy_always<
                algorithm::foldl<Range, Sequence, insert<_1, _2>>
            >
          >
    { };
} // end namespace intrinsic
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INTRINSIC_INSERT_RANGE_HPP
