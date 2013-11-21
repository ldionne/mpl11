/*!
 * @file
 * Forward declares `boost::mpl11::Sequence`.
 */

#ifndef BOOST_MPL11_FWD_SEQUENCE_HPP
#define BOOST_MPL11_FWD_SEQUENCE_HPP

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
     * | Expression       | %Type
     * | ----------       | -----
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
    struct Sequence {

#ifdef BOOST_MPL11_DOXYGEN_INVOKED
          //! This operation must be provided by the user.
          template <typename Sequence>
          struct begin_impl;

          //! This operation must be provided by the user.
          template <typename Sequence>
          struct end_impl;
#endif

          //! Returns the distance between both ends of the sequence.
          template <typename Sequence>
          struct size_impl;

          /*!
           * Returns whether `begin<%Sequence>::type` is equal to
           * `end<%Sequence>::type`.
           */
          template <typename Sequence>
          struct is_empty_impl;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_SEQUENCE_HPP
