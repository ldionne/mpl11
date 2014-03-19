/*!
 * @file
 * Forward declares the @ref Iterable typeclass.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_MPL11_FWD_ITERABLE_HPP
#define BOOST_MPL11_FWD_ITERABLE_HPP

#include <boost/mpl11/detail/checked.hpp>
#include <boost/mpl11/detail/doxygen.hpp>
#include <boost/mpl11/detail/std_size_t.hpp>
#include <boost/mpl11/fwd/bool.hpp>
#include <boost/mpl11/fwd/functional.hpp>
#include <boost/mpl11/fwd/integer.hpp>
#include <boost/mpl11/fwd/logical.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup typeclasses
     * @defgroup Iterable Iterable
     *
     * Data structures allowing external iteration.
     *
     * `Iterable`s are not required to be finite. Some operations are only
     * well-defined on finite `Iterable`s; the documentation of the operation
     * and that of the `Iterable` in question should be consulted.
     *
     *
     * ### Methods
     * `head`, `tail`, `is_empty`, `last`, `at` and `length`
     *
     *
     * ### Minimal complete definition
     * `head`, `tail` and `is_empty`.
     *
     *
     * ### Provided instances
     * #### `Comparable`
     * Two iterables are equal if their elements are equal when compared
     * side-by-side, and if both iterables run out of elements at the
     * same time, i.e. if they have the same length.
     *
     * #### `Orderable`
     * Less-than comparison for iterables is defined as the lexicographical
     * comparison of their elements.
     *
     * #### `Foldable`
     * ##### `foldl<f, state, iter>`
     * Reduces an iterable using a binary operation, from left to right.
     *
     * Specifically, returns the result of the successive application of the
     * binary operation `f` to the result of the previous `f` invocation (or
     * `state` for the first application) and every element of the iterable
     * in order.
     *
     * Visually, with `iter = x1, x2, ..., xn`:
     *
            foldl(f, state, iter) == f(...f(f(state, x1), x2)..., xn)
     *
     *
     *
     * ##### `foldr<f, state, iter>`
     * Reduces an iterable using a binary operator, from right to left.
     *
     * Specifically, returns the result of the successive application of the
     * binary operation `f` to every element of the iterable and the result
     * of the next `f` invocation (or `state` for the last application).
     *
     * Visually, with `iter = x1, x2, ..., xn`:
     *
            foldr(f, state, iter) == f(x1, f(x2, ...f(xn, state)...))
     *
     * @note
     * `foldl` is equivalent to the `fold` metafunction from the original MPL.
     * However, the order of the arguments has changed.
     *
     *
     * @todo
     * - Find a way to know whether an `Iterable` is finite and whether it
     *   has efficient xx or yy operations.
     * - Perform bounds-checking in `at` when we have a way of knowing whether
     *   an `Iterable` is finite.
     * - Improve the implementation of `Foldable`, `Comparable`, `Orderable`,
     *   `drop_while`, `drop` and default methods.
     *
     * @{
     */
    template <typename Datatype, typename = true_>
    struct Iterable;

    //! Returns the first element of a non-empty iterable.
    BOOST_MPL11_DECLARE_CHECKED(head, typename iter);

    /*!
     * Extract the elements after the head of a non-empty iterable.
     *
     * Specifically, returns an iterable containing all the elements of the
     * original iterable except the first one.
     */
    BOOST_MPL11_DECLARE_CHECKED(tail, typename iter);

    //! Returns the last element of a non-empty iterable.
    BOOST_MPL11_DECLARE_CHECKED(last, typename iter);

    //! Returns the number of elements in a finite iterable.
    template <typename iter>
    struct length;

    //! Returns the element of an iterable at the given index.
    BOOST_MPL11_DECLARE_CHECKED(at, typename index, typename iter);

    //! Equivalent to `at<size_t<index>, iter>`.
    template <detail::std_size_t index, typename iter>
    BOOST_MPL11_DOXYGEN_ALIAS(at_c, at<size_t<index>, iter>);

    //! Returns whether the iterable is empty.
    template <typename iter>
    struct is_empty;

    /*!
     * Drops the first `n` elements from an iterable and return the rest.
     *
     * `n` must be a non-negative @ref Integer representing the number of
     * elements to be dropped from the underlying iterable. If `n` is greater
     * than the length of the iterable, the returned iterable is empty.
     */
    BOOST_MPL11_DECLARE_CHECKED(drop, typename n, typename iter);

    //! Equivalent to `drop<size_t<n>, iter>`; provided for convenience.
    template <detail::std_size_t n, typename iter>
    BOOST_MPL11_DOXYGEN_ALIAS(drop_c, drop<size_t<n>, iter>);

    /*!
     * Drops elements from an iterable up to, but not including, the first
     * element for which the `predicate` returns `false`.
     *
     * Specifically, `drop_while` returns an iterable containing all the
     * elements of the underlying iterable except for those in the range
     * delimited by [`head`, `e`), where `head` is the first element of
     * the iterable and `e` is the first element for which the `predicate`
     * returns `false`.
     */
    template <typename predicate, typename iter>
    struct drop_while;

    //! Equivalent to `drop_while` with a negated `predicate`.
    template <typename predicate, typename iter>
    BOOST_MPL11_DOXYGEN_ALIAS(drop_until,
                        drop_while<compose<lift<not_>, predicate>, iter>);
    //! @}
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_ITERABLE_HPP
