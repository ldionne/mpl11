/*!
 * @file
 * Forward declares `boost::mpl11::length`.
 */

#ifndef BOOST_MPL11_FWD_LENGTH_HPP
#define BOOST_MPL11_FWD_LENGTH_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup FiniteSequence
     * @ingroup methods
     *
     * `Integral` of unsigned type representing the number of elements in
     * a `FiniteSequence`.
     */
    template <typename S>
    struct length;

    template <typename S>
    using length_t = typename length<S>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_LENGTH_HPP
