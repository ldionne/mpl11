/*!
 * @file
 * Defines `boost::mpl11::detail::right_folds::variadic`.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_MPL11_DETAIL_RIGHT_FOLDS_VARIADIC_HPP
#define BOOST_MPL11_DETAIL_RIGHT_FOLDS_VARIADIC_HPP

#include <boost/mpl11/detail/right_folds/variadic_unrolled.hpp>


namespace boost { namespace mpl11 { namespace detail { namespace right_folds {
    /*!
     * @ingroup details
     *
     * Alias to the most efficient variadic right fold.
     */
    template <template <typename ...> class f, typename state, typename ...xs>
    using variadic = variadic_unrolled<f, state, xs...>;
}}}} // end namespace boost::mpl11::detail::right_folds

#endif // !BOOST_MPL11_DETAIL_RIGHT_FOLDS_VARIADIC_HPP
