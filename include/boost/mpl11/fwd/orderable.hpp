/*!
 * @file
 * Forward declares the @ref Orderable typeclass.
 */

#ifndef BOOST_MPL11_FWD_ORDERABLE_HPP
#define BOOST_MPL11_FWD_ORDERABLE_HPP

#include <boost/mpl11/detail/doxygen.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup typeclasses
     * @defgroup Orderable Orderable
     *
     * The `Orderable` typeclass is used for totally ordered datatypes.
     *
     *
     * ### Methods
     * `less`, `less_equal`, `greater`, `greater_equal`, `min` and `max`.
     *
     * All those methods can be invoked with two arguments or more.
     * Specifically:
     * - If `m` is one of `less`, `less_equal`, `greater` or `greater_equal`,
     *   then `m<T1, ..., Tn>` is equivalent to
     *   `and_<m<T1, T2>, m<T2, ..., Tn>>`, and `m<T1, T2>` uses the usual
     *   tag dispatching technique.
     *
     * - If `m` is `min` or `max`, then `m<T1, ..., Tn>` is equivalent to
     *   `m<m<T1, T2>::%type, ..., Tn>`, and `m<T1, T2>` uses the usual
     *   tag dispatching technique.
     *
     * ### Minimal complete definition
     * `less`
     *
     * @{
     */
    template <typename TagL, typename TagR = TagL>
    struct Orderable;

    /*!
     * Tag representing the `Orderable` typeclass.
     *
     * @ingroup tags
     */
    struct orderable_tag BOOST_MPL11_IF_DOXYGEN({ });

    /*!
     * Boolean `StaticConstant` representing whether the given objects are
     * ordered according to the `<` ordering.
     */
    template <typename T1, typename T2, typename ...Tn>
    struct less;

    template <typename T1, typename T2, typename ...Tn>
    using less_t = typename less<T1, T2, Tn...>::type;

    /*!
     * Boolean `StaticConstant` representing whether the given objects are
     * ordered according to the `<=` ordering.
     */
    template <typename T1, typename T2, typename ...Tn>
    struct less_equal;

    template <typename T1, typename T2, typename ...Tn>
    using less_equal_t = typename less_equal<T1, T2, Tn...>::type;

    /*!
     * Boolean `StaticConstant` representing whether the given objects are
     * ordered according to the `>` ordering.
     */
    template <typename T1, typename T2, typename ...Tn>
    struct greater;

    template <typename T1, typename T2, typename ...Tn>
    using greater_t = typename greater<T1, T2, Tn...>::type;

    /*!
     * Boolean `StaticConstant` representing whether the given objects are
     * ordered according to the `>=` ordering.
     */
    template <typename T1, typename T2, typename ...Tn>
    struct greater_equal;

    template <typename T1, typename T2, typename ...Tn>
    using greater_equal_t = typename greater_equal<T1, T2, Tn...>::type;

    /*!
     * Returns the smallest of its arguments according to the ordering
     * induced by `less`.
     */
    template <typename T1, typename T2, typename ...Tn>
    struct min;

    template <typename T1, typename T2, typename ...Tn>
    using min_t = typename min<T1, T2, Tn...>::type;

    /*!
     * Returns the largest of its arguments according to the ordering
     * induced by `less`.
     */
    template <typename T1, typename T2, typename ...Tn>
    struct max;

    template <typename T1, typename T2, typename ...Tn>
    using max_t = typename max<T1, T2, Tn...>::type;
    //! @}
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_ORDERABLE_HPP
