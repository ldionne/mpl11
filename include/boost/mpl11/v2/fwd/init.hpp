/*!
 * @file
 * Forward declares `boost::mpl11::init`.
 */

#ifndef BOOST_MPL11_FWD_INIT_HPP
#define BOOST_MPL11_FWD_INIT_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup BidirectionalSequence
     * @ingroup methods
     *
     * Extract the elements before the last of a non-empty
     * `BidirectionalSequence`.
     *
     * Specifically, returns a concept-identical sequence containing all the
     * elements of the original sequence except the last one.
     */
    template <typename S>
    struct init;

    template <typename S>
    using init_t = typename init<S>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_INIT_HPP
