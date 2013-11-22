/*!
 * @file
 * Forward declares `boost::mpl11::at` and `boost::mpl::at_c`.
 */

#ifndef BOOST_MPL11_FWD_AT_HPP
#define BOOST_MPL11_FWD_AT_HPP

#include <boost/mpl11/fwd/integral_c.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup sequence_intrinsics
     *
     * Returns the element of a `RandomAccessSequence` at a given index.
     *
     * If the given index is out of bounds, a compile-time assertion
     * is triggered.
     */
    template <typename Sequence, typename N>
    struct at;

    template <typename Sequence, typename N>
    using at_t = typename at<Sequence, N>::type;

    //! @ingroup sequence_intrinsics
    //! Alias to `at<%Sequence, ulong<N>>`; provided for convenience.
    template <typename Sequence, unsigned long N>
    using at_c = at<Sequence, ulong<N>>;

    template <typename Sequence, unsigned long N>
    using at_c_t = typename at_c<Sequence, N>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_AT_HPP
