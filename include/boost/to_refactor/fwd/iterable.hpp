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
#include <boost/mpl11/fwd/integral_c.hpp>
#include <boost/mpl11/fwd/orderable.hpp>

// For drop_until and take_until
#include <boost/mpl11/fwd/compose.hpp>
#include <boost/mpl11/fwd/not.hpp>
#include <boost/mpl11/fwd/quote.hpp>


namespace boost { namespace mpl11 {
    namespace rules {
        template <typename, typename = true_>
        struct head_impl;

        template <typename, typename = true_>
        struct last_impl;

        template <typename, typename = true_>
        struct tail_impl;

        template <typename, typename = true_>
        struct init_impl;

        template <typename, typename = true_>
        struct is_empty_impl;

        template <typename, typename = true_>
        struct length_impl;

        template <typename, typename, typename = true_>
        struct unpack_impl;

        template <typename, typename, typename = true_>
        struct at_impl;

        template <typename, typename, typename = true_>
        struct drop_impl;

        template <typename, typename, typename = true_>
        struct filter_impl;

        template <typename, typename = true_>
        struct reverse_impl;

        template <typename, typename, typename = true_>
        struct take_impl;
    } // end namespace rules

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
     * `at_c` is only a wrapper over `at`. It is provided for convenience
     * but it is not implemented inside the typeclass.
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
     * @todo
     * Support lazy sequence traits.
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

    template <typename Iter>
    using head = rules::head_impl<Iter>;

    template <typename Iter>
    using last = rules::last_impl<Iter>;

    template <typename Iter>
    using tail = rules::tail_impl<Iter>;

    template <typename Iter>
    using init = rules::init_impl<Iter>;

    template <typename Iter, typename Index>
    using at = rules::at_impl<Iter, Index>;

#else

    //! Returns the first element of a non-empty iterable.
    template <typename Iter>
    struct head;

    /*!
     * Extract the elements after the head of a non-empty iterable.
     *
     * Specifically, returns an iterable containing all the elements of the
     * original iterable except the first one.
     */
    template <typename Iter>
    struct tail;

    //! Returns the last element of a non-empty iterable.
    template <typename Iter>
    struct last;

    /*!
     * Extract the elements before the last of a non-empty iterable.
     *
     * Specifically, returns an iterable containing all the elements of the
     * original iterable except the last one.
     */
    template <typename Iter>
    struct init;

    //! Returns the element of an iterable at the given index.
    template <typename Iter, typename Index>
    struct at;

#endif

    //! Boolean `StaticConstant` representing whether the iterable is empty.
    template <typename Iter>
    BOOST_MPL11_DOXYGEN_ALIAS(is_empty, rules::is_empty_impl<Iter>);

    //! Equivalent to `at_c<Iter, size_t<Index>>`.
    template <typename Iter, detail::std_size_t Index>
    BOOST_MPL11_DOXYGEN_ALIAS(at_c, at<Iter, size_t<Index>>);

    //! `StaticConstant` of unsigned type representing the number of
    //! elements in a finite iterable.
    template <typename Iter>
    BOOST_MPL11_DOXYGEN_ALIAS(length, rules::length_impl<Iter>);

    /*!
     * Invokes a metafunction class with the contents of a finite iterable.
     *
     * Specifically, `unpack<Iter, F>` is a nullary metafunction equivalent
     * to `apply<F, a0, ..., an>`, where `a0`, ...,`an` are the elements
     * in the iterable.
     */
    template <typename Iter, typename F>
    BOOST_MPL11_DOXYGEN_ALIAS(unpack, rules::unpack_impl<Iter, F>);


    template <typename Iter>
    using head_t = typename head<Iter>::type;

    template <typename Iter>
    using tail_t = typename tail<Iter>::type;

    template <typename Iter>
    using is_empty_t = typename is_empty<Iter>::type;

    template <typename Iter>
    using last_t = typename last<Iter>::type;

    template <typename Iter>
    using init_t = typename init<Iter>::type;

    template <typename Iter, detail::std_size_t Index>
    using at_c_t = typename at_c<Iter, Index>::type;

