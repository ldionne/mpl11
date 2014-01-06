/*!
 * @file
 * Forward declares `boost::mpl11::AssociativeSequence`.
 */

#ifndef BOOST_MPL11_FWD_ASSOCIATIVE_SEQUENCE_HPP
#define BOOST_MPL11_FWD_ASSOCIATIVE_SEQUENCE_HPP

#include <boost/mpl11/fwd/comparable.hpp>
#include <boost/mpl11/fwd/sequence.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup concepts
     *
     * `Sequence` allowing retrieval of elements based on keys.
     *
     *
     * ## Refinement of
     * `Sequence`, `Comparable`
     *
     *
     * ## Notation
     * | Expression | Description
     * | ---------- | -----------
     * | `S`        | An `AssociativeSequence`
     * | `Element`  | An element of `S`
     * | `Key`      | Any type
     * | `Default`  | Any type
     *
     *
     * ## Valid expressions
     * | Expression                      | Type
     * | ----------                      | ----
     * | `key_of<S, Element>::type`      | Any type
     * | `value_of<S, Element>::type`    | Any type
     * | `at_key<S, Key>::type`          | Any type
     * | `at_key<S, Key, Default>::type` | Any type
     * | `has_key<S, Key>`               | Boolean `Integral`
     */
    struct AssociativeSequence : Sequence, Comparable {
#ifdef BOOST_MPL11_DOXYGEN_INVOKED
        //! This operation must be provided by the user.
        template <typename Sequence, typename Key>
        struct at_key_impl;

        //! This operation must be provided by the user.
        template <typename Sequence, typename Key, typename Default>
        struct at_key_def_impl;

        //! This operation must be provided by the user.
        template <typename Sequence, typename Key>
        struct has_key_impl;

        //! This operation must be provided by the user.
        template <typename Sequence, typename Element>
        struct key_of_impl;

        //! This operation must be provided by the user.
        template <typename Sequence, typename Element>
        struct value_of_impl;
#endif
    };

    /*!
     * @ingroup sequence_intrinsics
     *
     * Returns the value associated with the given `Key` in an
     * `AssociativeSequence`.
     *
     * If the sequence does not contain a key `Key` and a `Default` is
     * provided, `Default::type` is returned. Otherwise, a compile-time
     * assertion is triggered.
     *
     *
     * @note
     * When a `Default` is provided, this intrinsic is dispatched to
     * `at_key_def_impl`. Otherwise, it is dispatched in the standard
     * way, to `at_key_impl`.
     */
    template <
        typename Sequence,
        typename Key,
        typename Default = detail::optional
    >
    struct at_key;

    template <
        typename Sequence,
        typename Key,
        typename Default = detail::optional
    >
    using at_key_t = typename at_key<Sequence, Key, Default>::type;

    /*!
     * @ingroup sequence_intrinsics
     *
     * Returns whether an `AssociativeSequence` contains one or more
     * elements with key `Key`.
     */
    template <typename Sequence, typename Key>
    struct has_key;

    template <typename Sequence, typename Key>
    using has_key_t = typename has_key<Sequence, Key>::type;

    /*!
     * @ingroup sequence_intrinsics
     *
     * Returns the value that _would_ be used for an element
     * in an `AssociativeSequence`.
     */
    template <typename Sequence, typename Element>
    struct value_of;

    template <typename Sequence, typename Element>
    using value_of_t = typename value_of<Sequence, Element>::type;

    /*!
     * @ingroup sequence_intrinsics
     *
     * Returns the key that _would_ be used for an element
     * in an `AssociativeSequence`.
     */
    template <typename Sequence, typename Element>
    struct key_of;

    template <typename Sequence, typename Element>
    using key_of_t = typename key_of<Sequence, Element>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_ASSOCIATIVE_SEQUENCE_HPP
