/*!
 * @file
 * Forward declares the @ref Iterable module.
 */

#ifndef BOOST_MPL11_FWD_ITERABLE_HPP
#define BOOST_MPL11_FWD_ITERABLE_HPP

#include <boost/mpl11/detail/doxygen.hpp>
#include <boost/mpl11/detail/std_size_t.hpp>
#include <boost/mpl11/fwd/comparable.hpp>
#include <boost/mpl11/fwd/foldable.hpp>
#include <boost/mpl11/fwd/functor.hpp>
#include <boost/mpl11/fwd/orderable.hpp>


namespace boost { namespace mpl11 {
    template <typename>                     struct head_impl;
    template <typename>                     struct last_impl;
    template <typename>                     struct tail_impl;
    template <typename>                     struct init_impl;
    template <typename>                     struct is_empty_impl;
    template <typename>                     struct length_impl;
    template <typename, typename>           struct unpack_impl;
    template <typename, detail::std_size_t> struct at_c_impl;

    /*!
     * @ingroup typeclasses
     * @defgroup Iterable Iterable
     *
     * Data structures allowing external iteration.
     *
     *
     * ### Methods
     * `head`, `tail`, `is_empty`, `last`, `init`, `at_c`, `at`,
     * `length` and `unpack`.
     *
     * `at` is only a wrapper over `at_c`. It is provided for convenience but
     * it is not implemented inside the typeclass.
     *
     * ### Minimal complete definition
     * `head`, `tail` and `is_empty`.
     *
     * ### Provides
     * - `Comparable` when the elements in the iterable are `Comparable`.
     * - `Orderable` when the elements in the iterable are `Orderable`.
     * - `Foldable`
     * - `Functor`
     *
     *
     * @note
     * `Iterable`s are not required to be finite. If an `Iterable` is
     * infinite, some methods such as `length` and `unpack` are not
     * well-defined. The well-definedness of some other methods such as
     * `init` and `last` depends on the particular iterable.
     *
     * @{
     */
    template <typename Tag>
    struct Iterable;

    /*!
     * Tag representing the `Iterable` typeclass.
     *
     * @ingroup tags
     */
    struct iterable_tag BOOST_MPL11_IF_DOXYGEN({ });

#if !defined(BOOST_MPL11_ENABLE_ASSERTIONS)

    template <typename I>                       using head = head_impl<I>;
    template <typename I>                       using last = last_impl<I>;
    template <typename I>                       using tail = tail_impl<I>;
    template <typename I>                       using init = init_impl<I>;
    template <typename I, detail::std_size_t N> using at_c = at_c_impl<I, N>;

#else

    //! Returns the first element of a non-empty iterable.
    template <typename I>
    struct head;

    /*!
     * Extract the elements after the head of a non-empty iterable.
     *
     * Specifically, returns an iterable containing all the elements of the
     * original iterable except the first one.
     */
    template <typename I>
    struct tail;

    //! Returns the last element of a non-empty iterable.
    template <typename I>
    struct last;

    /*!
     * Extract the elements before the last of a non-empty iterable.
     *
     * Specifically, returns an iterable containing all the elements of the
     * original iterable except the last one.
     */
    template <typename I>
    struct init;

    //! Returns the element of an iterable at the given index.
    template <typename I, detail::std_size_t Index>
    struct at_c;

#endif

    //! Boolean `StaticConstant` representing whether the iterable is empty.
    template <typename I>
    BOOST_MPL11_DOXYGEN_ALIAS(is_empty, is_empty_impl<I>);

    //! Equivalent to `at_c<S, Index::value>`;
    //! requires a non-negative `Index`.
    template <typename I, typename Index>
    struct at;

    //! `StaticConstant` of unsigned type representing the number of
    //! elements in a finite iterable.
    template <typename I>
    BOOST_MPL11_DOXYGEN_ALIAS(length, length_impl<I>);

    /*!
     * Invokes a metafunction class with the contents of a finite iterable.
     *
     * Specifically, `unpack<I, F>` is a nullary metafunction equivalent
     * to `apply<F, a0, ..., an>`, where `a0`, ...,`an` are the elements
     * in the iterable.
     */
    template <typename I, typename F>
    BOOST_MPL11_DOXYGEN_ALIAS(unpack, unpack_impl<I, F>);


