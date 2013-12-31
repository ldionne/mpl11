/*!
 * @file
 * Forward declares `boost::mpl11::insert_key`.
 */

#ifndef BOOST_MPL11_FWD_INSERT_KEY_HPP
#define BOOST_MPL11_FWD_INSERT_KEY_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup container_intrinsics
     *
     * Inserts an element in an `AssociativeContainer`.
     */
    template <typename Container, typename Element>
    struct insert_key;

    template <typename Container, typename Element>
    using insert_key_t = typename insert_key<Container, Element>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_INSERT_KEY_HPP
