/*!
 * @file
 * Includes the whole _mpl11_ library.
 */

#ifndef BOOST_MPL11_HPP
#define BOOST_MPL11_HPP

/*!
 * @page Concepts Concepts
 *
 * @subpage Categorizable
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
 * @subpage FrontExtensibleSequence
 * @subpage BackExtensibleSequence
 * @subpage RandomExtensibleSequence
 * @subpage ExtensibleAssociativeSequence
 *
 * @subpage ForwardIterator
 * @subpage BidirectionalIterator
 * @subpage RandomAccessIterator
 */

/*!
 * @page Categorizable Categorizable
 *
 * The most basic concept modeled by all types manipulated by the library.
 *
 *
 * ## Notation
 * | Expression | Description
 * | ---------- | -----------
 * | `T`        | An arbitrary type
 *
 *
 * ## Valid expressions
 * | Expression             | Type
 * | ----------             | ----
 * | `category_of<T>::type` | Any type
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
 * | Expression          | Type
 * | ----------          | ----
 * | `begin<S>::type`    | @ref ForwardIterator
 * | `end<S>::type`      | @ref ForwardIterator
 * | `size<S>::type`     | @ref IntegralConstant
 * | `is_empty<S>::type` | Boolean @ref IntegralConstant
 * | `front<S>::type`    | Any type
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
 * | Expression       | Type
 * | ----------       | ----
 * | `begin<S>::type` | @ref BidirectionalIterator
 * | `end<S>::type`   | @ref BidirectionalIterator
 * | `back<S>::type`  | Any type
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
 * | Expression       | Type
 * | ----------       | ----
 * | `begin<S>::type` | @ref RandomAccessIterator
 * | `end<S>::type`   | @ref RandomAccessIterator
 * | `at<S, N>::type` | Any type
 */

/*!
 * @page AssociativeSequence Associative Sequence
 *
 * @ref ForwardSequence allowing retrieval of elements based on keys.
 *
 * Unlike associative containers in the C++ Standard Library, MPL
 * @ref AssociativeSequence "Associative Sequences" have no associated
 * ordering relation. Instead, type equality is used to impose an equivalence
 * relation on keys, and the order in which sequence elements are traversed
 * during iteration is left unspecified.
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
 * | `K`, `Def` | Arbitrary types
 * | `E`        | An element of `S`
 *
 *
 * ## Valid expressions
 * | Expression             | Type
 * | ----------             | ----
 * | `has_key<S, K>::type`  | Boolean @ref IntegralConstant
 * | `at<S, K>::type`       | Any type
 * | `at<S, K, Def>::type`  | Any type
 * | `key_of<S, E>::type`   | Any type
 * | `value_of<S, E>::type` | Any type
 */

/*!
 * @page BackExtensibleSequence Back Extensible Sequence
 *
 * Sequence supporting insertion and removal of elements at the end.
 *
 *
 * ## Refinement of
 * @ref Categorizable
 *
 *
 * ## Notation
 * | Expression | Description
 * | ---------- | -----------
 * | `S`        | A @ref BackExtensibleSequence
 * | `E`        | An element of `S`
 *
 *
 * ## Valid expressions
 * | Expression              | Type
 * | ----------              | ----
 * | `push_back<S, E>::type` | @ref BackExtensibleSequence
 * | `pop_back<S>::type`     | @ref BackExtensibleSequence
 * | `clear<S>::type`        | @ref BackExtensibleSequence
 */

/*!
 * @page FrontExtensibleSequence Front Extensible Sequence
 *
 * Sequence supporting insertion and removal of elements at the beginning.
 *
 *
 * ## Refinement of
 * @ref Categorizable
 *
 *
 * ## Notation
 * | Expression | Description
 * | ---------- | -----------
 * | `S`        | A @ref FrontExtensibleSequence
 * | `E`        | An element of `S`
 *
 *
 * ## Valid expressions
 * | Expression               | Type
 * | ----------               | ----
 * | `push_front<S, E>::type` | @ref FrontExtensibleSequence
 * | `pop_front<S>::type`     | @ref FrontExtensibleSequence
 * | `clear<S>::type`         | @ref FrontExtensibleSequence
 */

