/*!
 * @file
 * Forward declares `boost::mpl11::drop_while`.
 */

#ifndef BOOST_MPL11_FWD_DROP_WHILE_HPP
#define BOOST_MPL11_FWD_DROP_WHILE_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup sequences
     *
     * Drops elements from a sequence up to, but not including, the first
     * element for which the `Predicate` returns `false`.
     *
     * Specifically, `drop_while` is a sequence containing all the elements
     * of the underlying sequence except for those in the range delimited by
     * [`head`, `e`), where `head` is the first element of the sequence and
     * `e` is the first element for which the `Predicate` returns `false`.
     *
     * `drop_while` is always a `ForwardSequence`. It is also a
     * `FiniteSequence` if the underlying sequence is a `FiniteSequence`.
     * If the underlying sequence is not finite, the finiteness of
     * `drop_while` depends upon whether the `Predicate` will eventually
     * return `false`. Since this is not easily enforced, `drop_while` is
     * always a `FiniteSequence`, but trying to use it as such when the
     * `Predicate` always returns `true` will cause an infinite number
     * of templates to be instantiated (which might take a long time).
     *
     *
     * @todo
     * Use minimal sequences in the unit tests.
     *
     * @todo
     * Use a less naive algorithm in place of `consume` in the implementation.
     */
    template <typename Predicate, typename Sequence>
    struct drop_while;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_DROP_WHILE_HPP
