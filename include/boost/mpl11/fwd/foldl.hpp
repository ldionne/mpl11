/*!
 * @file
 * Forward declares `boost::mpl11::foldl`.
 */

#ifndef BOOST_MPL11_FWD_FOLDL_HPP
#define BOOST_MPL11_FWD_FOLDL_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup metafunctions
     *
     * Reduces a sequence using a binary operation, from left to right.
     *
     * Specifically, returns the result of the successive application of the
     * binary operation `F` to the result of the previous `F` invocation (or
     * `State` for the first application) and every element of the sequence
     * in order.
     *
     * Visually, with `Sequence = x1, x2, ..., xn`:
     *
            foldl(F, State, Sequence) == F(...F(F(State, x1), x2)..., xn)
     *
     *
     * @note
     * This is equivalent to the `fold` metafunction from the original MPL.
     * However, the order of the arguments has changed.
     */
    template <typename F, typename State, typename Sequence>
    struct foldl;

    template <typename F, typename State, typename Sequence>
    using foldl_t = typename foldl<F, State, Sequence>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_FOLDL_HPP
