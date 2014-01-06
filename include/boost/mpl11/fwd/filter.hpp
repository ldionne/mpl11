/*!
 * @file
 * Forward declares `boost::mpl11::filter`.
 */

#ifndef BOOST_MPL11_FWD_FILTER_HPP
#define BOOST_MPL11_FWD_FILTER_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup metafunctions
     *
     * Returns a sequence containing those elements that satisfy the
     * given `Predicate`.
     *
     * If the underlying sequence is infinite, the sequence returned by
     * `filter` is finite if and only if the `Predicate` is `false` for
     * all elements after some element. However, since this is hard to
     * determine without actually performing the computation and should
     * be rare anyways, the returned sequence is trait-wise infinite when
     * the underlying sequence is infinite.
     */
    template <typename Predicate, typename Sequence>
    struct filter;

    template <typename Predicate, typename Sequence>
    using filter_t = filter<Predicate, Sequence>;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_FILTER_HPP
