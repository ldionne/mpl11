/*!
 * @file
 * Forward declares `boost::mpl11::front`.
 */

#ifndef BOOST_MPL11_FWD_FRONT_HPP
#define BOOST_MPL11_FWD_FRONT_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup intrinsics
     *
     * Returns the first element of a `ForwardIterable` if there is such an
     * element, and triggers a compile-time assertion otherwise.
     */
    template <typename I>
    struct front;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_FRONT_HPP
