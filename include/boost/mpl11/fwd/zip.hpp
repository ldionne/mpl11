/*!
 * @file
 * Forward declares `boost::mpl11::zip`.
 */

#ifndef BOOST_MPL11_FWD_ZIP_HPP
#define BOOST_MPL11_FWD_ZIP_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup metafunctions
     *
     * Returns a sequence that aggregates elements from two or more sequences.
     *
     * Specifically, the i-th element of the sequence is a `list` containing
     * the i-th element of each zipped sequence. The sequence stops when the
     * shortest zipped sequence is exhausted.
     *
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
     */
    template <typename Sequence1, typename Sequence2, typename ...SequenceN>
    struct zip;

    template <typename Sequence1, typename Sequence2, typename ...SequenceN>
    using zip_t = typename zip<Sequence1, Sequence2, SequenceN...>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_ZIP_HPP
