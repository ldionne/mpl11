/*!
 * @file
 * Forward declares `boost::mpl11::id`.
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
    struct id;

    template <typename T>
    using id_t = T;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_IDENTITY_HPP
