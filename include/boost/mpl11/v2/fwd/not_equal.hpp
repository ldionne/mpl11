/*!
 * @file
 * Forward declares `boost::mpl11::not_equal`.
 */

#ifndef BOOST_MPL11_FWD_NOT_EQUAL_HPP
#define BOOST_MPL11_FWD_NOT_EQUAL_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup Comparable
     * @ingroup comparison_methods
     *
     * Boolean `Integral` representing whether the given objects are unequal.
     *
     *
     * @warning
     * Using this method with several arguments can be confusing. It does not
     * return whether `T1`, `T2`, ...`Tn` are all unequal, but whether `T1`
     * is different from `T2`, `T2` different from `T3`, and so on.
     */
    template <typename T1, typename T2, typename ...Tn>
    struct not_equal;

    template <typename T1, typename T2, typename ...Tn>
    using not_equal_t = typename not_equal<T1, T2, Tn...>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_NOT_EQUAL_HPP
