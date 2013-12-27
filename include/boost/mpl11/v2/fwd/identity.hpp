/*!
 * @file
 * Forward declares `boost::mpl11::identity`.
 */

#ifndef BOOST_MPL11_FWD_IDENTITY_HPP
#define BOOST_MPL11_FWD_IDENTITY_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup metafunctions
     *
     * `Metafunction` returning its argument unchanged.
     */
    template <typename T>
    struct identity;

    template <typename T>
    using identity_t = T;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_IDENTITY_HPP
