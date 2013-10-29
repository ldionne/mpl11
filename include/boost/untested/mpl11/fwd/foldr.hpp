/*!
 * @file
 * Forward declares `boost::mpl11::foldr`.
 */

#ifndef BOOST_MPL11_FWD_FOLDR_HPP
#define BOOST_MPL11_FWD_FOLDR_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup algorithms
     *
     * Accumulates the elements of a sequence from an initial state using a
     * custom operation.
     *
     * Specifically, returns the result of the successive application of the
     * binary operation `F` to the result of the next `F` invocation (or
     * `State` for the first application) and every element of the sequence
     * in order.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to the following:
     * Let `First` be the same as `begin<Sequence>::type` and  `Last`
     * the same as `end<Sequence>::type`. `foldr` is equivalent to
     * `foldr_impl<First, Last, State, F>`, where `foldr_impl` is
     * equivalent to `identity<State>` if `equal_to<First, Last>::type::value`
     * is `true` and
       @code
            apply<
                F,
                foldr_impl<next<First>::type, Last, State, F>::type,
                deref<First>::type
            >
       @endcode
     * otherwise.
     */
    template <typename Sequence, typename State, typename F>
    struct foldr;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_FOLDR_HPP
