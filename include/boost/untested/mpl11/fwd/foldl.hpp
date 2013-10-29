/*!
 * @file
 * Forward declares `boost::mpl11::foldl`.
 */

#ifndef BOOST_MPL11_FWD_FOLDL_HPP
#define BOOST_MPL11_FWD_FOLDL_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup algorithms
     *
     * Accumulates the elements of a sequence from an initial state using a
     * custom operation.
     *
     * Specifically, returns the result of the successive application of the
     * binary operation `F` to the result of the previous `F` invocation (or
     * `State` for the first application) and every element of the sequence
     * in order.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to
       @code
            using Iter1 = begin<Sequence>::type;
            using State1 = apply<F, State, deref<Iter1>::type>::type;

            using Iter2 = next<Iter1>::type;
            using State2 = apply<F, State1, deref<Iter2>::type>::type;

            ...

            using StateN = apply<F, StateN-1, deref<IterN>::type>::type;
            using Last = next<IterN>::type;
            using Result = StateN;
       @endcode
     *
     *
     * @note
     * This is equivalent to the `mpl::fold` metafunction from the
     * original MPL.
     */
    template <typename Sequence, typename State, typename F>
    struct foldl;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_FOLDL_HPP
