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


namespace boost { namespace mpl11 { namespace detail { namespace logical_or {
    void allow_expansion(...) noexcept;
    template <bool condition>
    struct noexcept_if { noexcept_if() noexcept(condition) { } };

    /*!
     * @ingroup details
     *
     * Strict (non short-circuiting) logical or implemented with noexcept.
     */
    template <typename ...xs>
    using strict_noexcept = bool_<
        !noexcept(allow_expansion(noexcept_if<!(bool)xs::type::value>{}...))
    >;
}}}} // end namespace boost::mpl11::detail::logical_or

#endif // !BOOST_MPL11_DETAIL_LOGICAL_OR_STRICT_NOEXCEPT_HPP