    template <typename I>
    using head_t = typename head<I>::type;

    template <typename I>
    using tail_t = typename tail<I>::type;

    template <typename I>
    using is_empty_t = typename is_empty<I>::type;

    template <typename I>
    using last_t = typename last<I>::type;

    template <typename I>
    using init_t = typename init<I>::type;

    template <typename I, detail::std_size_t Index>
    using at_c_t = typename at_c<I, Index>::type;

    template <typename I, typename Index>
    using at_t = typename at<I, Index>::type;

    template <typename I>
    using length_t = typename length<I>::type;

    template <typename I, typename F>
    using unpack_t = typename unpack<I, F>::type;

    //! Defines the default operations for iterables.
    template <>
    struct Iterable<iterable_tag> BOOST_MPL11_IF_DOXYGEN({ });

    /*!
     * Default instantiation of the `Comparable` typeclass for iterables.
     *
     * Two iterables are equal if their elements are equal when compared
     * side-by-side, and if both iterables run out of elements at the same
     * time, i.e. if they have the same length.
     */
    template <>
    struct Comparable<iterable_tag, iterable_tag> BOOST_MPL11_IF_DOXYGEN({ });

    /*!
     * Default instantiation of the `Orderable` typeclass for iterables.
     *
     * Less-than comparison for iterables is defined as the lexicographical
     * comparison of their elements.
     */
    template <>
    struct Orderable<iterable_tag, iterable_tag> BOOST_MPL11_IF_DOXYGEN({ });

    /*!
     * Default instantiation of the `Foldable` typeclass for iterables.
     *
     *
     * ### `foldl<F, State, It>`
     * Reduces an iterable using a binary operation, from left to right.
     *
     * Specifically, returns the result of the successive application of the
     * binary operation `F` to the result of the previous `F` invocation (or
     * `State` for the first application) and every element of the iterable
     * in order.
     *
     * Visually, with `It = x1, x2, ..., xn`:
     *
            foldl(F, State, It) == F(...F(F(State, x1), x2)..., xn)
     *
     *
     *
     * ### `foldr<F, State, It>`
     * Reduces an iterable using a binary operator, from right to left.
     *
     * Specifically, returns the result of the successive application of the
     * binary operation `F` to every element of the iterable and the result
     * of the next `F` invocation (or `State` for the last application).
     *
     * Visually, with `It = x1, x2, ..., xn`:
     *
            foldr(F, State, It) == F(x1, F(x2, ...F(xn, State)...))
     *
     *
     * @note
     * `foldl` is equivalent to the `fold` metafunction from the original MPL.
     * However, the order of the arguments has changed.
     *
     * @todo
     * Improve the implementations.
     */
    template <>
    struct Foldable<iterable_tag> BOOST_MPL11_IF_DOXYGEN({ });

    /*!
     * Default instantiation of the `Functor` typeclass for iterables.
     *
     * ### `map<F, It>`
     * Returns the result of applying `F` to each element of the iterable.
     */
    template <>
    struct Functor<iterable_tag> BOOST_MPL11_IF_DOXYGEN({ });


    /*!
     * Returns an iterable containing the suffix of another iterable after
     * the first `N` elements.
     *
     * `N` must be a non-negative `StaticConstant` representing the number of
     * elements to be dropped from the underlying iterable. If `N` is greater
     * than the length of the iterable, the returned iterable is empty.
     */
    template <typename N, typename It>
    struct drop;

    template <typename N, typename It>
    using drop_t = typename drop<N, It>::type;

    //! Equivalent to `drop<size_t<N>, It>`.
    template <detail::std_size_t N, typename It>
    struct drop_c;

    template <detail::std_size_t N, typename It>
    using drop_c_t = typename drop_c<N, It>::type;


    /*!
     * Drops elements from an iterable up to, but not including, the first
     * element for which the `Predicate` returns `false`.
     *
     * Specifically, `drop_while` returns an iterable containing all the
     * elements of the underlying iterable except for those in the range
     * delimited by [`head`, `e`), where `head` is the first element of
     * the iterable and `e` is the first element for which the `Predicate`
     * returns `false`.
     *
     *
     * @todo
     * Use a less naive `consume` implementation.
     */
    template <typename Predicate, typename It>
    struct drop_while;

