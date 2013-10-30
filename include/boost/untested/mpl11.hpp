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
