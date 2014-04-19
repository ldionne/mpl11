/*!
 * @file
 * Defines `boost::mpl11::detail::variadic_foldl_alias`.
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

#ifndef BOOST_MPL11_DETAIL_VARIADIC_FOLDL_ALIAS_HPP
#define BOOST_MPL11_DETAIL_VARIADIC_FOLDL_ALIAS_HPP

#include <boost/mpl11/detail/std_size_t.hpp>


namespace boost { namespace mpl11 { namespace detail {
namespace variadic_foldl_alias_detail {
    <%
        UNROLL = 5
        f = -> (state, x) { "typename f::type::template apply<#{state}, #{x}>" }
        state = "state"
        dispatch = "(sizeof...(xs) > #{UNROLL+1} ? #{UNROLL+1} : sizeof...(xs))"

        def comma(xs)
          xs.map(&", ".method(:+))
        end

        def typename(xs)
          xs.map(&"typename ".method(:+))
        end

        def xs(range)
          range.map(&:to_s).map(&"x".method(:+))
        end
    %>

    template <std_size_t n>
    struct impl;

    template <>
    struct impl<    <%= UNROLL+1 %>   > {
        template <typename f, typename state <%= comma(typename(xs(1..UNROLL+1))).join %>, typename ...xs>
        using apply =
            typename impl<  <%= dispatch %>    >::template apply<
                f,
                <%= xs(1..UNROLL+1).reduce(state, &f) %>,
                xs...
            >;
    };

    <% for n in 0..UNROLL %>
        template <>
        struct impl<    <%= n %>    > {
            template <typename f, typename state <%= comma(typename(xs(1..n))).join %>>
            using apply = <%= xs(1..n).reduce(state, &f) %>;
        };
    <% end %>
} // end namespace variadic_foldl_alias_detail

/*!
 * @ingroup details
 *
 * Recursive alias-based variadic left fold.
 */
template <typename f, typename state, typename ...xs>
struct variadic_foldl_alias
    : variadic_foldl_alias_detail::impl<    <%= dispatch %>     >::
      template apply<f, state, xs...>
{ };
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_VARIADIC_FOLDL_ALIAS_HPP
