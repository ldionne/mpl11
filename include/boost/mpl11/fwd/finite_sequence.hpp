/*!
 * @file
 * Forward declares `boost::mpl11::FiniteSequence`.
 */

#ifndef BOOST_MPL11_FWD_FINITE_SEQUENCE_HPP
#define BOOST_MPL11_FWD_FINITE_SEQUENCE_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup typeclasses
     * @defgroup FiniteSequence FiniteSequence
     *
     * Sequence containing a finite number of elements.
     *
     *
     * ### Refines
     * `ForwardSequence`
     *
     * ### Methods
     * `unpack`, `length`
     *
     * ### Minimal complete definition
     * Nothing; everything is provided using the methods of `ForwardSequence`.
     *
     * @{
     */
    template <typename Tag>
    struct FiniteSequence;

    /*!
     * `Integral` of unsigned type representing the number of elements in
     * a `FiniteSequence`.
     */
    template <typename S>
    struct length;

    template <typename S>
    using length_t = typename length<S>::type;

    /*!
     * Invokes a metafunction class with the contents of a `FiniteSequence`.
     *
     * Specifically, `unpack<S, F>` is a nullary metafunction equivalent
     * to `apply<F, a0, ..., an>`, where `a0`, ...,`an` are the elements
     * in the sequence.
     */
    template <typename S, typename F>
    struct unpack;

    template <typename S, typename F>
    using unpack_t = typename unpack<S, F>::type;

    //! @}
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_FINITE_SEQUENCE_HPP
