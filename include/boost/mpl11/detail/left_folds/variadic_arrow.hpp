/*!
 * @file
 * Defines `boost::mpl11::detail::left_folds::variadic_arrow`.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_MPL11_DETAIL_LEFT_FOLDS_VARIADIC_ARROW_HPP
#define BOOST_MPL11_DETAIL_LEFT_FOLDS_VARIADIC_ARROW_HPP

namespace boost { namespace mpl11 { namespace detail { namespace left_folds {
    template <template <typename ...> class f, typename state, typename ...xs>
    struct arrow_impl {
        state result;
        arrow_impl* operator->();
    };

    template <template <typename ...> class f,
              typename state, typename x, typename ...xs>
    struct arrow_impl<f, state, x, xs...> {
        arrow_impl<f, f<state, x>, xs...> operator->();
    };

    /*!
     * @ingroup details
     *
     * Left fold using `operator->` for recursion.
     */
    template <template <typename ...> class f, typename state, typename ...xs>
    using variadic_arrow = decltype(arrow_impl<f, state, xs...>{}->result);
}}}} // end namespace boost::mpl11::detail::left_folds

#endif // !BOOST_MPL11_DETAIL_LEFT_FOLDS_VARIADIC_ARROW_HPP
