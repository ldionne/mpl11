/*!
 * @file
 * Forward declares `boost::mpl11::Orderable`.
 */

#ifndef BOOST_MPL11_FWD_ORDERABLE_HPP
#define BOOST_MPL11_FWD_ORDERABLE_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup typeclasses
     * @defgroup Orderable Orderable
     *
     * The `Orderable` typeclass is used for totally ordered datatypes.
     *
     *
     * ### Methods
     * `less`, `less_equal`, `greater` and `greater_equal`.
     *
     * Those methods can be invoked with more than two elements.
     * Specifically, `method<T1, ..., Tn>` is equivalent to
     * `and_<method<T1, T2>, method<T2, ..., Tn>>`, and `method<T1, T2>`
     * uses the usual tag dispatching technique.
     *
     * ### Minimal complete definition
     * `less`
     *
     *
     * @todo
     * Implement multiple arguments for the methods, as documented.
     *
     * @{
     */
    template <typename TagL, typename TagR = TagL>
    struct Orderable;

    /*!
     * Boolean `Integral` representing whether the given objects are ordered
     * according to the `<` ordering.
     */
    template <typename T1, typename T2>
    struct less;

    template <typename T1, typename T2>
    using less_t = typename less<T1, T2>::type;

    /*!
     * Boolean `Integral` representing whether the given objects are ordered
     * according to the `<=` ordering.
     */
    template <typename T1, typename T2>
    struct less_equal;

    template <typename T1, typename T2>
    using less_equal_t = typename less_equal<T1, T2>::type;

    /*!
     * Boolean `Integral` representing whether the given objects are ordered
     * according to the `>` ordering.
     */
    template <typename T1, typename T2>
    struct greater;

    template <typename T1, typename T2>
    using greater_t = typename greater<T1, T2>::type;

    /*!
     * Boolean `Integral` representing whether the given objects are ordered
     * according to the `>=` ordering.
     */
    template <typename T1, typename T2>
    struct greater_equal;

    template <typename T1, typename T2>
    using greater_equal_t = typename greater_equal<T1, T2>::type;

    //! @}
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_ORDERABLE_HPP
