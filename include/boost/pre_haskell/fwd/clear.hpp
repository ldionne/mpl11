/*!
 * @file
 * Forward declares `boost::mpl11::clear`.
 */

#ifndef BOOST_MPL11_FWD_CLEAR_HPP
#define BOOST_MPL11_FWD_CLEAR_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup container_intrinsics
     *
     * Erases all the elements of a `Container`.
     */
    template <typename Container>
    struct clear;

    template <typename Container>
    using clear_t = typename clear<Container>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_CLEAR_HPP
