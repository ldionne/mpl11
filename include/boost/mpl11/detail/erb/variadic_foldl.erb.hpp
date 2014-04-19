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

    def xs(range)
      range.map(&:to_s).map(&"x".method(:+))
    end

    def comma(xs)
      xs.map(&", ".method(:+))
    end

    def typename(xs)
      xs.map(&"typename ".method(:+))
    end

    f = -> (state, x) { "typename f::type::template apply<#{state}, #{x}>" }
    state = "state"

    UNROLL = 5

%>

/*!
 * @ingroup details
 *
 * Left fold over a parameter pack.
 */
template <typename f, typename state, typename ...xs>
struct variadic_foldl;

template <typename f, typename state <%= comma(typename(xs(0..UNROLL))).join %>, typename ...xs>
struct variadic_foldl<f, state <%= comma(xs(0..UNROLL)).join %>, xs...>
    : variadic_foldl<
        f,
        <%= xs(0..UNROLL).reduce(state, &f) %>,
        xs...
    >
{ };

<% for n in 0..UNROLL %>
    template <typename f, typename state <%= comma(typename(xs(0...n))).join %> >
    struct variadic_foldl<f, state <%= comma(xs(0...n)).join %> >
        : <%= xs(0...n).reduce(state, &f).sub(/^typename/, "") %>
    { };
<% end %>
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_VARIADIC_FOLDL_HPP
