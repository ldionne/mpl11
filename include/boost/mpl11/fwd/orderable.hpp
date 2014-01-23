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
     * All of these methods can be invoked with two arguments or more.
     * Specifically:
     * - If `m` is one of `less`, `less_equal`, `greater` or `greater_equal`,
     *   then `m<x1, ..., xN>` is equivalent to
     *   `and_<m<x1, x2>, m<x2, ..., xN>>`, and `m<x1, x2>` uses the usual
     *   dispatching technique.
     *
     * - If `m` is `min` or `max`, then `m<x1, ..., xN>` is equivalent to
     *   `m<m<x1, x2>, x3, ..., xN>`, and `m<x1, x2>` uses the usual
     *   dispatching technique.
     *
     * ### Minimal complete definition
     * `less`
     *
     * @{
     */
    template <typename Left, typename Right = Left>
    struct Orderable;

    /*!
     * Boolean `StaticConstant` representing whether the given objects are
     * ordered according to the `<` ordering.
     */
    template <typename x1, typename x2, typename ...xs>
    struct less;

    /*!
     * Boolean `StaticConstant` representing whether the given objects are
     * ordered according to the `<=` ordering.
     */
    template <typename x1, typename x2, typename ...xs>
    struct less_equal;

    /*!
     * Boolean `StaticConstant` representing whether the given objects are
     * ordered according to the `>` ordering.
     */
    template <typename x1, typename x2, typename ...xs>
    struct greater;

    /*!
     * Boolean `StaticConstant` representing whether the given objects are
     * ordered according to the `>=` ordering.
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
