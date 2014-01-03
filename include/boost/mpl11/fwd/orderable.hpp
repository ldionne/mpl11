/*!
 * @file
 * Forward declares `boost::mpl11::Orderable`.
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

    /*!
     * Returns the smallest of its arguments according to the ordering
     * induced by `less`.
     */
    template <typename T1, typename T2>
    struct min;

    template <typename T1, typename T2>
    using min_t = typename min<T1, T2>::type;

    /*!
     * Returns the largest of its arguments according to the ordering
     * induced by `less`.
     */
    template <typename T1, typename T2>
    struct max;

    template <typename T1, typename T2>
    using max_t = typename max<T1, T2>::type;

    //! @}

    /*!
     * @ingroup tags
     *
     * Tag representing the `Orderable` typeclass.
     */
    struct orderable_tag BOOST_MPL11_DOXYGEN_ONLY({ });
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_ORDERABLE_HPP
