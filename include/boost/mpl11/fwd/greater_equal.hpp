/*!
 * @file
 * Forward declares `boost::mpl11::greater_equal`.
 */

#ifndef BOOST_MPL11_FWD_GREATER_EQUAL_HPP
#define BOOST_MPL11_FWD_GREATER_EQUAL_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup comparison_operators
     *
     * Returns `T1 >= T2 >= ...Tn`.
     */
    template <typename T1, typename T2, typename ...Tn>
    struct greater_equal;

    template <typename T1, typename T2, typename ...Tn>
    using greater_equal_t = typename greater_equal<T1, T2, Tn...>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_GREATER_EQUAL_HPP
