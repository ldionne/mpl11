/*!
 * @file
 * Forward declares `boost::mpl11::transform`.
 */

#ifndef BOOST_MPL11_FWD_TRANSFORM_HPP
#define BOOST_MPL11_FWD_TRANSFORM_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup algorithms
     * @ingroup sequences
     *
     * `Sequence` containing the result of applying `F` to each element
     * of `%Sequence`.
     *
     * Additionally, `mpl11::transform` is an algorithm returning a new
     * `Container` created with the elements `mpl11::transform`. To use
     * `mpl11::transform` as an algorithm, `%Sequence` must be a `Container`.
     */
    template <typename Sequence, typename F>
    struct transform;

    template <typename Sequence, typename F>
    using transform_t = typename transform<Sequence, F>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_TRANSFORM_HPP
