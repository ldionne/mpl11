/*!
 * @file
 * Defines `boost::mpl11::detail::left_folds::until`.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

//////////////////////////////////////////////////////////////////////////
// GENERATED HEADER: DO NOT EDIT.
//////////////////////////////////////////////////////////////////////////

#ifndef BOOST_MPL11_DETAIL_LEFT_FOLDS_UNTIL_HPP
#define BOOST_MPL11_DETAIL_LEFT_FOLDS_UNTIL_HPP

#include <boost/mpl11/fwd/iterable.hpp>


namespace boost { namespace mpl11 { namespace detail { namespace left_folds {
    template <
        template <typename ...> class pred,
        template <typename ...> class f,
        typename z,
        typename xs,
        bool = pred<xs>::type::value
    >
    struct single_step;

    template <
        template <typename ...> class pred,
        template <typename ...> class f,
        typename z,
        typename xs
    >
    struct single_step<pred, f, z, xs, true> {
        using next = xs;
        using state = z;
    };

    template <
        template <typename ...> class pred,
        template <typename ...> class f,
        typename z,
        typename xs
    >
    struct single_step<pred, f, z, xs, false> {
        using next = tail<xs>;
        using state = f<z, head<xs>>;
    };

    template <
        template <typename ...> class pred,
        template <typename ...> class f,
        typename z,
        typename xs,
        bool = pred<xs>::type::value
    >
    struct multi_step;

    template <
        template <typename ...> class pred,
        template <typename ...> class f,
        typename z,
        typename xs
    >
    struct multi_step<pred, f, z, xs, true> {
        using next = xs;
        using state = z;
    };

    <%
        unroll = 5
    %>

    template <
        template <typename ...> class pred,
        template <typename ...> class f,
        typename z,
        typename xs
    >
    struct multi_step<pred, f, z, xs, false> {
        using state0 = f<z, head<xs>>;
        using next0  = tail<xs>;

        <% for n in 1..unroll %>
            using <%= "state#{n}" %> = typename single_step<
                pred, f, <%= "state#{n-1}" %>, <%= "next#{n-1}" %>
            >::state;

            using <%= "next#{n}" %> = typename single_step<
                pred, f, <%= "state#{n-1}" %>, <%= "next#{n-1}" %>
            >::next;
        <% end %>

        using next = typename multi_step<
            pred, f, <%= "state#{unroll}" %>, <%= "next#{unroll}" %>
        >::next;

        using state = typename multi_step<
            pred, f, <%= "state#{unroll}" %>, <%= "next#{unroll}" %>
        >::state;
    };

    /*!
     * @ingroup details
     *
     * Left fold stopping whenever the `predicate` returns true.
     *
     * The metafunctions are unlifted for performance reasons.
     */
    template <
        template <typename ...> class predicate,
        template <typename ...> class f,
        typename state,
        typename xs
    >
    using until = typename multi_step<
        predicate, f, state, xs
    >::state;
}}}} // end namespace boost::mpl11::detail::left_folds

#endif // !BOOST_MPL11_DETAIL_LEFT_FOLDS_UNTIL_HPP
