/*!
 * @file
 * Defines `boost::mpl11::detail::left_folds::variadic_variabletp`.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_MPL11_DETAIL_LEFT_FOLDS_VARIADIC_VARIABLETP_HPP
#define BOOST_MPL11_DETAIL_LEFT_FOLDS_VARIADIC_VARIABLETP_HPP

namespace boost { namespace mpl11 { namespace detail { namespace left_folds {
    struct done;

    template <template <typename ...> class f, typename state,
              typename x, typename ...xs>
    constexpr auto variable_impl = variable_impl<f, f<state, x>, xs...>;

    template <template <typename ...> class f, typename state>
    constexpr state variable_impl<f, state, done>{};

    /*!
     * @ingroup details
     *
     * Variadic left-fold using variable templates.
     */
    template <template <typename ...> class f, typename state, typename ...xs>
    using variadic_variabletp = decltype(variable_impl<f, state, xs..., done>);
}}}} // end namespace boost::mpl11::detail::left_folds

#endif // !BOOST_MPL11_DETAIL_LEFT_FOLDS_VARIADIC_VARIABLETP_HPP
