/*!
 * @file
 * Forward declares `boost::mpl11::init`.
 */

#ifndef BOOST_MPL11_FWD_INIT_HPP
#define BOOST_MPL11_FWD_INIT_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup sequence_intrinsics
     *
     * Extract the elements of a non-empty `BidirectionalSequence` before
     * the last.
     *
     * Specifically, returns a concept-identical sequence containing all the
     * elements of the original sequence except the last one. A static
     * assertion is triggered if the sequence is empty.
     */
    template <typename S>
    struct init;

    template <typename S>
    using init_t = typename init<S>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_INIT_HPP
