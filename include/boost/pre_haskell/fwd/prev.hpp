/*!
 * @file
 * Forward declares `boost::mpl11::prev`.
 */

#ifndef BOOST_MPL11_FWD_PREV_HPP
#define BOOST_MPL11_FWD_PREV_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup iterator_intrinsics
     *
     * Returns an iterator to the previous element in the sequence.
     */
    template <typename Iterator>
    struct prev;

    template <typename Iterator>
    using prev_t = typename prev<Iterator>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_PREV_HPP
