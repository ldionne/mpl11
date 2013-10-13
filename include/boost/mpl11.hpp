/*!
 * @file
 * Includes the whole _mpl11_ library.
 */

#ifndef BOOST_MPL11_HPP
#define BOOST_MPL11_HPP

/*!
 * @page Concepts Concepts
 *
 * @subpage Category
 * @subpage Categorizable
 *
 * @subpage EqualityComparable
 * @subpage LessThanComparable
 *
 * @subpage IntegralConstant
 *
 * @subpage Metafunction
 * @subpage MetafunctionClass
 * @subpage Placeholder
 * @subpage PlaceholderExpression
 * @subpage LambdaExpression
 *
 * @subpage ForwardSequence
 * @subpage BidirectionalSequence
 * @subpage RandomAccessSequence
 * @subpage AssociativeSequence
 *
 * @subpage ForwardIterator
 * @subpage BidirectionalIterator
 * @subpage RandomAccessIterator
 */

/*!
 * @page Category Category
 * @todo Document this concept
 */

/*!
 * @page Categorizable Categorizable
 *
 * Type that is in some classification and whose position in that
 * classification is available.
 *
 *
 * ## Notation
 * | Expression | Description
 * | ---------- | -----------
 * | `T`        | @ref Categorizable
 *
 *
 * ## Valid expressions
 * | Expression             | Type
 * | ----------             | ----
 * | `category_of<T>::type` | @ref Category
 */

/*!
 * @page EqualityComparable Equality Comparable
 *
 * Type possessing an equivalence relation.
 *
 *
 * ## Notation
 * | Expression | Description
 * | ---------- | -----------
 * | `T`, `U`   | Arbitrary @ref EqualityComparable "Equality Comparables"
 *
 *
 * ## Valid expressions
 * | Expression                 | Type
 * | ----------                 | ----
 * | `equal_to<T, U>::type`     | Boolean @ref IntegralConstant
 * | `not_equal_to<T, U>::type` | Boolean @ref IntegralConstant
 */

/*!
 * @page LessThanComparable LessThan Comparable
 *
 * Type possessing a strict weak ordering relation.
 *
 *
 * ## Notation
 * | Expression | Description
 * | ---------- | -----------
 * | `T`, `U`   | Arbitrary @ref LessThanComparable "LessThan Comparables"
 *
 *
 * ## Valid expressions
 * | Expression                  | Type
 * | ----------                  | ----
 * | `less<T, U>::type`          | Boolean @ref IntegralConstant
 * | `less_equal<T, U>::type`    | Boolean @ref IntegralConstant
 * | `greater<T, U>::type`       | Boolean @ref IntegralConstant
 * | `greater_equal<T, U>::type` | Boolean @ref IntegralConstant
 */

/*!
 * @page ForwardSequence Forward Sequence
 *
 * Compile-time sequence allowing iteration through the elements of the
 * sequence in one direction.
 *
 * A @ref ForwardSequence guarantees that its elements are arranged in a
 * definite, but possibly unspecified, order. Every MPL sequence is a
 * @ref ForwardSequence.
 *
 *
 * ## Refinement of
 * @ref Categorizable
 *
 *
 * ## Definitions
 * - The size of a sequence is the number of elements it contains. The size
 *   is a non-negative number.
 * - A sequence is empty if its size is zero.
 *
 *
 * ## Notation
 * | Expression | Description
 * | ---------- | -----------
 * | `S`        | A @ref ForwardSequence
 *
 *
 * ## Valid expressions
 * | Expression             | Type
 * | ----------             | ----
 * | `begin<S>::type`       | @ref ForwardIterator
 * | `end<S>::type`         | @ref ForwardIterator
 * | `category_of<S>::type` | Convertible to `category::forward_sequence`
 *
 *
 * ## Invariants
 * - [`begin<S>::type`, `end<S>::type`) is always a valid range.
 * - An algorithm that iterates through the range
 *   [`begin<S>::type`, `end<S>::type`) will pass
 *   through every element of `S` exactly once.
 * - `begin<S>::type` is equal to `end<S>::type` if and only if `S` is empty.
 * - Two different iterations through `S` will access its elements in the
 *   same order.
 */