    template <typename Iter, typename Index>
    using at_t = typename at<Iter, Index>::type;

    template <typename Iter>
    using length_t = typename length<Iter>::type;

    template <typename Iter, typename F>
    using unpack_t = typename unpack<Iter, F>::type;

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
     * ### `foldl<F, State, Iter>`
     * Reduces an iterable using a binary operation, from left to right.
     *
     * Specifically, returns the result of the successive application of the
     * binary operation `F` to the result of the previous `F` invocation (or
     * `State` for the first application) and every element of the iterable
     * in order.
     *
     * Visually, with `Iter = x1, x2, ..., xn`:
     *
            foldl(F, State, Iter) == F(...F(F(State, x1), x2)..., xn)
     *
     *
     *
     * ### `foldr<F, State, Iter>`
     * Reduces an iterable using a binary operator, from right to left.
     *
     * Specifically, returns the result of the successive application of the
     * binary operation `F` to every element of the iterable and the result
     * of the next `F` invocation (or `State` for the last application).
     *
     * Visually, with `Iter = x1, x2, ..., xn`:
     *
            foldr(F, State, Iter) == F(x1, F(x2, ...F(xn, State)...))
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
     * ### `fmap<F, Iter>`
     * Returns the result of applying `F` to each element of the iterable.
     */
    template <>
    struct Functor<iterable_tag> BOOST_MPL11_IF_DOXYGEN({ });


    //! Returns an iterable with an element prepended to it.
    template <typename Head, typename Tail>
    struct cons;

    template <typename Head, typename Tail>
    using cons_t = typename cons<Head, Tail>::type;


    /*!
     * Returns an iterable containing the suffix of another iterable after
     * the first `N` elements.
     *
     * `N` must be a non-negative `StaticConstant` representing the number of
     * elements to be dropped from the underlying iterable. If `N` is greater
     * than the length of the iterable, the returned iterable is empty.
     *
     *
     * @todo
     * Try optimizing the recursion in the implementation.
     */
#if defined(BOOST_MPL11_ENABLE_ASSERTIONS)
    template <typename N, typename Iter>
    struct drop;
#else
    template <typename N, typename Iter>
    using drop = rules::drop_impl<N, Iter>;
#endif

    template <typename N, typename Iter>
    using drop_t = typename drop<N, Iter>::type;

    //! Equivalent to `drop<size_t<N>, Iter>`; provided for convenience.
    template <detail::std_size_t N, typename Iter>
    using drop_c = drop<size_t<N>, Iter>;

    template <detail::std_size_t N, typename Iter>
    using drop_c_t = typename drop<size_t<N>, Iter>::type;


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
     * Try optimizing the recursion in the implementation.
     */
    template <typename Predicate, typename Iter>
    struct drop_while;

    template <typename Predicate, typename Iter>
    using drop_while_t = typename drop_while<Predicate, Iter>::type;


    //! Equivalent to `drop_while` with a negated `Predicate`.
    template <typename Predicate, typename Iter>
    using drop_until = drop_while<compose<quote<not_>, Predicate>, Iter>;

    template <typename Predicate, typename Iter>
    using drop_until_t = typename drop_until<Predicate, Iter>::type;


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
    template <typename Predicate, typename Iter>
    using filter = rules::filter_impl<Predicate, Iter>;

    template <typename Predicate, typename Iter>
    using filter_t = typename filter<Predicate, Iter>::type;


    /*!
     * Returns an infinite iterable containing repeated applications of a
     * metafunction class to an initial argument.
     */
    template <typename F, typename X>
    struct iterate;

    template <typename F, typename X>
    using iterate_t = typename iterate<F, X>::type;


    /*!
     * Concatenate several iterables.
     *
     * When invoked with `0` iterables, `join` returns an empty iterable.
     * When invoked with `1` iterables, `join` returns the iterable itself.
     *
     *
     * @todo
     * - Optimize last, init and at.
     * - Should we receive variadic arguments or an iterable of iterables?
     * - Consider using drop_while instead of hand-written recursion.
     */
    template <typename ...Iters>
    struct join;

    template <typename ...Iters>
    using join_t = typename join<Iters...>::type;


