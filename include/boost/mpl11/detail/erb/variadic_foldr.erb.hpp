/*!
 * @file
 * Defines `boost::mpl11::detail::variadic_foldr`.
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

#ifndef BOOST_MPL11_DETAIL_VARIADIC_FOLDR_HPP
#define BOOST_MPL11_DETAIL_VARIADIC_FOLDR_HPP

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

    f = -> (x, state) { "typename f::type::template apply<#{x}, #{state}>" }
    state = "state"

    UNROLL = 5

    module Enumerable
      def foldr(state, &block)
        reverse.inject(state) { |state, x| block.call(x, state) }
      end

      alias_method(:foldl, :inject)
    end

%>

/*!
 * @ingroup details
 *
 * Right fold over a parameter pack.
 */
template <typename f, typename state, typename ...xs>
struct variadic_foldr;

template <typename f, typename state <%= comma(typename(xs(0..UNROLL))).join %>, typename ...xs>
struct variadic_foldr<f, state <%= comma(xs(0..UNROLL)).join %>, xs...>
    : <%=
        xs(0..UNROLL).foldr("variadic_foldr<f, state, xs...>", &f)
                     .sub(/^typename/, "")
    %>
{ };

<% for n in 0..UNROLL %>
    template <typename f, typename state <%= comma(typename(xs(0...n))).join %> >
    struct variadic_foldr<f, state <%= comma(xs(0...n)).join %> >
        : <%= xs(0...n).foldr("state", &f).sub(/^typename/, "") %>
    { };
<% end %>
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_VARIADIC_FOLDR_HPP
