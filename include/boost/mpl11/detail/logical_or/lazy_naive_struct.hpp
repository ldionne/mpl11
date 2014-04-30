/*!
 * @file
 * Defines `boost::mpl11::detail::logical_or::lazy_naive_struct`.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_MPL11_DETAIL_LOGICAL_OR_LAZY_NAIVE_STRUCT_HPP
#define BOOST_MPL11_DETAIL_LOGICAL_OR_LAZY_NAIVE_STRUCT_HPP

#include <boost/mpl11/bool.hpp>


namespace boost { namespace mpl11 { namespace detail { namespace logical_or {
    template <bool b, typename ...>
    struct lazy_naive_struct_impl : bool_<b> { };

    template <typename x, typename ...xs>
    struct lazy_naive_struct_impl<false, x, xs...>
        : lazy_naive_struct_impl<(bool)x::type::value, xs...>
    { };

    /*!
     * @ingroup details
     *
     * Short-circuiting logical or implemented with naive recursion.
     */
    template <typename ...xs>
    using lazy_naive_struct = lazy_naive_struct_impl<false, xs...>;
}}}} // end namespace boost::mpl11::detail::logical_or

#endif // !BOOST_MPL11_DETAIL_LOGICAL_OR_LAZY_NAIVE_STRUCT_HPP
