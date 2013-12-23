/*!
 * @file
 * Forward declares `boost::mpl11::transform`.
 */

#ifndef BOOST_MPL11_FWD_TRANSFORM_HPP
#define BOOST_MPL11_FWD_TRANSFORM_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup sequences
     *
     * Sequence containing the result of invoking `F` with each element of
     * another sequence.
     *
     * Specifically, the i-th element of `transform<F, S>` is the result of
     * invoking `F` with the i-th element of `S`.
     *
     * The sequence operations supported by `transform` are exactly those of
     * the underlying sequence.
     *
     *
     * @todo
     * Consider allowing several sequences as arguments. What semantics
     * should that have? Transform each sequence or transform the zip
     * of all the sequences?
     *
     * @todo
     * Use minimal sequences in the unit tests.
     */
    template <typename F, typename Sequence>
    struct transform;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_TRANSFORM_HPP
