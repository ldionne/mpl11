/*!
 * @file
 * Defines helper macros to declare checked metafunctions.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_MPL11_DETAIL_CHECKED_HPP
#define BOOST_MPL11_DETAIL_CHECKED_HPP

#include <boost/mpl11/detail/config.hpp>


namespace boost { namespace mpl11 {
    //! @ingroup details
    //! Contains the unchecked version of checked metafunctions.
    namespace unchecked { }

    //! @ingroup details
    //! Contains the asserting code of checked metafunctions.
    namespace checks { }

    //! @ingroup details
    //! Inherit `xs...` in order.
    template <typename ...xs>
    struct inherit : xs... { };
}}

#if defined(BOOST_MPL11_DOXYGEN_INVOKED)

    /*!
     * @ingroup details
     *
     * Declare a metafunction allowing consistency checks when assertions
     * are enabled.
     *
     * The metafunction must be implemented (without the assertions) in the
     * `unchecked` namespace. Then, the consistency checks must be implemented
     * in `checks::F_checks`, where `F` is the name of the metafunction.
     *
     * @note
     * - This macro must be invoked in the `boost::mpl11` namespace only.
     * - Invocation of this macro must be followed by a semicolon.
     */
#   define BOOST_MPL11_DECLARE_CHECKED(F, ...)                              \
        template <__VA_ARGS__> struct F { }                                 \
    /**/

#elif defined(BOOST_MPL11_NO_ASSERTIONS)

#   define BOOST_MPL11_DECLARE_CHECKED(F, ...)                              \
        namespace unchecked { template <__VA_ARGS__> struct F; }            \
        namespace checks { template <__VA_ARGS__> struct F##_checks; }      \
        using unchecked::F                                                  \
    /**/

#else

    // Note:
    // Using an alias here is very important; it will make compilation fail
    // on the spot if the wrong number of arguments is passed to F. If we
    // used a struct instead, compilation would fail when (and if) the
    // struct is actually instantiated.
#   define BOOST_MPL11_DECLARE_CHECKED(F, ...)                              \
        namespace unchecked { template <__VA_ARGS__> struct F; }            \
        namespace checks { template <__VA_ARGS__> struct F##_checks; }      \
        template <typename ...args>                                         \
        using F = inherit<                                                  \
            checks::F##_checks<args...>,                                    \
            unchecked::F<args...>                                           \
        >                                                                   \
    /**/

#endif

#endif // !BOOST_MPL11_DETAIL_CHECKED_HPP
