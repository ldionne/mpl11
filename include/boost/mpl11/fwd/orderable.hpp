/*!
 * @file
 * Forward declares the @ref Orderable typeclass.
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
     * `less`, `less_equal`, `greater`, `greater_equal`, `min` and `max`.
     *
     * The `less`, `less_equal`, `greater` and `greater_equal` methods can
     * all be invoked with more than two arguments, in which case the method's
     * behavior conforms to the usual mathematical usage. Specifically,
     * `less<x1, x2, xs...>` is equivalent to
     * `and_<less<x1, x2>, less<x2, xs...>>`.
     *
     * The `min` and `max` methods can also be invoked with more than two
     * arguments. Specifically, `min<x1, x2, xs...>` is equivalent to
     * `min<min<x1, x2>, xs...>`.
     *
     *
     * ### Minimal complete definition
     * `less`
     *
     * @{
     */
    template <typename Left, typename Right = Left>
    struct Orderable;

    /*!
     * Returns whether the given objects are ordered according to the `<`
     * ordering.
     */
    template <typename x1, typename x2, typename ...xs>
    struct less;

    /*!
     * Returns whether the given objects are ordered according to the `<=`
     * ordering.
     */
    template <typename x1, typename x2, typename ...xs>
    struct less_equal;

    /*!
     * Returns whether the given objects are ordered according to the `>`
     * ordering.
     */
    template <typename x1, typename x2, typename ...xs>
    struct greater;

    /*!
     * Returns whether the given objects are ordered according to the `>=`
     * ordering.
     */
    template <typename x1, typename x2, typename ...xs>
    struct greater_equal;

    /*!
     * Returns the smallest of its arguments according to the ordering
     * induced by `less`.
     */
    template <typename x1, typename x2, typename ...xs>
    struct min;

    /*!
     * Returns the largest of its arguments according to the ordering
     * induced by `less`.
     */
    template <typename x1, typename x2, typename ...xs>
    struct max;
    //! @}
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_ORDERABLE_HPP