    //! Returns an infinite iterable containing copies of the given type.
    template <typename T>
    struct repeat;

    template <typename T>
    using repeat_t = typename repeat<T>::type;


    //! Returns the elements of an iterable in reverse order.
    template <typename Iter>
    using reverse = rules::reverse_impl<Iter>;

    template <typename Iter>
    using reverse_t = typename reverse<Iter>::type;


    /*!
     * `scanl` is similar to `foldl`, but returns an iterable of successive
     * reduced values from the left.
     */
    template <typename F, typename State, typename Iter>
    struct scanl;

    template <typename F, typename State, typename Iter>
    using scanl_t = typename scanl<F, State, Iter>::type;


    /*!
     * Returns a subrange of an iterable.
     *
     * Specifically, `slice` returns the elements in the subrange delimited
     * by [`Start`, `Stop`). In all cases, `Start` must be non-negative and
     * less-than or equal to `Stop`. If the iterable is finite, `Stop` must
     * always be less-than or equal to `length<Iter>`.
     *
     *
     * @todo
     * Reintroduce optimizations that were lost when using a single
     * typeclass for iterables.
     */
    template <typename Iter, typename Start, typename Stop>
    struct slice;

    template <typename Iter, typename Start, typename Stop>
    using slice_t = typename slice<Iter, Start, Stop>::type;

    //! Equivalent to `slice<Iter, size_t<Start>, size_t<Stop>>`.
    template <typename Iter, detail::std_size_t Start, detail::std_size_t Stop>
    using slice_c = slice<Iter, size_t<Start>, size_t<Stop>>;

    template <typename Iter, detail::std_size_t Start, detail::std_size_t Stop>
    using slice_c_t = typename slice<Iter, size_t<Start>, size_t<Stop>>::type;


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
    template <typename Predicate, typename Iter>
    struct sort_by;

    template <typename Predicate, typename Iter>
    using sort_by_t = typename sort_by<Predicate, Iter>::type;


    /*!
     * Returns an iterable containing the first `N` elements of
     * another iterable.
     *
     * `N` must be a non-negative `StaticConstant` representing the number of
     * elements to keep in the underlying iterable. If `N` is greater than
     * the length of the iterable, all of its elements are kept.
     */
#if defined(BOOST_MPL11_ENABLE_ASSERTIONS)
    template <typename N, typename Iter>
    struct take;
#else
    template <typename N, typename Iter>
    using take = rules::take_impl<N, Iter>;
#endif

    template <typename N, typename Iter>
    using take_t = typename take<N, Iter>::type;

    //! Equivalent to `take<size_t<N>, Iter>`.
    template <detail::std_size_t N, typename Iter>
    using take_c = take<size_t<N>, Iter>;

    template <detail::std_size_t N, typename Iter>
    using take_c_t = typename take<size_t<N>, Iter>::type;


    /*!
     * Returns the longest prefix of an iterable in which all elements
     * satisfy the `Predicate`.
     */
    template <typename Predicate, typename Iter>
    struct take_while;

    template <typename Predicate, typename Iter>
    using take_while_t = typename take_while<Predicate, Iter>::type;


    //! Equivalent to `take_while` with a negated `Predicate`.
    template <typename Predicate, typename Iter>
    using take_until = take_while<compose<quote<not_>, Predicate>, Iter>;

    template <typename Predicate, typename Iter>
    using take_until_t = typename take_until<Predicate, Iter>::type;


    /*!
     * Returns an iterable that aggregates elements from several iterables.
     *
     * Specifically, the i-th element of the iterable is a `list` containing
     * the i-th element of each zipped iterable. The iterable stops when the
     * shortest zipped iterable is exhausted. When invoked with 0 iterables,
     * `zip` returns an empty iterable. When invoked with 1 iterable, `zip`
     * returns an iterable of 1-element `list`s.
     *
     *
     * @todo
     * Consider implementing a `zip_longest` with the obvious semantics.
     */
    template <typename ...Iters>
    struct zip;

    template <typename ...Iters>
    using zip_t = typename zip<Iters...>::type;
    //! @}
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_ITERABLE_HPP
