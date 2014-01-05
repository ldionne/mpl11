/*!
 * @file
 * Forward declares `boost::mpl11::drop_while`.
 */

#ifndef BOOST_MPL11_FWD_DROP_WHILE_HPP
#define BOOST_MPL11_FWD_DROP_WHILE_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup metafunctions
     *
     * Drops elements from a sequence up to, but not including, the first
     * element for which the `Predicate` returns `false`.
     *
     * Specifically, `drop_while` returns a sequence containing all the
     * elements of the underlying sequence except for those in the range
     * delimited by [`head`, `e`), where `head` is the first element of
     * the sequence and `e` is the first element for which the `Predicate`
     * returns `false`.
     *
     * If the underlying sequence is infinite, the sequence returned by
     * `drop_while` is finite if and only if the `Predicate` always returns
     * `true`. However, since this is hard to determine without actually
     * performing the computation and should be rare anyways, the returned
     * sequence is trait-wise infinite when the underlying sequence is
     * infinite.
     *
     *
     * @todo
     * Use a less naive `consume` implementation.
     */
    template <typename Predicate, typename Sequence>
    struct drop_while;

    template <typename Predicate, typename Sequence>
    using drop_while_t = typename drop_while<Predicate, Sequence>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_DROP_WHILE_HPP
