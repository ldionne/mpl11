/*!
 * @file
 * Defines `boost::mpl11::insert_keys`.
 */

#ifndef BOOST_MPL11_FWD_INSERT_KEYS_HPP
#define BOOST_MPL11_FWD_INSERT_KEYS_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup container_intrinsics
     *
     * Inserts a `Sequence` of elements in an `AssociativeContainer`.
     */
    template <typename Container, typename Elements>
    struct insert_keys;

    template <typename Container, typename Elements>
    using insert_keys_t = typename insert_keys<Container, Elements>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_INSERT_KEYS_HPP
