/*!
 * @file
 * Forward declares the `boost::mpl11::Sequence` module.
 */

#ifndef BOOST_MPL11_FWD_SEQUENCE_HPP
#define BOOST_MPL11_FWD_SEQUENCE_HPP

#include <boost/mpl11/detail/doxygen.hpp>
#include <boost/mpl11/detail/std_size_t.hpp>
#include <boost/mpl11/fwd/comparable.hpp>
#include <boost/mpl11/fwd/foldable.hpp>
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
     * @defgroup Sequence Sequence
     *
     * Collection of objects.
     *
     * @todo Write more information about this.
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
     * - `Comparable` when the elements in the sequence are `Comparable`.
     * - `Orderable` when the elements in the sequence are `Orderable`.
     * - `Foldable`
     *
     *
     * @note
     * `Sequence`s are not required to be finite. If a `Sequence` is infinite,
     * some methods such as `length` and `unpack` are not well-defined. The
     * well-definedness of some other methods such as `init` and `last`
     * depends on the particular sequence.
     *
     * @{
     */
    template <typename Tag>
    struct Sequence;

    /*!
     * Tag representing the `Sequence` typeclass.
     *
     * @ingroup tags
     */
    struct sequence_tag BOOST_MPL11_IF_DOXYGEN({ });

#if !defined(BOOST_MPL11_ENABLE_ASSERTIONS)

    template <typename S>                       using head = head_impl<S>;
    template <typename S>                       using last = last_impl<S>;
    template <typename S>                       using tail = tail_impl<S>;
    template <typename S>                       using init = init_impl<S>;
    template <typename S, detail::std_size_t I> using at_c = at_c_impl<S, I>;

#else

    //! Returns the first element of a non-empty `Sequence`.
    template <typename S>
    struct head;

    /*!
     * Extract the elements after the head of a non-empty `Sequence`.
     *
     * Specifically, returns a sequence containing all the elements of the
     * original sequence except the first one.
     */
    template <typename S>
    struct tail;

    //! Returns the last element of a non-empty `Sequence`.
    template <typename S>
    struct last;

    /*!
     * Extract the elements before the last of a non-empty `Sequence`.
     *
     * Specifically, returns a sequence containing all the elements of the
     * original sequence except the last one.
     */
    template <typename S>
    struct init;

    //! Returns the element of a `Sequence` at the given index.
    template <typename S, detail::std_size_t Index>
    struct at_c;

#endif

    //! Boolean `StaticConstant` representing whether the given `Sequence`
    //! is empty.
    template <typename S>
    BOOST_MPL11_DOXYGEN_ALIAS(is_empty, is_empty_impl<S>);

    //! Equivalent to `at_c<S, Index::value>`;
    //! requires a non-negative `Index`.
    template <typename S, typename Index>
    struct at;

    //! `StaticConstant` of unsigned type representing the number of
    //! elements in a finite `Sequence`.
    template <typename S>
    BOOST_MPL11_DOXYGEN_ALIAS(length, length_impl<S>);

    /*!
     * Invokes a metafunction class with the contents of a finite `Sequence`.
     *
     * Specifically, `unpack<S, F>` is a nullary metafunction equivalent
     * to `apply<F, a0, ..., an>`, where `a0`, ...,`an` are the elements
     * in the sequence.
     */
    template <typename S, typename F>
    BOOST_MPL11_DOXYGEN_ALIAS(unpack, unpack_impl<S, F>);


    template <typename S>
    using head_t = typename head<S>::type;

    template <typename S>
    using tail_t = typename tail<S>::type;

    template <typename S>
    using is_empty_t = typename is_empty<S>::type;

    template <typename S>
    using last_t = typename last<S>::type;

    template <typename S>
    using init_t = typename init<S>::type;

    template <typename S, detail::std_size_t Index>
    using at_c_t = typename at_c<S, Index>::type;

    template <typename S, typename Index>
    using at_t = typename at<S, Index>::type;

    template <typename S>
    using length_t = typename length<S>::type;

    template <typename S, typename F>
    using unpack_t = typename unpack<S, F>::type;

    //! Defines the default operations for `Sequence`s.
    template <>
    struct Sequence<sequence_tag> BOOST_MPL11_IF_DOXYGEN({ });

    /*!
     * Default instantiation of the `Comparable` typeclass for `Sequence`s.
     *
     * Two `Sequence`s are equal if their elements are equal when compared
     * side-by-side, and if both sequences run out of elements at the same
     * time, i.e. if they have the same length. The inequality of two
     * `Sequence`s is defined in terms of their equality.
     */
    template <>
    struct Comparable<sequence_tag, sequence_tag> BOOST_MPL11_IF_DOXYGEN({ });

    /*!
     * Default instantiation of the `Orderable` typeclass for `Sequence`s.
     *
     * Less-than comparison for `Sequence`s is defined as the lexicographical
     * comparison of their elements. Other comparison operators are defined
     * in terms of the less-than comparison.
     */
    template <>
    struct Orderable<sequence_tag, sequence_tag> BOOST_MPL11_IF_DOXYGEN({ });

    /*!
     * Default instantiation of the `Foldable` typeclass for `Sequence`s.
     *
     *
     * ### `foldl<F, State, Seq>`
     * Reduces a sequence using a binary operation, from left to right.
     *
     * Specifically, returns the result of the successive application of the
     * binary operation `F` to the result of the previous `F` invocation (or
     * `State` for the first application) and every element of the sequence
     * in order.
     *
     * Visually, with a sequence `Seq = x1, x2, ..., xn`:
     *
            foldl(F, State, Seq) == F(...F(F(State, x1), x2)..., xn)
     *
     *
     *
     * ### `foldr<F, State, Seq>`
     * Reduces a sequence using a binary operator, from right to left.
     *
     * Specifically, returns the result of the successive application of the
     * binary operation `F` to every element of the sequence and the result
     * of the next `F` invocation (or `State` for the last application).
     *
     * Visually, with `Seq = x1, x2, ..., xn`:
     *
            foldr(F, State, Seq) == F(x1, F(x2, ...F(xn, State)...))
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
    struct Foldable<sequence_tag> BOOST_MPL11_IF_DOXYGEN({ });


    /*!
     * Returns a sequence containing the suffix of another sequence after
     * the first `N` elements.
     *
     * `N` must be a non-negative `StaticConstant` representing the number of
     * elements to be dropped from the underlying sequence. If `N` is greater
     * than the length of the sequence, the returned sequence is empty.
     */
    template <typename N, typename Sequence>
    struct drop;

    template <typename N, typename Sequence>
    using drop_t = typename drop<N, Sequence>::type;

    //! Equivalent to `drop<size_t<N>, Sequence>`.
    template <detail::std_size_t N, typename Sequence>
    struct drop_c;

    template <detail::std_size_t N, typename Sequence>
    using drop_c_t = typename drop_c<N, Sequence>::type;

    /*!
     * Drops elements from a sequence up to, but not including, the first
     * element for which the `Predicate` returns `false`.
     *
     * Specifically, `drop_while` returns a sequence containing all the
     * elements of the underlying sequence except for those in the range
     * delimited by [`head`, `e`), where `head` is the first element of
     * the sequence and `e` is the first element for which the `Predicate`
     * returns `false`.
     *
     *
     * @todo
     * Use a less naive `consume` implementation.
     */
    template <typename Predicate, typename Sequence>
    struct drop_while;

    template <typename Predicate, typename Sequence>
    using drop_while_t = typename drop_while<Predicate, Sequence>::type;


    /*!
     * Returns a `Sequence` containing the first `N` elements of
     * another sequence.
     *
     * `N` must be a non-negative `StaticConstant` representing the number of
     * elements to keep in the underlying sequence. If `N` is greater than
     * the length of the sequence, all of its elements are kept.
     */
    template <typename N, typename Sequence>
    struct take;

    template <typename N, typename Sequence>
    using take_t = typename take<N, Sequence>::type;

    //! Equivalent to `take<size_t<N>, Sequence>`.
    template <detail::std_size_t N, typename Sequence>
    struct take_c;

    template <detail::std_size_t N, typename Sequence>
    using take_c_t = typename take_c<N, Sequence>::type;

    /*!
     * Returns the longest prefix of a sequence in which all elements
     * satisfy the given `Predicate`.
     */
    template <typename Predicate, typename Sequence>
    struct take_while;

    template <typename Predicate, typename Sequence>
    using take_while_t = take_while<Predicate, Sequence>;
    //! @}
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_SEQUENCE_HPP
