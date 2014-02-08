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
 * @defgroup typeclasses Typeclasses
 *
 * General purpose typeclasses provided by the library.
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

/*!
 * @ingroup typeclasses
 * @defgroup StaticConstant Static Constant
 *
 * Type holding a compile-time value that can be converted to a runtime value.
 *
 * @ref StaticConstant is not really a typeclass; it is only a way of
 * capturing syntactic requirements for an interface, without providing
 * methods or functionality.
 *
 *
 * ### Valid expressions
 * For any @ref StaticConstant `N`, the following expressions must be valid:
 * - `constexpr N::value_type v = N::value`
 * - `constexpr N::value_type v = N{}`
 * - `constexpr N::value_type v = N{}()`
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

#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/comparable.hpp>
#include <boost/mpl11/core.hpp>
#include <boost/mpl11/enumerable.hpp>
#include <boost/mpl11/field.hpp>
#include <boost/mpl11/foldable.hpp>
#include <boost/mpl11/functional.hpp>
#include <boost/mpl11/functor.hpp>
#include <boost/mpl11/group.hpp>
#include <boost/mpl11/integer.hpp>
#include <boost/mpl11/integral_domain.hpp>
#include <boost/mpl11/logical.hpp>
#include <boost/mpl11/monoid.hpp>
#include <boost/mpl11/orderable.hpp>
#include <boost/mpl11/rational.hpp>
#include <boost/mpl11/ring.hpp>

#endif // !BOOST_MPL11_HPP
