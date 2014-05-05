/*!
 * @file
 * Defines `boost::mpl11::detail::right_folds::variadic_unrolled`.
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

#ifndef BOOST_MPL11_DETAIL_RIGHT_FOLDS_VARIADIC_UNROLLED_HPP
#define BOOST_MPL11_DETAIL_RIGHT_FOLDS_VARIADIC_UNROLLED_HPP

namespace boost { namespace mpl11 { namespace detail { namespace right_folds {
    <%
        def xs(range)
          range.map(&:to_s).map(&"x".method(:+))
        end

        f = -> (state, x) { "f<#{state}, #{x}>" }
        unroll = 5
    %>

    /*!
     * @ingroup details
     *
     * Right fold over a parameter pack with loop unrolling.
     *
     * The metafunction is unlifted for performance.
     */
    template <template <typename ...> class f, typename state, typename ...xs>
    struct variadic_unrolled;

    template <
        template <typename ...> class f,
        typename state
        <%= comma(typename(xs(0..unroll))).join %>,
        typename ...xs>
    struct variadic_unrolled<f, state <%= comma(xs(0..unroll)).join %>, xs...>
        : <%=
            xs(0..unroll).foldr("variadic_unrolled<f, state, xs...>", &f)
                         .sub(/^typename/, '')
        %>
    { };

    <% for n in 0..unroll %>
        template <
            template <typename ...> class f,
            typename state
            <%= comma(typename(xs(0...n))).join %>
        >
        struct variadic_unrolled<f, state <%= comma(xs(0...n)).join %> >
            : <%= xs(0...n).foldr("state", &f).sub(/^typename/, '') %>
        { };
    <% end %>
}}}} // end namespace boost::mpl11::detail::right_folds

#endif // !BOOST_MPL11_DETAIL_RIGHT_FOLDS_VARIADIC_UNROLLED_HPP
