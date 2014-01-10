/*!
 * @file
 * Defines `boost::mpl11::id`.
 */

#ifndef BOOST_MPL11_FWD_IDENTITY_HPP
#define BOOST_MPL11_FWD_IDENTITY_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup metafunctions
     *
     * The identity metafunction - returns its argument unchanged.
     */
    template <typename T>
    using id = T;

    template <typename T>
    using id_t = typename T::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_IDENTITY_HPP
