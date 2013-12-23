/*!
 * @file
 * Forward declares `boost::mpl11::length`.
 */

#ifndef BOOST_MPL11_FWD_LENGTH_HPP
#define BOOST_MPL11_FWD_LENGTH_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup sequence_intrinsics
     *
     * Returns the number of elements of a `FiniteSequence`.
     *
     * Specifically, `length<S>` is an `Integral` of unsigned type.
     * Therefore, the length is always (obviously) non-negative.
     */
    template <typename S>
    struct length;

    template <typename S>
    using length_t = typename length<S>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_LENGTH_HPP
