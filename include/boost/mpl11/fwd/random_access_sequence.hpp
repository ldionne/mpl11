/*!
 * @file
 * Forward declares `boost::mpl11::RandomAccessSequence`.
 */

#ifndef BOOST_MPL11_FWD_RANDOM_ACCESS_SEQUENCE_HPP
#define BOOST_MPL11_FWD_RANDOM_ACCESS_SEQUENCE_HPP

#include <boost/mpl11/fwd/bidirectional_sequence.hpp>
#include <boost/mpl11/fwd/forward_sequence.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup concepts
     *
     * `BidirectionalSequence` whose iterators model the
     * `RandomAccessIterator` concept.
     *
     *
     * ## Refinement of
     * `BidirectionalSequence`
     *
     *
     * ## Notation
     * | Expression | Description
     * | ---------- | -----------
     * | `S`        | A `RandomAccessSequence`
     * | `N`        | An `Integral`
     *
     *
     * ## Valid expressions
     * | Expression              | Type
     * | ----------              | ----
     * | `mpl11::begin<S>::type` | `RandomAccessIterator`
     * | `mpl11::end<S>::type`   | `RandomAccessIterator`
     * | `mpl11::at<S, N>::type` | Any type
     */
    struct RandomAccessSequence : BidirectionalSequence {
        /*!
         * Advances `begin<%Sequence>::type` `N` positions
         * and dereferences it.
         */
        template <typename Sequence, typename N>
        struct at_impl;
    };

    /*!
     * @ingroup concepts
     *
     * Collection of types providing efficient access to elements
     * anywhere in the sequence.
     *
     *
     * ## Refinement of
     * `ForwardSequence`
     *
     * ## Intrinsics
     * - `mpl11::at`
     * - `mpl11::slice`
     *
     * The minimal complete definition for `RandomAccessSequence` is all
     * of the intrinsics, plus the minimal complete definition for
     * `ForwardSequence`.
     */
    struct RandomAccessSequence2 : ForwardSequence {
#ifdef BOOST_MPL11_DOXYGEN_INVOKED
        template <typename S, typename Index>
        struct at_impl;

        template <typename S, typename Start, typename Stop>
        struct slice_impl;
#endif
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_RANDOM_ACCESS_SEQUENCE_HPP
