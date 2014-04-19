/*!
 * @file
 * Defines `boost::mpl11::detail::variadic_foldl`.
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

#ifndef BOOST_MPL11_DETAIL_VARIADIC_FOLDL_HPP
#define BOOST_MPL11_DETAIL_VARIADIC_FOLDL_HPP

namespace boost { namespace mpl11 { namespace detail {
<%
    f = apply.curry(3)['f']
    unroll = 5

    def xs(range)
      range.map(&:to_s).map(&"x".method(:+))
    end
%>

/*!
 * @ingroup details
 *
 * Left fold over a parameter pack.
 */
template <typename f, typename state, typename ...xs>
struct variadic_foldl;

template <typename f, typename state <%= comma(typename(xs(0..unroll))).join %>, typename ...xs>
struct variadic_foldl<f, state <%= comma(xs(0..unroll)).join %>, xs...>
    : variadic_foldl<
        f,
        <%= xs(0..unroll).foldl("state", &f) %>,
        xs...
    >
{ };

<% for n in 0..unroll %>
    template <typename f, typename state <%= comma(typename(xs(0...n))).join %> >
    struct variadic_foldl<f, state <%= comma(xs(0...n)).join %> >
        : <%= xs(0...n).foldl("state", &f).sub(/^typename/, "") %>
    { };
<% end %>
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_VARIADIC_FOLDL_HPP
