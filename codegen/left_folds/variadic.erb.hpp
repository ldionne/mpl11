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

//////////////////////////////////////////////////////////////////////////
// GENERATED HEADER: DO NOT EDIT.
//////////////////////////////////////////////////////////////////////////

#ifndef BOOST_MPL11_DETAIL_LEFT_FOLDS_VARIADIC_HPP
#define BOOST_MPL11_DETAIL_LEFT_FOLDS_VARIADIC_HPP

namespace boost { namespace mpl11 { namespace detail { namespace left_folds {
<%
    f = -> (state, xs) { "f<#{state}, #{xs}>" }
    unroll = 5

    def xs(range)
      range.map(&:to_s).map(&"x".method(:+))
    end
%>

/*!
 * @ingroup details
 *
 * Left fold over a parameter pack.
 *
 * The metafunction is unlifted for performance.
 */
template <template <typename ...> class f, typename state, typename ...xs>
struct variadic;

template <
    template <typename ...> class f,
    typename state
    <%= comma(typename(xs(0..unroll))).join %>,
    typename ...xs>
struct variadic<f, state <%= comma(xs(0..unroll)).join %>, xs...>
    : variadic<
        f,
        <%= xs(0..unroll).foldl("state", &f) %>,
        xs...
    >
{ };

<% for n in 0..unroll %>
    template <
        template <typename ...> class f,
        typename state
        <%= comma(typename(xs(0...n))).join %>
    >
    struct variadic<f, state <%= comma(xs(0...n)).join %> >
        : <%= xs(0...n).foldl("state", &f).sub(/^typename/, "") %>
    { };
<% end %>
}}}} // end namespace boost::mpl11::detail::left_folds

#endif // !BOOST_MPL11_DETAIL_LEFT_FOLDS_VARIADIC_HPP
