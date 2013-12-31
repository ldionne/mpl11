/*!
 * @file
 * Defines Doxygen related utilities.
 */

#ifndef BOOST_MPL11_DETAIL_DOXYGEN_HPP
#define BOOST_MPL11_DETAIL_DOXYGEN_HPP

#ifdef BOOST_MPL11_DOXYGEN_INVOKED
    /*!
     * @ingroup details
     *
     * Macro expanding to its argument(s) when generating the
     * documentation with Doxygen and to nothing otherwise.
     */
#   define BOOST_MPL11_DOXYGEN_ONLY(...) __VA_ARGS__

    /*!
     * @ingroup details
     *
     * Macro expanding to a struct when generating the documentation and
     * to an alias otherwise.
     *
     * This is required because Doxygen handles template aliases (and aliases
     * in general) poorly (or maybe I just can't get them to work).
     */
#   define BOOST_MPL11_DOXYGEN_ALIAS(NAME, ...) struct NAME : __VA_ARGS__ { }
#else
#   define BOOST_MPL11_DOXYGEN_ONLY(...) /* nothing */
#   define BOOST_MPL11_DOXYGEN_ALIAS(NAME, ...) using NAME = __VA_ARGS__
#endif

#endif // !BOOST_MPL11_DETAIL_DOXYGEN_HPP