/*!
 * @page RandomExtensibleSequence Random Extensible Sequence
 *
 * Sequence supporting insertion and removal of elements at any position.
 *
 *
 * ## Refinement of
 * @ref BackExtensibleSequence, @ref FrontExtensibleSequence
 *
 *
 * ## Notation
 * | Expression             | Description
 * | ----------             | -----------
 * | `S`                    | A @ref RandomExtensibleSequence
 * | `First`, `Last`, `Pos` | Iterators of `S`
 * | `E`                    | An arbitrary type
 * | `R`                    | A @ref ForwardSequence
 *
 *
 * ## Valid expressions
 * | Expression                      | Type
 * | ----------                      | ----
 * | `insert<S, Pos, E>::type`       | @ref RandomExtensibleSequence
 * | `insert_range<S, Pos, R>::type` | @ref RandomExtensibleSequence
 * | `erase<S, Pos>::type`           | @ref RandomExtensibleSequence
 * | `erase<S, First, Last>::type`   | @ref RandomExtensibleSequence
 * | `clear<S>::type`                | @ref RandomExtensibleSequence
 */

/*!
 * @page ExtensibleAssociativeSequence Extensible Associative Sequence
 *
 * Sequence supporting insertion and removal of elements based on their key.
 *
 *
 * ## Refinement of
 * @ref Categorizable
 *
 *
 * ## Notation
 * | Expression | Description
 * | ---------- | -----------
 * | `S`        | A @ref ExtensibleAssociativeSequence
 * | `E`        | A type compatible to be used as an element of `S`
 * | `K`        | An arbitrary type
 * | `R`        | A @ref ForwardSequence
 *
 *
 * ## Valid expressions
 * | Expression                 | Type
 * | ----------                 | ----
 * | `insert<S, E>::type`       | @ref ExtensibleAssociativeSequence
 * | `insert_range<S, R>::type` | @ref ExtensibleAssociativeSequence
 * | `erase_key<S, K>::type`    | @ref ExtensibleAssociativeSequence
 * | `clear<S>::type`           | @ref ExtensibleAssociativeSequence
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
 * @ref Categorizable
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
 * | Expression       | Type
 * | ----------       | ----
 * | `deref<I>::type` | Any type
 * | `next<I>::type`  | @ref ForwardIterator
 *
 *
 * ## Invariants
 * - `I` and `J` are equal if and only if they are pointing to the same
 *   element.
 * - If `I` is dereferenceable and `J` is equal to `I`, then `J` is
 *   dereferenceable as well.
 * - If `I` and `J` are equal and dereferenceable, then `deref<I>::type`
 *   and `deref<J>::type` are equal.
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
 * | Expression       | Type
 * | ----------       | ----
 * | `next<I>::type`  | @ref BidirectionalIterator
 * | `prior<I>::type` | @ref BidirectionalIterator
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
 * @ref BidirectionalIterator
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
 * | Expression            | Type                      | Complexity
 * | ----------            | ----                      | ----------
 * | `next<I>::type`       | @ref RandomAccessIterator | Constant time
 * | `prior<I>::type`      | @ref RandomAccessIterator | Constant time
 * | `advance<I, N>::type` | @ref RandomAccessIterator | Constant time
 * | `distance<I, J>::type | @ref IntegralConstant     | Constant time
 *
 *
 * ## Invariants
 * - If `advance_c<I, N::value>::type` is well-defined, then
 *   `advance_c<advance_c<I, N::value>::type, -N::value>::type`
 *   is equal to `I`.
 */

/*!
 * @page IntegralConstant Integral Constant
 * @todo Document this concept
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

#include <boost/mpl11/adaptor.hpp>
#include <boost/mpl11/algorithms.hpp>
#include <boost/mpl11/always.hpp>
#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/apply_wrap.hpp>
#include <boost/mpl11/arg.hpp>
#include <boost/mpl11/as_placeholder.hpp>
#include <boost/mpl11/bind.hpp>
#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/categories.hpp>
#include <boost/mpl11/containers.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/empty_base.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/if.hpp>
#include <boost/mpl11/inherit.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/intrinsics.hpp>
#include <boost/mpl11/is_placeholder.hpp>
#include <boost/mpl11/is_placeholder_expression.hpp>
#include <boost/mpl11/iterators.hpp>
#include <boost/mpl11/lambda.hpp>
#include <boost/mpl11/pair.hpp>
#include <boost/mpl11/quote.hpp>
#include <boost/mpl11/tags.hpp>
#include <boost/mpl11/tests.hpp>
#include <boost/mpl11/unpack_args.hpp>
#include <boost/mpl11/views.hpp>

#endif // !BOOST_MPL11_HPP
