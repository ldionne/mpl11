/*!
 * @file
 * Defines the `static_assert_` helper for unit tests.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_MPL11_TEST_STATIC_ASSERT_HPP
#define BOOST_MPL11_TEST_STATIC_ASSERT_HPP

/*!
 * @ingroup details
 *
 * Returns the given boolean expression and statically asserts that its
 * value is `true`.
 */
template <typename boolean_expression>
struct static_assert_ : boolean_expression {
    static_assert(boolean_expression::type::value, "");
};

#endif // !BOOST_MPL11_TEST_STATIC_ASSERT_HPP
