/*!
 * @file
 * Forward declares `boost::mpl11::filter`.
 */

#ifndef BOOST_MPL11_FWD_FILTER_HPP
#define BOOST_MPL11_FWD_FILTER_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup sequences
     *
     * Sequence whose elements are those of another sequence for which the
     * `Predicate` returns `true`.
     *
     * The sequence operations supported by `filter` are the same as that
     * of the underlying sequence, except that `filter` is never a
     * `RandomAccessSequence`.
     *
     *
     * @todo
     * The implementation is temporary; it is very naive.
     *
     * @todo
     * Use minimal sequences in the unit tests.
     */
    template <typename Predicate, typename Sequence>
    struct filter;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_FILTER_HPP
