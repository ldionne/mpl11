/*!
 * @file
 * Defines Doxygen related utilities.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
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
#   define BOOST_MPL11_IF_DOXYGEN(...) __VA_ARGS__

    /*!
     * @ingroup details
     *
     * Macro expanding to its argument(s) unless when generating the
     * documentation with Doxygen, where it expands to nothing.
     */
#   define BOOST_MPL11_UNLESS_DOXYGEN(...) /* nothing */

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
#   define BOOST_MPL11_IF_DOXYGEN(...) /* nothing */
#   define BOOST_MPL11_UNLESS_DOXYGEN(...) __VA_ARGS__
#   define BOOST_MPL11_DOXYGEN_ALIAS(NAME, ...) using NAME = __VA_ARGS__
#endif

#endif // !BOOST_MPL11_DETAIL_DOXYGEN_HPP
