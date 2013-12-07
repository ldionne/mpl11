/*!
 * @file
 * Forward declares `boost::mpl11::zip`.
 */

#ifndef BOOST_MPL11_FWD_ZIP_HPP
#define BOOST_MPL11_FWD_ZIP_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup algorithms
     * @ingroup sequences
     *
     * `Sequence` containing the transpose of two or more `Sequence`s.
     *
     * Specifically, each element of `mpl11::zip` is a `Sequence` containing
     * the elements of each zipped sequence at that position. The number of
     * elements in `mpl11::zip` is equal to the number of elements of the
     * smallest zipped sequence.
     *
     * Additionally, `mpl11::zip` is an algorithm returning a new `Container`
     * created with the elements of `mpl11::zip`. To use `mpl11::zip` as an
     * algorithm, `Sequence1` must be a `Container`.
     *
     *
     * @todo
     * Consider optimizing `mpl11::unpack`. The gain, if any, isn't obvious.
     */
    template <typename Sequence1, typename Sequence2, typename ...SequenceN>
    struct zip;

    template <typename Sequence1, typename Sequence2, typename ...SequenceN>
    using zip_t = typename zip<Sequence1, Sequence2, SequenceN...>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_ZIP_HPP
