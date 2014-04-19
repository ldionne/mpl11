/*!
 * @file
 * Defines `boost::mpl11::detail::left_folds::variadic_naive`.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_MPL11_DETAIL_LEFT_FOLDS_VARIADIC_NAIVE_HPP
#define BOOST_MPL11_DETAIL_LEFT_FOLDS_VARIADIC_NAIVE_HPP

namespace boost { namespace mpl11 { namespace detail { namespace left_folds {
    /*!
     * @ingroup details
     *
     * Naive left fold for parameter packs.
     */
    template <typename f, typename state, typename ...xs>
    struct variadic_naive : state { };

    template <typename f, typename state, typename x, typename ...xs>
    struct variadic_naive<f, state, x, xs...>
        : variadic_naive<
            f, typename f::type::template apply<state, x>, xs...
        >
    { };
}}}} // end namespace boost::mpl11::detail::left_folds

#endif // !BOOST_MPL11_DETAIL_LEFT_FOLDS_VARIADIC_NAIVE_HPP
