/*!
 * @file
 * Defines `boost::mpl11::detail::left_folds::until_naive`.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_MPL11_DETAIL_LEFT_FOLDS_UNTIL_NAIVE_HPP
#define BOOST_MPL11_DETAIL_LEFT_FOLDS_UNTIL_NAIVE_HPP

#include <boost/mpl11/fwd/iterable.hpp>


namespace boost { namespace mpl11 { namespace detail { namespace left_folds {
    /*!
     * @ingroup details
     *
     * Naive left fold stopping whenever the `predicate` returns true.
     *
     * The metafunctions are unlifted for performance.
     */
    template <
        template <typename ...> class predicate,
        template <typename ...> class f,
        typename state, typename xs,
        bool = predicate<xs>::type::value>
    struct until_naive;

    template <
        template <typename ...> class p,
        template <typename ...> class f,
        typename state, typename xs>
    struct until_naive<p, f, state, xs, true>
        : state
    { };

    template <
        template <typename ...> class p,
        template <typename ...> class f,
        typename state, typename xs>
    struct until_naive<p, f, state, xs, false>
        : until_naive<p, f, f<state, head<xs>>, tail<xs>>
    { };
}}}} // end namespace boost::mpl11::detail::left_folds

#endif // !BOOST_MPL11_DETAIL_LEFT_FOLDS_UNTIL_NAIVE_HPP
