/*!
 * @file
 * Forward declares `boost::mpl11::unpack`.
 */

#ifndef BOOST_MPL11_FWD_UNPACK_HPP
#define BOOST_MPL11_FWD_UNPACK_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup FiniteSequence
     * @ingroup methods
     *
     * Invokes a `MetafunctionClass` with the contents of a `FiniteSequence`.
     *
     * Specifically, `unpack<S, F>` is a nullary `Metafunction` equivalent
     * to `apply<F, a0, ..., an>`, where `a0`, ...,`an` are the elements
     * in the sequence.
     */
    template <typename S, typename F>
    struct unpack;

    template <typename S, typename F>
    using unpack_t = typename unpack<S, F>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_UNPACK_HPP
