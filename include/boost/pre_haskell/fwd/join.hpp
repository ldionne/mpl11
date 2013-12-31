/*!
 * @file
 * Forward declares `boost::mpl11::join`.
 */

#ifndef BOOST_MPL11_FWD_JOIN_HPP
#define BOOST_MPL11_FWD_JOIN_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup sequences
     *
     * Sequence containing the elements of two or more concatenated sequences.
     *
     * The sequence operations supported by `join` is the intersection of the
     * sequence operations supported by the joined sequences. However, in
     * order for `join` to be a `RandomAccessSequence`, all the sequences must
     * also be `FiniteSequence`s.
     *
     *
     * @todo
     * Consider allowing 0 or 1 sequence to be joined.
     *
     * @todo
     * Consider creating a similar sequence that takes a sequence of
     * sequences.
     *
     * @todo
     * Use folds instead of hand-crafted recursion in the implementation.
     */
    template <typename Sequence1, typename Sequence2, typename ...SequenceN>
    struct join;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_JOIN_HPP
