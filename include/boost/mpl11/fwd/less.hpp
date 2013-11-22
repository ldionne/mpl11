/*!
 * @file
 * Forward declares `boost::mpl11::less`.
 */

#ifndef BOOST_MPL11_FWD_LESS_HPP
#define BOOST_MPL11_FWD_LESS_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup comparison_operators
     *
     * Returns `T1 < T2 < ...Tn`.
     */
    template <typename T1, typename T2, typename ...Tn>
    struct less;

    template <typename T1, typename T2, typename ...Tn>
    using less_t = typename less<T1, T2, Tn...>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_LESS_HPP
