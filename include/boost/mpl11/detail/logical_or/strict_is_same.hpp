/*!
 * @file
 * Defines `boost::mpl11::detail::logical_or::strict_is_same`.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_MPL11_DETAIL_LOGICAL_OR_STRICT_IS_SAME_HPP
#define BOOST_MPL11_DETAIL_LOGICAL_OR_STRICT_IS_SAME_HPP

#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/detail/std_is_same.hpp>


namespace boost { namespace mpl11 { namespace detail { namespace logical_or {
    template <bool ...>
    struct strict_is_same_impl;

    /*!
     * @ingroup details
     *
     * Strict (non short-circuiting) logical or implemented with `is_same`.
     *
     * All credit goes to Roland Bock for the technique.
     */
    template <typename ...xs>
    using strict_is_same = bool_<
        !std_is_same<
            strict_is_same_impl<(bool)xs::type::value...>,
            strict_is_same_impl<(xs::type::value, false)...>
        >::value
    >;
}}}} // end namespace boost::mpl11::detail::logical_or

#endif // !BOOST_MPL11_DETAIL_LOGICAL_OR_STRICT_IS_SAME_HPP
