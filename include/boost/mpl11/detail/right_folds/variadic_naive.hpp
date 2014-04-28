/*!
 * @file
 * Defines `boost::mpl11::detail::right_folds::variadic_naive`.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_MPL11_DETAIL_RIGHT_FOLDS_VARIADIC_NAIVE_HPP
#define BOOST_MPL11_DETAIL_RIGHT_FOLDS_VARIADIC_NAIVE_HPP

namespace boost { namespace mpl11 { namespace detail { namespace right_folds {
    /*!
     * @ingroup details
     *
     * Naive right fold for parameter packs.
     */
    template <template <typename ...> class f, typename state, typename ...xs>
    struct variadic_naive : state { };

    template <
        template <typename ...> class f,
        typename state, typename x, typename ...xs
    >
    struct variadic_naive<f, state, x, xs...>
        : f<x, variadic_naive<f, state, xs...>>
    { };
}}}} // end namespace boost::mpl11::detail::right_folds

#endif // !BOOST_MPL11_DETAIL_RIGHT_FOLDS_VARIADIC_NAIVE_HPP
