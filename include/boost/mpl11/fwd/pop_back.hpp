/*!
 * @file
 * Forward declares `boost::mpl11::pop_back`.
 */

#ifndef BOOST_MPL11_FWD_POP_BACK_HPP
#define BOOST_MPL11_FWD_POP_BACK_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup container_intrinsics
     *
     * Removes the last element of a sequence if such an element exists, and
     * triggers a compile-time assertion otherwise.
     */
    template <typename Seq>
    struct pop_back;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_POP_BACK_HPP
