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
 * Tags come in two flavors (the difference is only their purpose):
 *
 * ### Typeclass tags
 * A typeclass tag represents a single typeclass. For example, the
 * `sequence_tag` is a typeclass tag because it represents the `Sequence`
 * typeclass. These tags are used as a meeting point to dispatch multi-ary
 * methods with different datatype tags by using the following technique:
 *
 * The typeclass must be user-specialized on the left datatype tag and
 * that specialization must be of the form:

        template <typename RightTag>
        struct Typeclass<my_left_datatype_tag, RightTag>
            : Typeclass<the_typeclass_tag, RightTag>
        { };

 * Then, the typeclass should be library-specialized in the following way:

        template <typename RightTag>
        struct Typeclass<the_typeclass_tag, RightTag>
            : Typeclass<RightTag, the_typeclass_tag>
        { };

 * This allows `RightTag` to undergo the same process as
 * `my_left_datatype_tag`, so that the typeclass is eventually resolved to

        template <>
        struct Typeclass<the_typeclass_tag, the_typeclass_tag>;

 * Which is the typeclass that implements the method we were searching for.
 *
 *
 * ### Datatype tags
 * A datatype tag represents a specific datatype. These tags are only used to
 * make the datatype an instance of typeclasses.
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
#include <boost/mpl11/bitwise.hpp>
#include <boost/mpl11/comparable.hpp>
#include <boost/mpl11/compose.hpp>
#include <boost/mpl11/drop.hpp>
#include <boost/mpl11/empty_base.hpp>
#include <boost/mpl11/empty_sequence.hpp>
#include <boost/mpl11/flip.hpp>
#include <boost/mpl11/foldl.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/if.hpp>
#include <boost/mpl11/inherit.hpp>
#include <boost/mpl11/integral.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/into.hpp>
#include <boost/mpl11/iterate.hpp>
#include <boost/mpl11/list.hpp>
#include <boost/mpl11/not.hpp>
#include <boost/mpl11/or.hpp>
#include <boost/mpl11/orderable.hpp>
#include <boost/mpl11/partial.hpp>
#include <boost/mpl11/quote.hpp>
#include <boost/mpl11/repeat.hpp>
#include <boost/mpl11/scanl.hpp>
#include <boost/mpl11/sequence.hpp>
#include <boost/mpl11/sequence_traits.hpp>
#include <boost/mpl11/tag_of.hpp>
#include <boost/mpl11/take.hpp>
#include <boost/mpl11/take_while.hpp>

#endif // !BOOST_MPL11_HPP
