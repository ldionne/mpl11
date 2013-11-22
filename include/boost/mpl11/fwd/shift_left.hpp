/*!
 * @file
 * Forward declares `boost::mpl11::shift_left`.
 */

#ifndef BOOST_MPL11_FWD_SHIFT_LEFT_HPP
#define BOOST_MPL11_FWD_SHIFT_LEFT_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup bitwise_operators
     *
     * Returns `T1 << T2 << ...Tn`.
     */
    template <typename T1, typename T2, typename ...Tn>
    struct shift_left;

    template <typename T1, typename T2, typename ...Tn>
    using shift_left_t = typename shift_left<T1, T2, Tn...>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_SHIFT_LEFT_HPP
