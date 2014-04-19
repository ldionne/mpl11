/*!
 * @file
 * Defines `boost::mpl11::detail::foldl_n`.
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

#ifndef BOOST_MPL11_DETAIL_FOLDL_N_HPP
#define BOOST_MPL11_DETAIL_FOLDL_N_HPP

#include <boost/mpl11/detail/std_size_t.hpp>
#include <boost/mpl11/fwd/iterable.hpp>


namespace boost { namespace mpl11 { namespace detail {
namespace foldl_n_detail {
    <%
        f = -> (state, x) {
          "typename f::type::template apply<#{state}, head<#{x}>>"
        }

        def tail(n)
          (0...n).reduce("xs") { |xs, _| "tail<#{xs}>" }
        end

        def tails(n)
          (0...n).map(&method(:tail))
        end

        UNROLL = 5
    %>

    template <std_size_t n, typename f, typename state, typename xs>
    struct impl {
        using left = impl<
            (n - <%= UNROLL+1 %>)/2,
            f,
            <%= tails(UNROLL+1).reduce("state", &f) %>,
            <%= tail(UNROLL+1) %>
        >;
        using right = impl<
            (n - <%= UNROLL+1 %>) - (n - <%= UNROLL+1 %>)/2,
            f,
            typename left::result,
            typename left::rest
        >;

        using rest = typename right::rest;
        using result = typename right::result;
    };

    <% for n in 0..UNROLL %>
        template <typename f, typename state, typename xs>
        struct impl<<%= n %>, f, state, xs> {
            using rest = <%= tail n %>;
            using result = <%= tails(n).reduce("state", &f) %>;
        };
    <% end %>
} // end namespace foldl_n_detail

/*!
 * @ingroup details
 *
 * Left fold stopping after `n` steps.
 */
template <std_size_t n, typename f, typename state, typename xs>
using foldl_n = typename foldl_n_detail::impl<n, f, state, xs>::result;
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_FOLDL_N_HPP
