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
     * containing the elements of the concatenated `Sequence`s. To use
     * `mpl11::join` as an algorithm, the first `Sequence` must be a
     * `Container`.
     */
    template <typename Sequence1, typename Sequence2, typename ...SequenceN>
    struct join;

    template <typename Sequence1, typename Sequence2, typename ...SequenceN>
    using join_t = typename join<Sequence1, Sequence2, SequenceN...>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_JOIN_HPP
