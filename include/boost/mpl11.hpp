/*!
 * @file
 * Includes the whole _mpl11_ library.
 */

#ifndef BOOST_MPL11_HPP
#define BOOST_MPL11_HPP

/*!
 * @defgroup details Details
 *
 * Implementation details.
 */

/*!
 * @defgroup datatypes Data types
 *
 * First-class constructs for manipulating data at compile-time.
 */

/*!
 * @defgroup sequences Sequences
 * @ingroup datatypes
 *
 * Types representing collections of other types.
 */

#ifdef BOOST_MPL11_DOXYGEN_INVOKED
/*!
 * @ingroup concepts
 *
 * A `Metafunction` is a class or a class template that represents a
 * function invocable at compile-time.
 *
 * An non-nullary metafunction is invoked by instantiating the class
 * template with particular template parameters (metafunction arguments);
 * the result of the metafunction application is accessible through the
 * instantiation's nested `type` alias. All metafunction's arguments must
 * be types (i.e. only type template parameters are allowed). A
 * metafunction can have a variable number of parameters. A nullary
 * metafunction is represented as a (template) class with a nested `type`
 * typename member.
 *
 *
 * ## Notation
 * | Expression | Description
 * | ---------- | -----------
 * | `F`        | A `Metafunction`
 * | `Args...`  | An arbitrary sequence of types
 *
 *
 * ## Valid expressions
 * | Expression                      | Type
 * | ----------                      | ----
 * | `F<Args...>::type` or `F::type` | Any type
 *
 *
 * @note
 * This concept only lives in the documentation. There exists no such
 * `struct` in the library.
 */
struct Metafunction { };
#endif

/*!
 * @defgroup metafunctions Metafunctions
 *
 * `Metafunction`s provided by the library.
 */

/*!
 * @defgroup algorithms Algorithms
 * @ingroup metafunctions
 *
 * Generic algorithms manipulating @ref datatypes through their intrinsics.
 */

/*!
 * @defgroup intrinsics Intrinsics
 * @ingroup metafunctions
 *
 * Metafunctions forming the essential interface of @ref datatypes.
 *
 * Intrinsics use a special dispatching system to allow their behavior to
 * be customized easily.
 *
 *
 * @todo Document the dispatching system.
 */

/*!
 * @defgroup concepts Concepts
 *
 * Concepts upon which the library is built.
 *
 * In this library, concepts are more than just documented syntaxic and
 * semantic requirements about types. Each concept is also a C++ class
 * that can be used as mixin to ease the implementation of the concept.
 *
 *
 * @todo
 * Expand upon the usage and composition of concepts as mixins.
 */

