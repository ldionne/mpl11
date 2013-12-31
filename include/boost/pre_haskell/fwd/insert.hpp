/*!
 * @file
 * Forward declares `boost::mpl11::insert`.
 */

#ifndef BOOST_MPL11_FWD_INSERT_HPP
#define BOOST_MPL11_FWD_INSERT_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup container_intrinsics
     *
     * Inserts an element at an arbitrary position in an `ExtensibleContainer`.
     */
    template <typename Container, typename Position, typename Element>
    struct insert;

    template <typename Container, typename Position, typename Element>
    using insert_t = typename insert<Container, Position, Element>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_INSERT_HPP
