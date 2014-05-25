/*!
 * @file
 * Defines `boost::mpl11::detail::count_if::variadic_sum`.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_MPL11_DETAIL_COUNT_IF_VARIADIC_SUM_HPP
#define BOOST_MPL11_DETAIL_COUNT_IF_VARIADIC_SUM_HPP

#include <boost/mpl11/detail/std_size_t.hpp>
#include <boost/mpl11/integer.hpp>


namespace boost { namespace mpl11 { namespace detail { namespace count_if {
    template <std_size_t N>
    constexpr std_size_t homogeneous_sum(const bool (&array)[N]) {
        std_size_t s = 0;
        for (std_size_t i = 0; i < N; ++i)
            s += array[i];
        return s;
    }

    /*!
     * @ingroup details
     *
     * `count_if` algorithm using a constexpr sum.
     */
    template <template <typename ...> class predicate, typename ...xs>
    using variadic_sum = size_t<
        // Avoid empty arrays
        homogeneous_sum<sizeof...(xs)+1>(
            {false, (bool)predicate<xs>::type::value...}
        )
    >;
}}}} // end namespace boost::mpl11::detail::count_if

#endif // !BOOST_MPL11_DETAIL_COUNT_IF_VARIADIC_SUM_HPP
