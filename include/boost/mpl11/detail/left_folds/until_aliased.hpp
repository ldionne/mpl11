/*!
 * @file
 * Defines `boost::mpl11::detail::left_folds::until_aliased`.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_MPL11_DETAIL_LEFT_FOLDS_UNTIL_ALIASED_HPP
#define BOOST_MPL11_DETAIL_LEFT_FOLDS_UNTIL_ALIASED_HPP

#include <boost/mpl11/fwd/iterable.hpp>


namespace boost { namespace mpl11 { namespace detail { namespace left_folds {
    template <bool done>
    struct until_aliased_impl;

    template <>
    struct until_aliased_impl<true> {
        template <
            template <typename ...> class pred,
            template <typename ...> class f,
            typename state, typename xs,
            template <typename ...> class head,
            template <typename ...> class tail>
        using apply = state;
    };

    template <>
    struct until_aliased_impl<false> {
        template <
            template <typename ...> class pred,
            template <typename ...> class f,
            typename state, typename xs,
            template <typename ...> class head,
            template <typename ...> class tail>
        using apply =
            typename until_aliased_impl<pred<tail<xs>>::type::value>::
            template apply<pred, f, f<state, head<xs>>, tail<xs>, head, tail>;
    };

    /*!
     * @ingroup details
     *
     * Left fold using aliases stopping whenever the `predicate` returns true.
     *
     * The metafunctions are unlifted for performance.
     */
    template <
        template <typename ...> class predicate,
        template <typename ...> class f,
        typename state, typename xs,
        template <typename ...> class head = mpl11::head,
        template <typename ...> class tail = mpl11::tail>
    using until_aliased =
        typename until_aliased_impl<predicate<xs>::type::value>::
        template apply<predicate, f, state, xs, head, tail>;
}}}} // end namespace boost::mpl11::detail::left_folds

#endif // !BOOST_MPL11_DETAIL_LEFT_FOLDS_UNTIL_ALIASED_HPP
