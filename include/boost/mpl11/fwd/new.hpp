/*!
 * @file
 * Forward declares `boost::mpl11::new_`.
 */

#ifndef BOOST_MPL11_FWD_NEW_HPP
#define BOOST_MPL11_FWD_NEW_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup container_intrinsics
     *
     * Variadic @ref MetafunctionClass creating a `Container` from
     * the arguments provided to it.
     */
    template <typename Container>
    struct new_;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_NEW_HPP
