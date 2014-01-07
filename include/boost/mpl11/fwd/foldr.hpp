/*!
 * @file
 * Forward declares `boost::mpl11::foldr`.
 */

#ifndef BOOST_MPL11_FWD_FOLDR_HPP
#define BOOST_MPL11_FWD_FOLDR_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup metafunctions
     *
     * Reduces a sequence using a binary operator, from right to left.
     *
     * Specifically, returns the result of the successive application of the
     * binary operation `F` to every element of the sequence and the result
     * of the next `F` invocation (or `State` for the last application).
     *
     * Visually, with `Sequence = x1, x2, ..., xn`:
     *
            foldr(F, State, Sequence) == F(x1, F(x2, ...F(xn, State)...))
     *
     *
     * @todo
     * Get rid of the dumb recursion in the implementation.
     */
    template <typename F, typename State, typename Sequence>
    struct foldr;

    template <typename F, typename State, typename Sequence>
    using foldr_t = typename foldr<F, State, Sequence>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_FOLDR_HPP
