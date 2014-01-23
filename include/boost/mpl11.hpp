/*!
 * @file
 * Includes all the modules of the library.
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
 */

/*!
 * @defgroup tags Tags
 *
 * Tags are types used to dispatch methods.
 *
 * Tags come in two flavors (the difference is only their purpose):
 *
 * ### Typeclass tags
 * A typeclass tag represents a single typeclass. These tags are used as a
 * meeting point to dispatch multi-ary methods with different datatype tags
 * by using the following technique:
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
 */

/*!
 * @defgroup metafunctions Metafunctions
 *
 * Metafunctions provided by the library.
 */

/*!
 * @defgroup metafunction_classes Metafunctions Classes
 *
 * Metafunction classes provided by the library.
 */

#if defined(BOOST_MPL11_DOXYGEN_INVOKED)
    /*!
     * @ingroup details
     *
     * When defined, optional assertions and consistency checks are
     * performed by the library.
     *
     * Since this can have a negative impact on compile-time performance,
     * it is disabled by default. However, it is strongly recommended to
     * enable this when debugging template code.
     */
#   define BOOST_MPL11_ENABLE_ASSERTIONS
#endif

#include <boost/mpl11/comparable.hpp>
#include <boost/mpl11/core.hpp>
#include <boost/mpl11/enumerable.hpp>
#include <boost/mpl11/foldable.hpp>
#include <boost/mpl11/functional.hpp>
#include <boost/mpl11/functor.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/logical.hpp>
#include <boost/mpl11/orderable.hpp>

#endif // !BOOST_MPL11_HPP
