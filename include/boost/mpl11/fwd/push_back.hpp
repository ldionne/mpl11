/*!
 * @file
 * Forward declares `boost::mpl11::push_back`.
 */

#ifndef BOOST_MPL11_FWD_PUSH_BACK_HPP
#define BOOST_MPL11_FWD_PUSH_BACK_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup container_intrinsics
     *
     * Appends an element at the end of a container.
     */
    template <typename Seq, typename Element>
    struct push_back;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_PUSH_BACK_HPP
