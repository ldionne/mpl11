/*!
 * @file
 * Forward declares `boost::mpl11::greater`.
 */

#ifndef BOOST_MPL11_FWD_GREATER_HPP
#define BOOST_MPL11_FWD_GREATER_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup Orderable
     * @ingroup comparison_methods
     *
     * Boolean `Integral` representing whether the given objects are ordered
     * according to the `>` ordering.
     */
    template <typename T1, typename T2, typename ...Tn>
    struct greater;

    template <typename T1, typename T2, typename ...Tn>
    using greater_t = typename greater<T1, T2, Tn...>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_GREATER_HPP
