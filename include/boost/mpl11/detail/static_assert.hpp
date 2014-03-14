/*!
 * @file
 * Defines `boost::mpl11::detail::static_assert_`.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_MPL11_DETAIL_STATIC_ASSERT_HPP
#define BOOST_MPL11_DETAIL_STATIC_ASSERT_HPP

namespace boost { namespace mpl11 { namespace detail {
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
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_STATIC_ASSERT_HPP
