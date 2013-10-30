/*!
 * @file
 * Forward declares `boost::mpl11::back`.
 */

#ifndef BOOST_MPL11_FWD_BACK_HPP
#define BOOST_MPL11_FWD_BACK_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup sequence_intrinsics
     *
     * Returns the last element of a `BidirectionalSequence` if there is
     * such an element, and triggers a compile-time assertion otherwise.
     */
    template <typename Seq>
    struct back;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_BACK_HPP
