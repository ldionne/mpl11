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
     * Removes the first element of a `FrontExtensibleContainer`.
     *
     * If no such element exists, i.e. if `%Container` is empty, a
     * compile-time assertion is triggered.
     */
    template <typename Container>
    struct pop_front;

    template <typename Container>
    using pop_front_t = typename pop_front<Container>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_POP_FRONT_HPP
