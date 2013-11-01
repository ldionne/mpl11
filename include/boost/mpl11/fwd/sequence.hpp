/*!
 * @file
 * Forward declares `boost::mpl11::Sequence`.
 */

#ifndef BOOST_MPL11_FWD_SEQUENCE_HPP
#define BOOST_MPL11_FWD_SEQUENCE_HPP

#include <boost/mpl11/detail/doxygen_only.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @defgroup sequence_intrinsics Sequence intrinsics
     * @ingroup intrinsics
     *
     * Intrinsics forming the essential interface of sequences.
     */

    /*!
     * @ingroup concepts
     *
     * Collection of types that can be traversed.
     *
     *
     * ## Definitions
     * - The size of a sequence is the number of elements it contains.
     *   The size is a non-negative number.
     *
     * - A sequence is empty if its size is zero.
     *
     *
     * ## Notation
     * | Expression | Description
     * | ---------- | -----------
     * | `S`        | A `Sequence`
     *
     *
     * ## Valid expressions
     * | Expression       | Type
     * | ----------       | ----
     * | `begin<S>::type` | `ForwardIterator`
     * | `end<S>::type`   | `ForwardIterator`
     * | `size<S>`        | `IntegralConstant`
     * | `is_empty<S>`    | Boolean `IntegralConstant`
     *
     *
     * ## Invariants
     * - [`begin<S>::type`, `end<S>::type`) is always a valid range.
     *
     * - An algorithm that iterates through the range
     *   [`begin<S>::type`, `end<S>::type`) will pass
     *   through every element of `S` exactly once.
     *
     * - `begin<S>::type` is equal to `end<S>::type` if and only if `S`
     *   is empty.
     *
     * - Two different iterations through `S` will access its elements
     *   in the same order.
     */
    struct Sequence BOOST_MPL11_DOXYGEN_ONLY({ });
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_SEQUENCE_HPP
