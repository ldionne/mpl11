/*!
 * @file
 * Forward declares `boost::mpl11::DirectionalSequence`.
 */

#ifndef BOOST_MPL11_FWD_DIRECTIONAL_SEQUENCE_HPP
#define BOOST_MPL11_FWD_DIRECTIONAL_SEQUENCE_HPP

#include <boost/mpl11/fwd/comparable.hpp>
#include <boost/mpl11/fwd/orderable.hpp>
#include <boost/mpl11/fwd/sequence.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup concepts
     *
     * `Sequence` whose elements are traversed in a definite order.
     *
     *
     * ## Refinement of
     * `Sequence`, `Comparable`, `Orderable`
     *
     *
     * ## Notation
     * | Expression | Description
     * | ---------- | -----------
     * | `S`        | A `DirectionalSequence`
     *
     *
     * ## Valid expressions
     * | Expression       | %Type
     * | ----------       | ----
     * | `front<S>::type` | Any type
     */
    struct DirectionalSequence : Sequence, Comparable, Orderable {
        /*!
         * Returns `mpl11::deref<mpl11::begin<%Sequence>::type>::type` if
         * `is_empty<%Sequence>::value` is `false`, and triggers a static
         * assertion otherwise.
         */
        template <typename Sequence>
        struct front_impl;

        //! Performs an element-wise comparison of the two sequences.
        template <typename Sequence1, typename Sequence2>
        struct equal_impl;

        //! Performs a lexicographical comparison of the two sequences.
        template <typename Sequence1, typename Sequence2>
        struct less_impl;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_DIRECTIONAL_SEQUENCE_HPP
