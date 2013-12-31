/*!
 * @file
 * Forward declares `boost::mpl11::next`.
 */

#ifndef BOOST_MPL11_FWD_NEXT_HPP
#define BOOST_MPL11_FWD_NEXT_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup iterator_intrinsics
     *
     * Returns an iterator to the next element in the sequence.
     */
    template <typename Iterator>
    struct next;

    template <typename Iterator>
    using next_t = typename next<Iterator>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_NEXT_HPP