/*!
 * @page BidirectionalSequence Bidirectional Sequence
 *
 * @ref ForwardSequence whose iterators model the @ref BidirectionalIterator
 * concept.
 *
 *
 * ## Refinement of
 * @ref ForwardSequence
 *
 *
 * ## Notation
 * | Expression | Description
 * | ---------- | -----------
 * | `S`        | A @ref BidirectionalSequence
 *
 *
 * ## Valid expressions
 * | Expression             | Type
 * | ----------             | ----
 * | `begin<S>::type`       | @ref BidirectionalIterator
 * | `end<S>::type`         | @ref BidirectionalIterator
 * | `category_of<S>::type` | Convertible to `category::bidirectional_sequence`
 */

/*!
 * @page RandomAccessSequence Random Access Sequence
 *
 * @ref BidirectionalSequence whose iterators model the
 * @ref RandomAccessIterator concept.
 *
 *
 * ## Refinement of
 * @ref BidirectionalSequence
 *
 *
 * ## Notation
 * | Expression | Description
 * | ---------- | -----------
 * | `S`        | A @ref RandomAccessSequence
 * | `N`        | An @ref IntegralConstant
 *
 *
 * ## Valid expressions
 * | Expression             | Type
 * | ----------             | ----
 * | `begin<S>::type`       | @ref RandomAccessIterator
 * | `end<S>::type`         | @ref RandomAccessIterator
 * | `category_of<S>::type` | Convertible to `category::random_access_sequence`
 */

/*!
 * @page AssociativeSequence Associative Sequence
 *
 * @ref ForwardSequence allowing retrieval of elements based on keys.
 *
 *
 * ## Refinement of
 * @ref ForwardSequence
 *
 *
 * ## Notation
 * | Expression | Description
 * | ---------- | -----------
 * | `S`        | An @ref AssociativeSequence
 * | `E`        | An element of `S`
 *
 *
 * ## Valid expressions
 * | Expression             | Type
 * | ----------             | ----
 * | `category_of<S>::type` | Convertible to `category::associative_sequence`
 * | `key_of<S, E>::type`   | Any type
 * | `value_of<S, E>::type` | Any type
 */

/*!
 * @page ForwardIterator Forward Iterator
 *
 * Type representing a positional reference to an element of a
 * @ref ForwardSequence.
 *
 * A @ref ForwardIterator allows accessing the element through a dereference
 * operation, and provides a way to obtain an iterator to the next element in
 * the sequence.
 *
 *
 * ## Refinement of
 * @ref Categorizable, @ref EqualityComparable
 *
 *
 * ## Notation
 * | Expression | Description
 * | ---------- | -----------
 * | `I`, `J`   | @ref ForwardIterator "Forward Iterators"
 *
 *
 * ## Definitions
 * - `I` is dereferenceable if `deref<I>::type` is a well-defined expression.
 * - An iterator is past-the-end if it points beyond the last element of a
 *   sequence; past-the-end iterators are non-dereferenceable.
 * - `I` is incrementable if there is a "next" iterator, that is, if
 *   `next<I>::type` is a well-defined expression; past-the-end iterators
 *   are not incrementable.
 * - `J` is reachable from `I` if, after a finite number of recursive
 *   applications of `next` to `I`, `I` is equal to `J`.
 * - The notation [`I`, `J`) refers to a range of iterators beginning with
 *   `I` and up to but not including `J`.
 * - The range [`I`, `J`) is a valid range if `J` is reachable from `I`.
 *
 *
 * ## Valid expressions
 * | Expression             | Type
 * | ----------             | ----
 * | `deref<I>::type`       | Any type
 * | `next<I>::type`        | @ref ForwardIterator
 * | `category_of<I>::type` | Convertible to `category::forward_iterator`
 *
 *
 * ## Invariants
 * - `I` and `J` are equal if and only if they are pointing to the same
 *   element.
 * - If `I` is dereferenceable and `J` is equal to `I`, then `J` is
 *   dereferenceable as well.
 * - If `I` and `J` are equal and dereferenceable, then `deref<I>::type`
 *   and `deref<J>::type` are exactly the same type.
 * - If `I` is incrementable and `J` is equal to `I`, then `J` is
 *   incrementable as well.
 * - If `I` and `J` are equal and incrementable, then `next<I>::type` and
 *   `next<J>::type` are equal.
 */

