/*!
 * @file
 * Forward declares `boost::mpl11::transform`.
 */

#ifndef BOOST_MPL11_FWD_TRANSFORM_HPP
#define BOOST_MPL11_FWD_TRANSFORM_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup metafunctions
     *
     * Returns the result of applying `F` to each element of a sequence.
     *
     *
     * @todo
     * Consider allowing several sequences as arguments. What semantics
     * should that have? Transform each sequence or transform the zip
     * of all the sequences?
     */
    template <typename F, typename Sequence>
    struct transform;

    template <typename F, typename Sequence>
    using transform_t = transform<F, Sequence>;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_TRANSFORM_HPP
