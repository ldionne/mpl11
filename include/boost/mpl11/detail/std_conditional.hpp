/*!
 * @file
 * Defines `boost::mpl11::detail::std_conditional`.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_MPL11_DETAIL_STD_CONDITIONAL_HPP
#define BOOST_MPL11_DETAIL_STD_CONDITIONAL_HPP

namespace boost { namespace mpl11 { namespace detail {
    /*!
     * @ingroup details
     *
     * Equivalent to `std::conditional`.
     */
    template <bool Cond, typename Then, typename Else>
    struct std_conditional {
        using type = Then;
    };

    template <typename Then, typename Else>
    struct std_conditional<false, Then, Else> {
        using type = Else;
    };
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_STD_CONDITIONAL_HPP
