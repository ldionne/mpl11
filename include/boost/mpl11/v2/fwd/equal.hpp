/*!
 * @file
 * Forward declares `boost::mpl11::equal`.
 */

#ifndef BOOST_MPL11_FWD_EQUAL_HPP
#define BOOST_MPL11_FWD_EQUAL_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup Comparable
     * @ingroup comparison_methods
     *
     * Boolean `Integral` representing whether the given objects are equal.
     */
    template <typename T1, typename T2, typename ...Tn>
    struct equal;

    template <typename T1, typename T2, typename ...Tn>
    using equal_t = typename equal<T1, T2, Tn...>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_EQUAL_HPP
