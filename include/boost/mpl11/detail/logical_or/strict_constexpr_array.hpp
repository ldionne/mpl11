/*!
 * @file
 * Defines `boost::mpl11::detail::logical_or::strict_constexpr_array`.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_MPL11_DETAIL_LOGICAL_OR_STRICT_CONSTEXPR_ARRAY_HPP
#define BOOST_MPL11_DETAIL_LOGICAL_OR_STRICT_CONSTEXPR_ARRAY_HPP

#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/detail/std_size_t.hpp>


namespace boost { namespace mpl11 { namespace detail { namespace logical_or {
    template <std_size_t N>
    constexpr bool strict_constexpr_array_impl(const bool (&array)[N]) {
        // Note: GCC 4.9 does not like range-based for loop in constexpr.
        for (std_size_t i = 0; i < N; ++i)
            if (array[i])
                return true;
        return false;
    }

    /*!
     * @ingroup details
     *
     * Strict (non short-circuiting) `logical or` implemented with constexpr.
     */
    template <typename ...xs>
    using strict_constexpr_array = bool_<
        strict_constexpr_array_impl<sizeof...(xs)+1>({
            (bool)xs::type::value..., false
        })
    >;
}}}} // end namespace boost::mpl11::detail::logical_or

#endif // !BOOST_MPL11_DETAIL_LOGICAL_OR_STRICT_CONSTEXPR_ARRAY_HPP
