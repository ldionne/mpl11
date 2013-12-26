/*!
 * @file
 * Forward declares `boost::mpl11::tail`.
 */

#ifndef BOOST_MPL11_FWD_TAIL_HPP
#define BOOST_MPL11_FWD_TAIL_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup ForwardSequence
     * @ingroup methods
     *
     * Extract the elements after the head of a non-empty `ForwardSequence`.
     *
     * Specifically, returns a concept-identical sequence containing all the
     * elements of the original sequence except the first one.
     */
    template <typename S>
    struct tail;

    template <typename S>
    using tail_t = typename tail<S>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_TAIL_HPP
