/*!
 * @file
 * Defines the `BOOST_MPL11_IF_ASSERTIONS` macro.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_MPL11_DETAIL_ASSERTIONS_HPP
#define BOOST_MPL11_DETAIL_ASSERTIONS_HPP

#if defined(BOOST_MPL11_NO_ASSERTIONS) || defined(BOOST_MPL11_DOXYGEN_INVOKED)
    /*!
     * @ingroup details
     *
     * Macro expanding to its argument(s) if `BOOST_MPL11_NO_ASSERTIONS` is
     * _not_ defined, and to nothing otherwise.
     */
#   define BOOST_MPL11_IF_ASSERTIONS(...) // nothing
#else
#   define BOOST_MPL11_IF_ASSERTIONS(...) __VA_ARGS__
#endif

#endif // !BOOST_MPL11_DETAIL_ASSERTIONS_HPP