/*!
 * @page BidirectionalIterator Bidirectional Iterator
 *
 * @ref ForwardIterator providing a way to obtain an iterator to the previous
 * element in the sequence.
 *
 *
 * ## Refinement of
 * @ref ForwardIterator
 *
 *
 * ## Notation
 * | Expression | Description
 * | ---------- | -----------
 * | `I`        | A @ref BidirectionalIterator
 *
 *
 * ## Definitions
 * - `I` is decrementable if there is a "previous" iterator, that is, if
 *   the `prior<I>::type` expression is well-defined; iterators pointing
 *   to the first element of a sequence are not decrementable.
 *
 *
 * ## Valid expressions
 * | Expression             | Type
 * | ----------             | ----
 * | `next<I>::type`        | @ref BidirectionalIterator
 * | `prior<I>::type`       | @ref BidirectionalIterator
 * | `category_of<I>::type` | Convertible to `category::bidirectional_iterator`
 *
 *
 * ## Invariants
 * - If `I` is incrementable, then `prior<next<I>::type>::type` is equal to
 *   `I`; similarly, if `I` is decrementable, `next<prior<I>::type>::type`
 *   is equal to `I`.
 */

/*!
 * @page RandomAccessIterator Random Access Iterator
 *
 * @ref BidirectionalIterator providing constant-time guarantees on moving
 * the iterator an arbitrary number of positions.
 *
 *
 * ## Refinement of
 * @ref BidirectionalIterator, @ref LessThanComparable
 *
 *
 * ## Notation
 * | Expression | Description
 * | ---------- | -----------
 * | `I`, `J`   | @ref RandomAccessIterator "Random Access Iterators"
 * | `N`        | An @ref IntegralConstant
 *
 *
 * ## Valid expressions
 * | Expression             | Type                      | Complexity
 * | ----------             | ----                      | ----------
 * | `next<I>::type`        | @ref RandomAccessIterator | Constant time
 * | `prior<I>::type`       | @ref RandomAccessIterator | Constant time
 * | `advance<I, N>::type`  | @ref RandomAccessIterator | Constant time
 * | `distance<I, J>::type  | @ref IntegralConstant     | Constant time
 * | `category_of<I>::type` | Convertible to `category::random_access_iterator`
 *
 *
 * ## Invariants
 * - If `advance_c<I, N::value>::type` is well-defined, then
 *   `advance_c<advance_c<I, N::value>::type, -N::value>::type`
 *   is equal to `I`.
 */

/*!
 * @page IntegralConstant Integral Constant
 *
 * Holder for a compile-time value of an integral type.
 *
 * Every @ref IntegralConstant is also a nullary @ref Metafunction
 * returning itself. An integral constant object is implicitly convertible
 * to the corresponding runtime value of the wrapped integral type.
 *
 *
 * ## Refinement of
 * @ref Categorizable
 *
 *
 * ## Notation
 * | Expression | Description
 * | ---------- | -----------
 * | `N`        | An @ref IntegralConstant
 *
 *
 * ## Valid expressions
 * | Expression                        | Type
 * | ----------                        | ----
 * | `N::value_type`                   | An integral type
 * | `N::value`                        | An integral constant expression
 * | `N::type`                         | @ref IntegralConstant
 * | `constexpr N::value_type c = N{}` |
 * | `category_of<N>::type`            | Convertible to `category::integral_constant`
 */

/*!
 * @page Metafunction Metafunction
 * @todo Document this concept
 */

/*!
 * @page MetafunctionClass Metafunction Class
 * @todo Document this concept
 */

/*!
 * @page Placeholder Placeholder
 * @todo Document this concept
 */

/*!
 * @page PlaceholderExpression Placeholder Expression
 * @todo Document this concept
 */

/*!
 * @page LambdaExpression Lambda Expression
 * @todo Document this concept
 */

#include <boost/mpl11/algorithms.hpp>
#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/categories.hpp>
#include <boost/mpl11/containers.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/empty_base.hpp>
#include <boost/mpl11/functional.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/if.hpp>
#include <boost/mpl11/inherit.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/intrinsics.hpp>
#include <boost/mpl11/operators.hpp>
#include <boost/mpl11/pair.hpp>
#include <boost/mpl11/views.hpp>

#endif // !BOOST_MPL11_HPP
