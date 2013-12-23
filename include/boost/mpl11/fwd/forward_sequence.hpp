/*!
 * @file
 * Forward declares `boost::mpl11::ForwardSequence`.
 */

#ifndef BOOST_MPL11_FWD_FORWARD_SEQUENCE_HPP
#define BOOST_MPL11_FWD_FORWARD_SEQUENCE_HPP

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
     * Collection of types that can be traversed in one direction.
     *
     *
     * ## Intrinsics
     * - `mpl11::head`
     * - `mpl11::tail`
     * - `mpl11::is_empty`
     *
     * The minimal complete definition for `ForwardSequence` is all of the
     * intrinsics. No default implementation is provided for any of the
     * intrinsics introduced by the concept.
     */
    struct ForwardSequence {
        template <typename S>
        struct is_empty_impl;

        template <typename S>
        struct head_impl;

        template <typename S>
        struct tail_impl;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_FORWARD_SEQUENCE_HPP
