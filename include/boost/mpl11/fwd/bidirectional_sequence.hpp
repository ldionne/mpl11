/*!
 * @file
 * Forward declares `boost::mpl11::BidirectionalSequence`.
 */

#ifndef BOOST_MPL11_FWD_BIDIRECTIONAL_SEQUENCE_HPP
#define BOOST_MPL11_FWD_BIDIRECTIONAL_SEQUENCE_HPP

#include <boost/mpl11/fwd/directional_sequence.hpp>
#include <boost/mpl11/fwd/forward_sequence.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup concepts
     *
     * `DirectionalSequence` whose elements can be traversed in reverse order.
     *
     *
     * ## Refinement of
     * `DirectionalSequence`
     *
     *
     * ## Notation
     * | Expression | Description
     * | ---------- | -----------
     * | `S`        | A `BidirectionalSequence`
     *
     *
     * ## Valid expressions
     * | Expression       | %Type
     * | ----------       | -----
     * | `begin<S>::type` | `BidirectionalIterator`
     * | `end<S>::type`   | `BidirectionalIterator`
     * | `back<S>::type`  | Any type
     */
    struct BidirectionalSequence : DirectionalSequence {
        /*!
         * Returns
         *
            mpl11::deref<
                mpl11::prev<
                    mpl11::end<Sequence>::type
                >::type
            >::type
         *
         * if `is_empty<%Sequence>::value` is `false`, and triggers a static
         * assertion otherwise.
         */
        template <typename Sequence>
        struct back_impl;
    };

    /*!
     * @ingroup concepts
     *
     * Collection of types that can be traversed in both directions.
     *
     *
     * ## Refinement of
     * `ForwardSequence`
     *
     * ## Intrinsics
     * - `mpl11::last`
     * - `mpl11::init`
     *
     * The minimal complete definition for `BidirectionalSequence` is all of
     * the intrinsics, plus the minimal complete definition for
     * `ForwardSequence`.
     */
    struct BidirectionalSequence2 : ForwardSequence {
#ifdef BOOST_MPL11_DOXYGEN_INVOKED
        template <typename S>
        struct last_impl;

        template <typename S>
        struct init_impl;
#endif
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_BIDIRECTIONAL_SEQUENCE_HPP