#include <boost/mpl11/add.hpp>
#include <boost/mpl11/advance.hpp>
#include <boost/mpl11/all_of.hpp>
#include <boost/mpl11/always.hpp>
#include <boost/mpl11/and.hpp>
#include <boost/mpl11/any_of.hpp>
#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/arg.hpp>
#include <boost/mpl11/args.hpp>
#include <boost/mpl11/arithmetic.hpp>
#include <boost/mpl11/associative_container.hpp>
#include <boost/mpl11/associative_sequence.hpp>
#include <boost/mpl11/at.hpp>
#include <boost/mpl11/at_key.hpp>
#include <boost/mpl11/back.hpp>
#include <boost/mpl11/back_extensible_container.hpp>
#include <boost/mpl11/begin.hpp>
#include <boost/mpl11/bidirectional_iterator.hpp>
#include <boost/mpl11/bidirectional_sequence.hpp>
#include <boost/mpl11/bitand.hpp>
#include <boost/mpl11/bitor.hpp>
#include <boost/mpl11/bitwise.hpp>
#include <boost/mpl11/bitxor.hpp>
#include <boost/mpl11/class_of.hpp>
#include <boost/mpl11/clear.hpp>
#include <boost/mpl11/comparable.hpp>
#include <boost/mpl11/compose.hpp>
#include <boost/mpl11/container.hpp>
#include <boost/mpl11/contains.hpp>
#include <boost/mpl11/count.hpp>
#include <boost/mpl11/count_if.hpp>
#include <boost/mpl11/couple.hpp>
#include <boost/mpl11/deref.hpp>
#include <boost/mpl11/directional_sequence.hpp>
#include <boost/mpl11/distance.hpp>
#include <boost/mpl11/divide.hpp>
#include <boost/mpl11/empty_base.hpp>
#include <boost/mpl11/end.hpp>
#include <boost/mpl11/equal.hpp>
#include <boost/mpl11/erase.hpp>
#include <boost/mpl11/erase_key.hpp>
#include <boost/mpl11/erase_keys.hpp>
#include <boost/mpl11/erase_range.hpp>
#include <boost/mpl11/filter.hpp>
#include <boost/mpl11/find.hpp>
#include <boost/mpl11/find_if.hpp>
#include <boost/mpl11/first.hpp>
#include <boost/mpl11/flip.hpp>
#include <boost/mpl11/foldl.hpp>
#include <boost/mpl11/foldr.hpp>
#include <boost/mpl11/forward_iterator.hpp>
#include <boost/mpl11/front.hpp>
#include <boost/mpl11/front_extensible_container.hpp>
#include <boost/mpl11/greater.hpp>
#include <boost/mpl11/greater_equal.hpp>
#include <boost/mpl11/has_key.hpp>
#include <boost/mpl11/has_optimization.hpp>
#include <boost/mpl11/hash.hpp>
#include <boost/mpl11/hashable.hpp>
#include <boost/mpl11/hset.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/if.hpp>
#include <boost/mpl11/imap.hpp>
#include <boost/mpl11/inherit.hpp>
#include <boost/mpl11/insert.hpp>
#include <boost/mpl11/insert_key.hpp>
#include <boost/mpl11/insert_keys.hpp>
#include <boost/mpl11/insert_range.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/integral_constant.hpp>
#include <boost/mpl11/into.hpp>
#include <boost/mpl11/is_empty.hpp>
#include <boost/mpl11/iterator_range.hpp>
#include <boost/mpl11/join.hpp>
#include <boost/mpl11/key_of.hpp>
#include <boost/mpl11/less.hpp>
#include <boost/mpl11/less_equal.hpp>
#include <boost/mpl11/logical.hpp>
#include <boost/mpl11/max.hpp>
#include <boost/mpl11/min.hpp>
#include <boost/mpl11/modulo.hpp>
#include <boost/mpl11/multiply.hpp>
#include <boost/mpl11/new.hpp>
#include <boost/mpl11/next.hpp>
#include <boost/mpl11/none_of.hpp>
#include <boost/mpl11/not.hpp>
#include <boost/mpl11/not_equal.hpp>
#include <boost/mpl11/optimization.hpp>
#include <boost/mpl11/or.hpp>
#include <boost/mpl11/orderable.hpp>
#include <boost/mpl11/pair.hpp>
#include <boost/mpl11/partial.hpp>
#include <boost/mpl11/pop_back.hpp>
#include <boost/mpl11/pop_front.hpp>
#include <boost/mpl11/prev.hpp>
#include <boost/mpl11/push_back.hpp>
#include <boost/mpl11/push_front.hpp>
#include <boost/mpl11/quote.hpp>
#include <boost/mpl11/random_access_iterator.hpp>
#include <boost/mpl11/random_access_sequence.hpp>
#include <boost/mpl11/random_extensible_container.hpp>
#include <boost/mpl11/second.hpp>
#include <boost/mpl11/shift_left.hpp>
#include <boost/mpl11/shift_right.hpp>
#include <boost/mpl11/size.hpp>
#include <boost/mpl11/subtract.hpp>
#include <boost/mpl11/transform.hpp>
#include <boost/mpl11/unpack.hpp>
#include <boost/mpl11/value_of.hpp>
#include <boost/mpl11/vector.hpp>

#endif // !BOOST_MPL11_HPP
