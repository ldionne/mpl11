/*!
 * @file
 * Forward declares `boost::mpl11::erase`.
 */

#ifndef BOOST_MPL11_FWD_ERASE_HPP
#define BOOST_MPL11_FWD_ERASE_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup container_intrinsics
     *
     * Removes an element at a position in an `ExtensibleContainer`.
     */
    template <typename Container, typename Position>
    struct erase;

    template <typename Container, typename Position>
    using erase_t = typename erase<Container, Position>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_ERASE_HPP
