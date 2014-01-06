/*!
 * @file
 * Forward declares `boost::mpl11::none`.
 */

#ifndef BOOST_MPL11_FWD_NONE_HPP
#define BOOST_MPL11_FWD_NONE_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup metafunctions
     *
     * Boolean `StaticConstant` representing whether no element of a
     * `Sequence` satisfies the given `Predicate`.
     */
    template <typename Predicate, typename Sequence>
    struct none;

    template <typename Predicate, typename Sequence>
    using none_t = typename none<Predicate, Sequence>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_NONE_HPP
