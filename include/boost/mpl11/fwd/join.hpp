/*!
 * @file
 * Forward declares `boost::mpl11::join`.
 */

#ifndef BOOST_MPL11_FWD_JOIN_HPP
#define BOOST_MPL11_FWD_JOIN_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup metafunctions
     *
     * Concatenate several sequences.
     *
     * When invoked with `0` sequences, `join` returns an empty sequence.
     * When invoked with `1` sequence, `join` returns the sequence itself.
     *
     *
     * @todo
     * Improve the implementation:
     * - Use folds instead of hand-crafted recursion in the implementation.
     * - Use a fold to implement `at_c`.
     * - Handle the infinite sequence case in `at_c`.
     * - Implement `init` in an efficient way.
     * - Improve the filtration of sequences when creating `join`.
     * - Don't reconstruct `join` in `unpack_impl`.
     */
    template <typename ...Sequences>
    struct join;

    template <typename ...Sequences>
    using join_t = typename join<Sequences...>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_JOIN_HPP
