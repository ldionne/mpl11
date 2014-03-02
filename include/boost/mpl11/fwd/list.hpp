/*!
 * @file
 * Forward declares the `boost::mpl11::List` datatype.
 */

#ifndef BOOST_MPL11_FWD_LIST_HPP
#define BOOST_MPL11_FWD_LIST_HPP

#include <boost/mpl11/detail/doxygen.hpp>
#include <boost/mpl11/detail/std_size_t.hpp>
#include <boost/mpl11/fwd/functional.hpp>
#include <boost/mpl11/fwd/integer.hpp>
#include <boost/mpl11/fwd/logical.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup datatypes
     * @defgroup List List
     *
     * A sequence of types.
     *
     *
     * ### Instance of
     * `Iterable`, `Functor`
     *
     * @todo
     * - Find out how to minimize the number of instantiations. In the
     * current implementation, the whole list has to be re-indexed
     * each time we modify it.
     * - Use rewrite rules for `repeat` and `take`.
     *
     * @{
     */
    struct List BOOST_MPL11_IF_DOXYGEN({ });

    //! A `List` containing the given elements.
    template <typename ...xs>
    struct list;

    //! A `List` created by prepending an element to an @ref Iterable.
    template <typename x, typename xs>
    struct cons;

    /*!
     * A `List` created by appending an element to an @ref Iterable.
     *
     * @todo
     * If the iterable is infinite, `snoc` could be `id`.
     */
    template <typename xs, typename x>
    struct snoc;

    //! Returns an infinite `List` of repeated applications of `f` to `x`.
    template <typename f, typename x>
    struct iterate;

    //! Returns an infinite `List` containing copies of `x`.
    template <typename x>
    struct repeat;

    /*!
     * Returns the first `n` elements of a `List`.
     *
     * `n` must be a non-negative @ref Integer representing the number of
     * elements to keep. If `n` is greater than the length of the `List`,
     * the whole `List` is returned.
     */
    template <typename n, typename xs>
    struct take;

    //! Equivalent to `take<size_t<n>, xs>`.
    template <detail::std_size_t n, typename xs>
    BOOST_MPL11_DOXYGEN_ALIAS(take_c, take<size_t<n>, xs>);

    /*!
     * Returns the longest prefix of a `List` in which all elements
     * satisfy the `predicate`.
     */
    template <typename predicate, typename xs>
    struct take_while;

    //! Equivalent to `take_while` with a negated `predicate`.
    template <typename predicate, typename xs>
    BOOST_MPL11_DOXYGEN_ALIAS(take_until,
        take_while<compose<quote<not_>, predicate>, xs>);

    //! Returns a `List` with its elements in reverse order.
    template <typename xs>
    struct reverse;

    //! Returns a `List` containing only the elements satisfying `predicate`.
    template <typename predicate, typename xs>
    struct filter;

    /*!
     * `scanl` is similar to `foldl`, but returns a `List` of successive
     * reduced values from the left.
     */
    template <typename f, typename state, typename xs>
    struct scanl;

    /*!
     * Returns a list that aggregates elements from several lists.
     *
     * Specifically, the i-th element of the list is a `List` containing
     * the i-th element of each zipped list. The list stops when the
     * shortest zipped list is exhausted. When invoked with 0 arguments,
     * `zip` returns an empty list. When invoked with 1 argument, `zip`
     * returns a `List` of 1-element `List`s.
     *
     *
     * @todo
     * Consider implementing a `zip_longest` with the obvious semantics.
     */
    template <typename ...lists>
    struct zip;

    /*!
     * Concatenate several lists.
     *
     * When invoked with 0 arguments, `join` returns an empty list.
     * When invoked with 1 argument, `join` returns the list itself.
     *
     *
     * @todo
     * - Optimize last, init and at.
     * - Should we receive variadic arguments or an iterable of iterables?
     * - Consider using `drop_while` instead of hand-written recursion.
     */
    template <typename ...lists>
    struct join;

    /*!
     * Returns a subrange of a list.
     *
     * Specifically, `slice` returns the elements in the subrange delimited
     * by [`start`, `stop`). In all cases, `start` must be non-negative and
     * less-than or equal to `stop`. If the list is finite, `stop` must
     * always be less-than or equal to `length<xs>`.
     *
     *
     * @todo
     * Reintroduce optimizations that were lost when using a single
     * typeclass for iterables.
     */
    template <typename xs, typename start, typename stop>
    struct slice;

    //! Equivalent to `slice<xs, size_t<start>, size_t<stop>>`.
    template <typename xs, detail::std_size_t start, detail::std_size_t stop>
    BOOST_MPL11_DOXYGEN_ALIAS(slice_c, slice<xs, size_t<start>, size_t<stop>>);

    //! Returns a list sorted with the `predicate`.
    //!
    //! @todo
    //! Generate more data in unit tests by using a permutation generator.
    template <typename predicate, typename xs>
    struct sort_by;

    /*!
     * Returns the elements before the last of a non-empty list.
     *
     * Specifically, returns a list containing all the elements of the
     * original list except the last one.
     */
    template <typename xs>
    struct init;
    //! @}
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_LIST_HPP
