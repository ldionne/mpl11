/*!
 * @file
 * Forward declares `boost::mpl11::pop_front`.
 */

#ifndef BOOST_MPL11_FWD_POP_FRONT_HPP
#define BOOST_MPL11_FWD_POP_FRONT_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup container_intrinsics
     *
     * Removes the first element of a container if such an element exists,
     * and triggers a compile-time assertion otherwise.
     */
    template <typename Seq>
    struct pop_front;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_POP_FRONT_HPP
