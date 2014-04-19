/*!
 * @file
 * Defines `boost::mpl11::detail::left_folds::bounded`.
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

#ifndef BOOST_MPL11_DETAIL_LEFT_FOLDS_BOUNDED_HPP
#define BOOST_MPL11_DETAIL_LEFT_FOLDS_BOUNDED_HPP

#include <boost/mpl11/detail/std_size_t.hpp>
#include <boost/mpl11/fwd/iterable.hpp>


namespace boost { namespace mpl11 { namespace detail { namespace left_folds {
    <%
        def tail(n)
          (0...n).foldl("xs") { |xs, _| "tail<#{xs}>" }
        end

        def tails(n)
          (0...n).map(&method(:tail))
        end

        f = -> (state, x) { apply.call('f', state, "head<#{x}>") }
        unroll = 5
    %>

    template <std_size_t n, typename f, typename state, typename xs>
    struct bounded_impl {
        using left = bounded_impl<
            (n - <%= unroll+1 %>)/2,
            f,
            <%= tails(unroll+1).foldl("state", &f) %>,
            <%= tail(unroll+1) %>
        >;
        using right = bounded_impl<
            (n - <%= unroll+1 %>) - (n - <%= unroll+1 %>)/2,
            f,
            typename left::result,
            typename left::rest
        >;

        using rest = typename right::rest;
        using result = typename right::result;
    };

    <% for n in 0..unroll %>
        template <typename f, typename state, typename xs>
        struct bounded_impl<<%= n %>, f, state, xs> {
            using rest = <%= tail n %>;
            using result = <%= tails(n).foldl("state", &f) %>;
        };
    <% end %>

    /*!
     * @ingroup details
     *
     * Left fold stopping after `n` steps.
     */
    template <std_size_t n, typename f, typename state, typename xs>
    using bounded = typename bounded_impl<n, f, state, xs>::result;
}}}} // end namespace boost::mpl11::detail::left_folds

#endif // !BOOST_MPL11_DETAIL_LEFT_FOLDS_BOUNDED_HPP
