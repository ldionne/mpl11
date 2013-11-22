/*!
 * @file
 * Forward declares `boost::mpl11::hash`.
 */

#ifndef BOOST_MPL11_FWD_HASH_HPP
#define BOOST_MPL11_FWD_HASH_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup intrinsics
     *
     * Returns a type that is almost uniquely associated to `%Hashable`.
     *
     *
     * @todo
     * Document this further if it's useful.
     */
    template <typename Hashable>
    struct hash;

    template <typename Hashable>
    using hash_t = typename hash<Hashable>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_HASH_HPP
