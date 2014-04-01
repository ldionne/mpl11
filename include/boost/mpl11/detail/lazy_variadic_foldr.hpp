/*!
 * @file
 * Defines `boost::mpl11::detail::lazy_variadic_foldr`.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_MPL11_DETAIL_LAZY_VARIADIC_FOLDR_HPP
#define BOOST_MPL11_DETAIL_LAZY_VARIADIC_FOLDR_HPP

namespace boost { namespace mpl11 { namespace detail {
    /*!
     * @ingroup details
     *
     * Lazy right-fold algorithm processing a variadic parameter pack.
     */
    template <typename f, typename state, typename ...xs>
    struct lazy_variadic_foldr : state { };

    template <typename f, typename state, typename x, typename ...xs>
    struct lazy_variadic_foldr<f, state, x, xs...>
        : f::type::template apply<
            x, lazy_variadic_foldr<f, state, xs...>
        >
    { };
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_LAZY_VARIADIC_FOLDR_HPP
