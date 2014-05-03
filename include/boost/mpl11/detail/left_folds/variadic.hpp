/*!
 * @file
 * Defines `boost::mpl11::detail::left_folds::variadic`.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_MPL11_DETAIL_LEFT_FOLDS_VARIADIC_HPP
#define BOOST_MPL11_DETAIL_LEFT_FOLDS_VARIADIC_HPP

#include <boost/mpl11/detail/left_folds/variadic_aliased.hpp>


namespace boost { namespace mpl11 { namespace detail { namespace left_folds {
    /*!
     * @ingroup details
     *
     * Alias to the most efficient variadic left fold.
     */
    template <template <typename ...> class f, typename state, typename ...xs>
    using variadic = variadic_aliased<f, state, xs...>;
}}}} // end namespace boost::mpl11::detail::left_folds

#endif // !BOOST_MPL11_DETAIL_LEFT_FOLDS_VARIADIC_HPP
