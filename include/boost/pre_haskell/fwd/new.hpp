/*!
 * @file
 * Forward declares `boost::mpl11::new_`.
 */

#ifndef BOOST_MPL11_FWD_NEW_HPP
#define BOOST_MPL11_FWD_NEW_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup metafunction_classes
     * @ingroup container_intrinsics
     *
     * `MetafunctionClass` creating a `Container` from the `Sequence`
     * passed to it.
     */
    template <typename Container>
    struct new_;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_NEW_HPP
