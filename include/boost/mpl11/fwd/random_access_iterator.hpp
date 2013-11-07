/*!
 * @file
 * Forward declares `boost::mpl11::RandomAccessIterator`.
 */

#ifndef BOOST_MPL11_FWD_RANDOM_ACCESS_ITERATOR_HPP
#define BOOST_MPL11_FWD_RANDOM_ACCESS_ITERATOR_HPP

#include <boost/mpl11/detail/doxygen_only.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup concepts
     *
     * `BidirectionalIterator` providing constant-time guarantees on moving
     * the iterator an arbitrary number of positions.
     *
     *
     * ## Refinement of
     * `BidirectionalIterator`, `Orderable`
     *
     *
     * ## Notation
     * | Expression | Description
     * | ---------- | -----------
     * | `I`, `J`   | `RandomAccessIterator`s
     * | `N`        | An `IntegralConstant`
     *
     *
     * ## Valid expressions
     * | Expression                   | Type                   | Complexity
     * | ----------                   | ----                   | ----------
     * | `mpl11::next<I>::type`       | `RandomAccessIterator` | O(1) time
     * | `mpl11::prev<I>::type`       | `RandomAccessIterator` | O(1) time
     * | `mpl11::advance<I, N>::type` | `RandomAccessIterator` | O(1) time
     * | `mpl11::distance<I, J>`      | `IntegralConstant`     | O(1) time
     *
     *
     * ## Invariants
     * - If `advance_c<I, N::value>::type` is well-defined, then
     *   `advance_c<advance_c<I, N::value>::type, -N::value>::type`
     *   is equal to `I`.
     */
    struct RandomAccessIterator BOOST_MPL11_DOXYGEN_ONLY({ });
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_RANDOM_ACCESS_ITERATOR_HPP
