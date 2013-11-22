/*!
 * @file
 * Forward declares `boost::mpl11::erase_keys`.
 */

#ifndef BOOST_MPL11_FWD_ERASE_KEYS_HPP
#define BOOST_MPL11_FWD_ERASE_KEYS_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup container_intrinsics
     *
     * Removes a `Sequence` of keys from an `AssociativeContainer`.
     */
    template <typename Container, typename Keys>
    struct erase_keys;

    template <typename Container, typename Keys>
    using erase_keys_t = typename erase_keys<Container, Keys>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_ERASE_KEYS_HPP
