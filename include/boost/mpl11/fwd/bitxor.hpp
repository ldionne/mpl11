/*!
 * @file
 * Forward declares `boost::mpl11::bitxor_`.
 */

#ifndef BOOST_MPL11_FWD_BITXOR_HPP
#define BOOST_MPL11_FWD_BITXOR_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup bitwise_operators
     *
     * Returns `T1 ^ T2 ^ ...Tn`.
     */
    template <typename T1, typename T2, typename ...Tn>
    struct bitxor_;

    template <typename T1, typename T2, typename ...Tn>
    using bitxor_t = typename bitxor_<T1, T2, Tn...>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_BITXOR_HPP
