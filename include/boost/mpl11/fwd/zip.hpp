/*!
 * @file
 * Forward declares `boost::mpl11::zip`.
 */

#ifndef BOOST_MPL11_FWD_ZIP_HPP
#define BOOST_MPL11_FWD_ZIP_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup sequences
     *
     * Sequence aggregating elements from two or more sequences.
     *
     * Specifically, the i-th element of `zip` is a `RandomAccessSequence`
     * containing the i-th element of each zipped sequence. The `zip`
     * sequence stops when the shortest zipped sequence is exhausted.
     * Therefore, the length of `zip` is that of the shortest zipped sequence.
     *
     * The sequence operations supported by `zip` is the intersection of the
     * sequence operations supported by all the zipped sequences.
     *
     *
     * @warning
     * `zip` is never a `BidirectionalSequence`; this has to be implemented.
     *
     * @todo
     * Implement `BidirectionalSequence` for `zip`. This is less trivial
     * than it seems because we have to deal with infinite sequences
     * and other stuff in the `last` method.
     *
     * @todo
     * Consider implementing a `zip_longest` with the obvious semantics.
     *
     * @todo
     * Should we allow 0 and 1 sequences to be zipped?
     *
     * @todo
     * Consider implementing a custom `unpack`. Is it possible to be more
     * clever than the default implementation?
     *
     * @todo
     * Use minimal sequences in the unit test.
     */
    template <typename Sequence1, typename Sequence2, typename ...SequenceN>
    struct zip;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_ZIP_HPP
