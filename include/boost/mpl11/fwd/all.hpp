/*!
 * @file
 * Forward declares `boost::mpl11::all`.
 */

#ifndef BOOST_MPL11_FWD_ALL_HPP
#define BOOST_MPL11_FWD_ALL_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup metafunctions
     *
     * Boolean `StaticConstant` representing whether all the elements of a
     * `Sequence` satisfy the given `Predicate`.
     */
    template <typename Predicate, typename Sequence>
    struct all;

    template <typename Predicate, typename Sequence>
    using all_t = typename all<Predicate, Sequence>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_ALL_HPP
