/*!
 * @file
 * Forward declares the @ref Iterable typeclass.
 */

#ifndef BOOST_MPL11_FWD_ITERABLE_HPP
#define BOOST_MPL11_FWD_ITERABLE_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup typeclasses
     * @defgroup Iterable Iterable
     *
     * Data structures allowing external iteration.
     *
     *
     * ### Methods
     * `head`, `tail`, `is_empty`
     *
     * ### Minimal complete definition
     * `head`, `tail` and `is_empty`.
     *
     *
     * @note
     * `Iterable`s are not required to be finite. Some operations are only
     * well-defined on finite `Iterable`s; the documentation of the operation
     * and that of the `Iterable` in question should be consulted.
     *
     * @todo
     * - Optimize recursion in `drop`, `drop_while` and default methods.
     * - Find a way to know whether an `Iterable` is finite and whether it
     *   has efficient xx or yy operations.
     * - Perform bounds-checking in `at` when we have a way of knowing whether
     *   an `Iterable` is finite.
     * - Write unit tests for `drop_while` and `drop`.
     *
     * @{
     */
    template <typename Datatype>
    struct Iterable;

    //! Returns the first element of a non-empty iterable.
    template <typename iter>
    struct head;

    /*!
     * Extract the elements after the head of a non-empty iterable.
     *
     * Specifically, returns an iterable containing all the elements of the
     * original iterable except the first one.
     */
    template <typename iter>
    struct tail;

    //! Returns whether the iterable is empty.
    template <typename iter>
    struct is_empty;
    //! @}
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_ITERABLE_HPP
