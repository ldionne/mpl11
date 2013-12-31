/*!
 * @file
 * Includes the whole library.
 */

#ifndef BOOST_MPL11_HPP
#define BOOST_MPL11_HPP

/*!
 * @defgroup details Details
 *
 * Implementation details.
 */

/*!
 * @defgroup typeclasses Type classes
 *
 * General purpose type classes provided by the library.
 *
 *
 * @todo Explain what are type classes and methods.
 */

/*!
 * @defgroup tags Tags
 *
 * Tags are types used to dispatch methods.
 *
 * Tags come in two flavors (the difference is only conceptual):
 *
 * ### Typeclass tags
 * A typeclass tag is a tag representing a single typeclass. For example,
 * the `forward_sequence_tag` is a typeclass tag because it represents
 * the `ForwardSequence` typeclass. These tags are used as a meeting
 * point between different datatype tags.
 *
 *
 * ### Datatype tags
 * A datatype tag represents a specific datatype. For example,
 * `vector_tag` is a datatype tag because it only represents the
 * `vector` datatype. These tags are only used to make datatypes
 * instances of typeclasses.
 */

/*!
 * @defgroup datatypes Data Types
 *
 * Data types provided by the library.
 *
 *
 * @todo Explain what are data types.
 */

/*!
 * @defgroup metafunctions Metafunctions
 *
 * Metafunctions provided by the library.
 *
 * A metafunction is a class or a class template that represents a
 * function invocable at compile-time.
 *
 * An non-nullary metafunction is invoked by instantiating the class
 * template with particular template parameters (metafunction arguments);
 * the result of the metafunction application is accessible through the
 * instantiation's nested `type` alias. All of a metafunction's arguments
 * must be types (i.e. only type template parameters are allowed). A
 * metafunction can have a variable number of parameters. A nullary
 * metafunction is represented as a (template) class with a nested `type`
 * typename member.
 *
 *
 * ### Notation
 * | Expression | Description
 * | ---------- | -----------
 * | `F`        | A metafunction
 * | `Args...`  | An arbitrary sequence of types
 *
 *
 * ### Valid expressions
 * | Expression                       | Type
 * | ----------                       | ----
 * | `F<Args...>::%type` or `F::type` | Any type
 */

/*!
 * @defgroup metafunction_classes Metafunctions Classes
 *
 * Metafunction classes provided by the library.
 *
 * A metafunction class is a compile-time invokable entity that is
 * first-class in the C++ template system.
 *
 *
 * ### Notation
 * | Expression | Description
 * | ---------- | -----------
 * | `F`        | A metafunction class
 * | `Args...`  | An arbitrary sequence of types
 *
 *
 * ### Valid expressions
 * | Expression                 | Type
 * | ----------                 | ----
 * | `apply<F, Args...>::%type` | Any type
 */


#include <boost/mpl11/always.hpp>
#include <boost/mpl11/and.hpp>
#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/arg.hpp>
#include <boost/mpl11/arithmetic.hpp>
#include <boost/mpl11/bidirectional_sequence.hpp>
#include <boost/mpl11/bitwise.hpp>
#include <boost/mpl11/comparable.hpp>
#include <boost/mpl11/compose.hpp>
#include <boost/mpl11/empty_base.hpp>
#include <boost/mpl11/finite_sequence.hpp>
#include <boost/mpl11/flip.hpp>
#include <boost/mpl11/forward_sequence.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/if.hpp>
#include <boost/mpl11/inherit.hpp>
#include <boost/mpl11/integral.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/into.hpp>
#include <boost/mpl11/not.hpp>
#include <boost/mpl11/or.hpp>
#include <boost/mpl11/orderable.hpp>
#include <boost/mpl11/partial.hpp>
#include <boost/mpl11/quote.hpp>
#include <boost/mpl11/random_access_sequence.hpp>
#include <boost/mpl11/sequence_traits.hpp>
#include <boost/mpl11/tag_of.hpp>
#include <boost/mpl11/vector.hpp>

#endif // !BOOST_MPL11_HPP
