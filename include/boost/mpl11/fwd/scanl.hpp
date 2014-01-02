/*!
 * @file
 * Forward declares `boost::mpl11::scanl`.
 */

#ifndef BOOST_MPL11_FWD_SCANL_HPP
#define BOOST_MPL11_FWD_SCANL_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup datatypes
     *
     * Sequence containing successive reduced values from `foldl`.
     *
     * `scanl` is a `RandomAccessSequence` and a `BidirectionalSequence`.
     * If the underlying sequence is finite, then `scanl` is a
     * `FiniteSequence` too.
     */
    template <typename F, typename State, typename Sequence>
    struct scanl;

    template <typename F, typename State, typename Sequence>
    using scanl_t = scanl<F, State, Sequence>;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_SCANL_HPP
