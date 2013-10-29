/*!
 * @file
 * Forward declares `boost::mpl11::BidirectionalIterator`.
 */

#ifndef BOOST_MPL11_FWD_BIDIRECTIONAL_ITERATOR_HPP
#define BOOST_MPL11_FWD_BIDIRECTIONAL_ITERATOR_HPP

#include <boost/mpl11/detail/doxygen_only.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup mixins
     *
     * `ForwardIterator` providing a way to obtain an iterator to the previous
     * element in the sequence.
     *
     *
     * ## Refinement of
     * `ForwardIterator`
     *
     *
     * ## Notation
     * | Expression | Description
     * | ---------- | -----------
     * | `I`        | A `BidirectionalIterator`
     * | `N`        | An `IntegralConstant`
     *
     *
     * ## Definitions
     * - `I` is decrementable if there is a "previous" iterator, that is, if
     *   the `prev<I>::type` expression is well-defined; iterators pointing
     *   to the first element of a sequence are not decrementable.
     *
     *
     * ## Valid expressions
     * | Expression            | Type
     * | ----------            | ----
     * | `next<I>::type`       | A `BidirectionalIterator`
     * | `prev<I>::type`       | A `BidirectionalIterator`
     * | `advance<I, N>::type` | A `BidirectionalIterator`
     *
     *
     * ## Invariants
     * - If `I` is incrementable, then `prev<next<I>::type>::type` is equal to
     *   `I`; similarly, if `I` is decrementable, `next<prev<I>::type>::type`
     *   is equal to `I`.
     */
    struct BidirectionalIterator BOOST_MPL11_DOXYGEN_ONLY({ });
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_BIDIRECTIONAL_ITERATOR_HPP
