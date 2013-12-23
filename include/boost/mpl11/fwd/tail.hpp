/*!
 * @file
 * Forward declares `boost::mpl11::tail`.
 */

#ifndef BOOST_MPL11_FWD_TAIL_HPP
#define BOOST_MPL11_FWD_TAIL_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup sequence_intrinsics
     *
     * Extract the elements after the head of a non-empty `ForwardSequence`.
     *
     * Specifically, returns a concept-identical sequence containing all the
     * elements of the original sequence except the first one. A static
     * assertion is triggered if the sequence is empty.
     */
    template <typename S>
    struct tail;

    template <typename S>
    using tail_t = typename tail<S>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_TAIL_HPP
