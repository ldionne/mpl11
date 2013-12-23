/*!
 * @file
 * Forward declares `boost::mpl11::FiniteSequence`.
 */

#ifndef BOOST_MPL11_FWD_FINITE_SEQUENCE_HPP
#define BOOST_MPL11_FWD_FINITE_SEQUENCE_HPP

#include <boost/mpl11/fwd/forward_sequence.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup concepts
     *
     * Sequence containing a finite number of elements.
     *
     *
     * ## Refinement of
     * `ForwardSequence`
     *
     * ## Intrinsics
     * - `mpl11::unpack`
     * - `mpl11::length`
     *
     * The minimal complete definition for `FiniteSequence` is that of
     * `ForwardSequence`, i.e. `FiniteSequence` does not require anything
     * to be implemented except what is required by `ForwardSequence`.
     */
    struct FiniteSequence : ForwardSequence {
        template <typename S>
        struct length_impl;

        template <typename S, typename F>
        struct unpack_impl;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_FINITE_SEQUENCE_HPP
