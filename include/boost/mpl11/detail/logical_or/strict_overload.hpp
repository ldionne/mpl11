/*!
 * @file
 * Defines `boost::mpl11::detail::logical_or::strict_overload`.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_MPL11_DETAIL_LOGICAL_OR_STRICT_OVERLOAD_HPP
#define BOOST_MPL11_DETAIL_LOGICAL_OR_STRICT_OVERLOAD_HPP

#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/detail/std_conditional.hpp>


namespace boost { namespace mpl11 { namespace detail { namespace logical_or {
    template <typename ...T> false_ strict_overload_impl(T*...);
                             false_ strict_overload_impl();
    template <typename ...T> true_  strict_overload_impl(T...);

    /*!
     * @ingroup details
     *
     * Strict (non short-circuiting) logical or implemented with
     * overload resolution.
     */
    template <typename ...xs>
    using strict_overload = decltype(
        strict_overload_impl(
            typename std_conditional<
                (bool)xs::type::value, int, int*
            >::type{}...
        )
    );
}}}} // end namespace boost::mpl11::detail::logical_or

#endif // !BOOST_MPL11_DETAIL_LOGICAL_OR_STRICT_OVERLOAD_HPP
