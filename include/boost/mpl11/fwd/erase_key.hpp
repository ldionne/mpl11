/*!
 * @file
 * Forward declares `boost::mpl11::erase_key`.
 */

#ifndef BOOST_MPL11_FWD_ERASE_KEY_HPP
#define BOOST_MPL11_FWD_ERASE_KEY_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup container_intrinsics
     *
     * Removes the given `Key` from an `AssociativeContainer`.
     */
    template <typename Container, typename Key>
    struct erase_key;

    template <typename Container, typename Key>
    using erase_key_t = typename erase_key<Container, Key>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_ERASE_KEY_HPP
