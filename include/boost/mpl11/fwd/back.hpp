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
     * Returns the last element of a `BidirectionalSequence`.
     *
     * If there is no such element, i.e. if the sequence is empty, a
     * compile-time assertion is triggered.
     */
    template <typename Sequence>
    struct back;

    template <typename Sequence>
    using back_t = typename back<Sequence>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_BACK_HPP
