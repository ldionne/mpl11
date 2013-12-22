/*!
 * @file
 * Forward declares `boost::mpl11::join`.
 */

#ifndef BOOST_MPL11_FWD_JOIN_HPP
#define BOOST_MPL11_FWD_JOIN_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup algorithms
     * @ingroup sequences
     *
     * `Sequence` containing the elements of two or more
     * concatenated `Sequence`s.
     *
     * Additionally, `mpl11::join` is an algorithm returning a new `Container`
     * created with the elements of `mpl11::join`. To use `mpl11::join` as an
     * algorithm, `Sequence1` must be a `Container`.
     *
     *
     * @todo
     * Take advantage of knowing the length of the underlying sequence in
     * O(1) in the join_iterator.
     *
     * @todo
     * Take advantage of possible fast sum in the implementation of size<>.
     *
     * @todo
     * Fix the fact that a join_iterator and a random type will compare
     * unequal instead of failing. Also, make sure two join iterators can
     * be compared like equal<X, Y> or equal<Y, X>, which is not the case
     * right now. This issue is also related to multiple dispatch.
     */
    template <typename Sequence1, typename Sequence2, typename ...SequenceN>
    struct join;

    template <typename Sequence1, typename Sequence2, typename ...SequenceN>
    using join_t = typename join<Sequence1, Sequence2, SequenceN...>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_JOIN_HPP
