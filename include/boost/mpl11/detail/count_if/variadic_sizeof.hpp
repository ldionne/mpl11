/*!
 * @file
 * Defines `boost::mpl11::detail::count_if::variadic_sizeof`.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_MPL11_DETAIL_COUNT_IF_VARIADIC_SIZEOF_HPP
#define BOOST_MPL11_DETAIL_COUNT_IF_VARIADIC_SIZEOF_HPP

#include <boost/mpl11/detail/std_index_sequence.hpp>
#include <boost/mpl11/detail/std_size_t.hpp>
#include <boost/mpl11/integer.hpp>


namespace boost { namespace mpl11 { namespace detail { namespace count_if {
    template <std_size_t, bool> struct count_helper { };
    template <std_size_t n> struct count_helper<n, true> { char c[10]; };

    template <
        template <typename ...> class pred,
        typename index,
        typename ...xs>
    struct sizeof_impl;

    template <
        template <typename ...> class pred,
        std_size_t ...index,
        typename ...xs>
    struct sizeof_impl<pred, std_index_sequence<index...>, xs...>
        : count_helper<index, (bool)pred<xs>::type::value>...
    { };

    /*!
     * @ingroup details
     *
     * `count_if` algorithm using a trick with the `sizeof` operator.
     */
    template <template <typename ...> class predicate, typename ...xs>
    using variadic_sizeof = size_t<sizeof...(xs) == 0 ? 0 :
        sizeof(
            sizeof_impl<
                predicate,
                typename make_std_index_sequence<sizeof...(xs)>::type,
                xs...
            >
        ) / sizeof(count_helper<0, true>)
    >;
}}}} // end namespace boost::mpl11::detail::count_if

#endif // !BOOST_MPL11_DETAIL_COUNT_IF_VARIADIC_SIZEOF_HPP
