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
        unroll = 5
        f = apply.curry(3)['f']
        dispatch = "(sizeof...(xs) > #{unroll+1} ? #{unroll+1} : sizeof...(xs))"

        def xs(range)
          range.map(&:to_s).map(&"x".method(:+))
        end
    %>

    template <std_size_t n>
    struct impl;

    template <>
    struct impl<    <%= unroll+1 %>   > {
        template <typename f, typename state <%= comma(typename(xs(1..unroll+1))).join %>, typename ...xs>
        using apply =
            typename impl<  <%= dispatch %>    >::template apply<
                f,
                <%= xs(1..unroll+1).foldl("state", &f) %>,
                xs...
            >;
    };

    <% for n in 0..unroll %>
        template <>
        struct impl<    <%= n %>    > {
            template <typename f, typename state <%= comma(typename(xs(1..n))).join %>>
            using apply = <%= xs(1..n).foldl("state", &f) %>;
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
