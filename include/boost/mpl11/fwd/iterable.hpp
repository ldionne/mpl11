/*!
 * @file
 * Forward declares `boost::mpl11::Iterable`.
 */

#ifndef BOOST_MPL11_FWD_ITERABLE_HPP
#define BOOST_MPL11_FWD_ITERABLE_HPP

#include <boost/mpl11/detail/doxygen_only.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @defgroup iterable_intrinsics Iterable intrinsics
     * @ingroup intrinsics
     *
     * Intrinsics forming the essential interface of `Iterable`s.
     */

    /*!
     * @ingroup mixins
     *
     * Collection of types that can be traversed.
     *
     * An `Iterable` guarantees that its elements are arranged in a definite,
     * but possibly unspecified and not meaningful order.
     *
     *
     * ## Definitions
     * - The size of an iterable is the number of elements it contains.
     *   The size is a non-negative number.
     *
     * - An iterable is empty if its size is zero.
     *
     *
     * ## Notation
     * | Expression | Description
     * | ---------- | -----------
     * | `I`        | An `Iterable`
     *
     *
     * ## Valid expressions
     * | Expression       | Type
     * | ----------       | ----
     * | `begin<I>::type` | `ForwardIterator`
     * | `end<I>::type`   | `ForwardIterator`
     * | `size<I>`        | `IntegralConstant`
     * | `is_empty<I>`    | Boolean `IntegralConstant`
     *
     *
     * ## Invariants
     * - [`begin<I>::type`, `end<I>::type`) is always a valid range.
     *
     * - An algorithm that iterates through the range
     *   [`begin<I>::type`, `end<I>::type`) will pass
     *   through every element of `I` exactly once.
     *
     * - `begin<I>::type` is equal to `end<I>::type` if and only if `I`
     *   is empty.
     *
     * - Two different iterations through `I` will access its elements
     *   in the same order.
     */
    struct Iterable BOOST_MPL11_DOXYGEN_ONLY({ });
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_ITERABLE_HPP
