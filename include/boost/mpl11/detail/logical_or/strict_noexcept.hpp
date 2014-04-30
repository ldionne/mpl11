/*!
 * @file
 * Defines `boost::mpl11::detail::logical_or::strict_noexcept`.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_MPL11_DETAIL_LOGICAL_OR_STRICT_NOEXCEPT_HPP
#define BOOST_MPL11_DETAIL_LOGICAL_OR_STRICT_NOEXCEPT_HPP

#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/detail/std_conditional.hpp>


namespace boost { namespace mpl11 { namespace detail { namespace logical_or {
    void allow_expansion_impl(...) noexcept;
    struct non_throwing_impl { non_throwing_impl() noexcept { } };
    struct throwing_impl { throwing_impl() { throw; } };

    /*!
     * @ingroup details
     *
     * Strict (non short-circuiting) logical or implemented with noexcept.
     */
    template <typename ...xs>
    using strict_noexcept = bool_<
        !noexcept(allow_expansion_impl(
            typename std_conditional<
                (bool)xs::type::value, throwing_impl, non_throwing_impl
            >::type{}...
        ))
    >;
}}}} // end namespace boost::mpl11::detail::logical_or

#endif // !BOOST_MPL11_DETAIL_LOGICAL_OR_STRICT_NOEXCEPT_HPP
