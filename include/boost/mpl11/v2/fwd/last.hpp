/*!
 * @file
 * Forward declares `boost::mpl11::last`.
 */

#ifndef BOOST_MPL11_FWD_LAST_HPP
#define BOOST_MPL11_FWD_LAST_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup BidirectionalSequence
     * @ingroup methods
     *
     * Returns the last element of a non-empty `BidirectionalSequence`.
     */
    template <typename S>
    struct last;

    template <typename S>
    using last_t = typename last<S>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_LAST_HPP
