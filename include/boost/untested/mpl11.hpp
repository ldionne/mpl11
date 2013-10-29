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
 * @defgroup views Views
 * A view is a sequence adaptor providing a lazily-altered presentation of
 * one or more underlying sequences.
 */

#endif // !BOOST_MPL11_HPP
