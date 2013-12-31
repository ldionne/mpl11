/*!
 * @file
 * Forward declares `boost::mpl11::push_front`.
 */

#ifndef BOOST_MPL11_FWD_PUSH_FRONT_HPP
#define BOOST_MPL11_FWD_PUSH_FRONT_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup container_intrinsics
     *
     * Inserts an element at the beginning of a `FrontExtensibleContainer`.
     */
    template <typename Container, typename Element>
    struct push_front;

    template <typename Container, typename Element>
    using push_front_t = typename push_front<Container, Element>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_PUSH_FRONT_HPP
