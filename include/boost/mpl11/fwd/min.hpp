/*!
 * @file
 * Forward declares `boost::mpl11::min`.
 */

#ifndef BOOST_MPL11_FWD_MIN_HPP
#define BOOST_MPL11_FWD_MIN_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup algorithms
     *
     * Returns the smallest of its arguments.
     *
     *
     * ### Semantics and default implementation
     *
     * When invoked with arguments `T1`, `T2`, ...`Tn`, equivalent to
     * `min<T1, min<T2, Tn...>::type>`.
     *
     * When invoked with arguments `T1` and `T2`, equivalent to
     * `if_<less<T1, T2>, T1, T2>`.
     *
     *
     * @warning
     * Differences from the original MPL:
     * - Several types can be compared at a time.
     */
    template <typename T1, typename T2, typename ...Tn>
    struct min;

    template <typename T1, typename T2, typename ...Tn>
    using min_t = typename min<T1, T2, Tn...>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_MIN_HPP
