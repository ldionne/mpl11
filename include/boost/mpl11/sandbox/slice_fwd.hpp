/*!
 * @file
 * Forward declares `boost::mpl11::slice`.
 */

#ifndef BOOST_MPL11_FWD_SLICE_HPP
#define BOOST_MPL11_FWD_SLICE_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup algorithms
     * @ingroup sequences
     *
     * `Sequence` containing the elements of a `%Sequence` in the range
     * delimited by [`First`, `Last`).
     *
     * Additionally, `mpl11::slice` is an algorithm returning a new
     * `Container` containing the elements of `%Sequence` in the range
     * delimited by [`First`, `Last`). To use `mpl11::slice` as an algorithm,
     * `%Sequence` must be a `Container`.
     */
    template <typename Sequence, typename First, typename Last>
    struct slice;

    template <typename Sequence, typename First, typename Last>
    using slice_t = typename slice<Sequence, First, Last>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_SLICE_HPP
