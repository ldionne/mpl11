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
#include <boost/mpl11/fwd/functional.hpp> // id is defined in the fwd header


namespace boost { namespace mpl11 { namespace detail { namespace logical_or {
    template <std_size_t n>
    constexpr bool
    strict_constexpr_array_impl(id<bool[n]> const& array, std_size_t i = 0) {
        return i == n ? false :
                        array[i] || strict_constexpr_array_impl(array, i + 1);
    }

    /*!
     * @ingroup details
     *
     * Strict (non short-circuiting) logical or implemented with constexpr.
     *
     *
     * @todo
     * In C++14, we can use generalized constexpr to reduce memory usage
     * of this implementation drastically.
     */
    template <typename ...xs>
    using strict_constexpr_array = bool_<
        strict_constexpr_array_impl(id<bool[sizeof...(xs)+1]>{
            xs::type::value..., false
        })
    >;
}}}} // end namespace boost::mpl11::detail::logical_or

#endif // !BOOST_MPL11_DETAIL_LOGICAL_OR_STRICT_CONSTEXPR_ARRAY_HPP
