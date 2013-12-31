/*!
 * @file
 * Forward declares `boost::mpl11::reverse`.
 */

#ifndef BOOST_MPL11_FWD_REVERSE_HPP
#define BOOST_MPL11_FWD_REVERSE_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup sequences
     *
     * Sequence whose elements are those of another sequence in reverse order.
     *
     * The underlying sequence `S` must always be a `BidirectionalSequence`,
     * and `reverse` is always at least a `BidirectionalSequence`. If `S`
     * is also a `FiniteSequence`, then so is `reverse`. Finally, if `S`
     * is both a `FiniteSequence` and a `RandomAccessSequence`, then so
     * is `reverse`.
     *
     *
     * @todo
     * Use minimal sequences in the unit test.
     */
    template <typename Sequence>
    struct reverse;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_REVERSE_HPP
