/*!
 * @file
 * Manages configurable options of the library and defines utility macros.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_MPL11_DETAIL_CONFIG_HPP
#define BOOST_MPL11_DETAIL_CONFIG_HPP

#if defined(BOOST_MPL11_DOXYGEN_INVOKED)
    /*!
     * @ingroup details
     *
     * When defined, optional assertions and consistency checks are
     * __not__ performed by the library.
     *
     * Assertions can have a negative impact on compile-time performance;
     * they can be disabled if that is a problem. However, it is strongly
     * recommended to enable them when debugging template code.
     */
#   define BOOST_MPL11_NO_ASSERTIONS

    /*!
     * @ingroup details
     *
     * When defined, rewrite rules are disabled.
     *
     * Disabling rewrite rules can have a negative impact on compile-time
     * performance; this is mainly meant as a way to make sure rewrite rules
     * do not change the semantics of metaprograms.
     */
#   define BOOST_MPL11_NO_REWRITE_RULES

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
     * Macro expanding to a struct when generating the documentation and
     * to an alias otherwise.
     *
     * This is required because Doxygen handles template aliases (and aliases
     * in general) poorly (or maybe I just can't get them to work).
     */
#   define BOOST_MPL11_DOXYGEN_ALIAS(NAME, ...) struct NAME : __VA_ARGS__ { }

#else // not generating documentation

#   define BOOST_MPL11_IF_DOXYGEN(...) /* nothing */
#   define BOOST_MPL11_DOXYGEN_ALIAS(NAME, ...) using NAME = __VA_ARGS__

#endif

#if defined(BOOST_MPL11_NO_ASSERTIONS) || defined(BOOST_MPL11_DOXYGEN_INVOKED)
    /*!
     * @ingroup details
     *
     * Macro expanding to its argument(s) if @ref BOOST_MPL11_NO_ASSERTIONS
     * is _not_ defined, and to nothing otherwise.
     */
#   define BOOST_MPL11_IF_ASSERTIONS(...) // nothing
#else
#   define BOOST_MPL11_IF_ASSERTIONS(...) __VA_ARGS__
#endif

/*!
 * @ingroup details
 *
 * Clang-3.5 has a bug causing `flip` to fail on binary metafunctions.
 */
#define BOOST_MPL11_CLANG_FLIP_BUG

/*!
 * @ingroup details
 *
 * GCC-4.9 has a bug making it an error to expand parameter packs in some
 * circumstances.
 */
#define BOOST_MPL11_GCC_PACK_EXPANSION_BUG

#if (defined(__GNUC__) || defined(__GNUG__)) && \
    !defined(__clang__) && !defined(__INTEL_COMPILER)
#   define BOOST_MPL11_GCC
#endif

#endif // !BOOST_MPL11_DETAIL_CONFIG_HPP
