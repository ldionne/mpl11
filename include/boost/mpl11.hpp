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
#include <boost/mpl11/field.hpp>
#include <boost/mpl11/foldable.hpp>
#include <boost/mpl11/functional.hpp>
#include <boost/mpl11/functor.hpp>
#include <boost/mpl11/group.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/logical.hpp>
#include <boost/mpl11/monoid.hpp>
#include <boost/mpl11/orderable.hpp>
#include <boost/mpl11/ring.hpp>

#endif // !BOOST_MPL11_HPP