    template <typename Predicate, typename It>
    using drop_while_t = typename drop_while<Predicate, It>::type;


    /*!
     * Returns an iterable containing the first `N` elements of
     * another iterable.
     *
     * `N` must be a non-negative `StaticConstant` representing the number of
     * elements to keep in the underlying iterable. If `N` is greater than
     * the length of the iterable, all of its elements are kept.
     */
    template <typename N, typename It>
    struct take;

    template <typename N, typename It>
    using take_t = typename take<N, It>::type;

    //! Equivalent to `take<size_t<N>, It>`.
    template <detail::std_size_t N, typename It>
    struct take_c;

    template <detail::std_size_t N, typename It>
    using take_c_t = typename take_c<N, It>::type;


    /*!
     * Returns the longest prefix of an iterable in which all elements
     * satisfy the `Predicate`.
     */
    template <typename Predicate, typename It>
    struct take_while;

    template <typename Predicate, typename It>
    using take_while_t = take_while<Predicate, It>;


    //! Returns an iterable with an element prepended to it.
    template <typename Head, typename Tail>
    struct cons;

    template <typename Head, typename Tail>
    using cons_t = typename cons<Head, Tail>::type;


    /*!
     * Returns an iterable containing only the elements satisfying
     * the `Predicate`.
     *
     * If the underlying iterable is infinite, the iterable returned by
     * `filter` is finite if and only if the `Predicate` is `false` for
     * an infinite suffix of the iterable. However, since this is hard to
     * determine without actually performing the computation and should
     * be rare anyways, the returned iterable is trait-wise infinite whenever
     * the underlying iterable is infinite.
     */
    template <typename Predicate, typename It>
    struct filter;

    template <typename Predicate, typename It>
    using filter_t = typename filter<Predicate, It>::type;


    /*!
     * Concatenate several iterable.
     *
     * When invoked with `0` iterables, `join` returns an empty iterable.
     * When invoked with `1` iterables, `join` returns the iterable itself.
     *
     *
     * @todo
     * Improve the implementation:
     * - Use folds instead of hand-crafted recursion in the implementation.
     * - Use a fold to implement `at_c`.
     * - Handle the infinite iterable case in `at_c`.
     * - Implement `init` in an efficient way.
     * - Improve the filtration of iterables when creating `join`.
     * - Don't reconstruct `join` in `unpack_impl`.
     */
    template <typename ...Iterables>
    struct join;

    template <typename ...Iterables>
    using join_t = typename join<Iterables...>::type;


    //! Returns the elements of an iterable in reverse order.
    template <typename It>
    struct reverse;

    template <typename It>
    using reverse_t = typename reverse<It>::type;


    /*!
     * `scanl` is similar to `foldl`, but returns an iterable of successive
     * reduced values from the left.
     */
    template <typename F, typename State, typename It>
    struct scanl;

    template <typename F, typename State, typename It>
    using scanl_t = typename scanl<F, State, It>::type;


    /*!
     * Returns an iterable with an element appended to its end.
     *
     *
     * @todo
     * If the iterable is infinite, `snoc` could be `id`.
     */
    template <typename Init, typename Last>
    struct snoc;

    template <typename Init, typename Last>
    using snoc_t = typename snoc<Init, Last>::type;


    //! Returns an iterable sorted with the `Predicate`.
    template <typename Predicate, typename It>
    struct sort_by;

    template <typename Predicate, typename It>
    using sort_by_t = typename sort_by<Predicate, It>::type;


    /*!
     * Returns an iterable that aggregates elements from two or
     * more iterables.
     *
     * Specifically, the i-th element of the iterable is a `list` containing
     * the i-th element of each zipped iterable. The iterable stops when the
     * shortest zipped iterable is exhausted.
     *
     *
     * @todo
     * Consider implementing a `zip_longest` with the obvious semantics.
     *
     * @todo
     * Should we allow 0 and 1 iterable to be zipped?
     */
    template <typename It1, typename It2, typename ...ItN>
    struct zip;

    template <typename It1, typename It2, typename ...ItN>
    using zip_t = typename zip<It1, It2, ItN...>::type;
    //! @}
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_ITERABLE_HPP
