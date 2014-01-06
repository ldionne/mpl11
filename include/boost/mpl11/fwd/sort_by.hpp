/*!
 * @file
 * Forward declares `boost::mpl11::sort_by`.
 */

#ifndef BOOST_MPL11_FWD_SORT_BY_HPP
#define BOOST_MPL11_FWD_SORT_BY_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup metafunctions
     *
     * Returns a `Sequence` sorted with the given `Predicate`.
     */
    template <typename Predicate, typename Sequence>
    struct sort_by;

    template <typename Predicate, typename Sequence>
    using sort_by_t = typename sort_by<Predicate, Sequence>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_SORT_BY_HPP
