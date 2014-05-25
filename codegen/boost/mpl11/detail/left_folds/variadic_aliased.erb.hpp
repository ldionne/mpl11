/*!
 * @file
 * Defines `boost::mpl11::detail::left_folds::variadic_aliased`.
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

#ifndef BOOST_MPL11_DETAIL_LEFT_FOLDS_VARIADIC_ALIASED_HPP
#define BOOST_MPL11_DETAIL_LEFT_FOLDS_VARIADIC_ALIASED_HPP

namespace boost { namespace mpl11 { namespace detail { namespace left_folds {
    <%
        unroll = 5
        f = -> (state, xs) { "f<#{state}, #{xs}>" }
        dispatch = "(sizeof...(xs) > #{unroll+1} ? #{unroll+1} : sizeof...(xs))"

        def xs(range)
          range.map(&:to_s).map(&"x".method(:+))
        end
    %>

    template <unsigned n>
    struct variadic_aliased_impl;

    template <>
    struct variadic_aliased_impl<    <%= unroll+1 %>   > {
        template <
            template <typename ...> class f,
            typename state
            <%= comma(typename(xs(1..unroll+1))).join %>,
            typename ...xs>
        using apply =
            typename variadic_aliased_impl<  <%= dispatch %>    >::
            template apply<
                f,
                <%= xs(1..unroll+1).foldl("state", &f) %>,
                xs...
            >;
    };

    <% for n in 0..unroll %>
        template <>
        struct variadic_aliased_impl<    <%= n %>    > {
            template <
                template <typename ...> class f,
                typename state
                <%= comma(typename(xs(1..n))).join %>
            >
            using apply = <%= xs(1..n).foldl("state", &f) %>;
        };
    <% end %>

    /*!
     * @ingroup details
     *
     * Recursive alias-based variadic left fold.
     *
     * The metafunction is unlifted for performance.
     */
    template <template <typename ...> class f, typename state, typename ...xs>
    struct variadic_aliased
        : variadic_aliased_impl<    <%= dispatch %>     >::
          template apply<f, state, xs...>
    { };
}}}} // end namespace boost::mpl11::detail::left_folds

#endif // !BOOST_MPL11_DETAIL_LEFT_FOLDS_VARIADIC_ALIASED_HPP
