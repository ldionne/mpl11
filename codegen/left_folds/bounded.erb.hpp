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

        f = -> (state, xs) { "f<#{state}, head<#{xs}>>" }
        unroll = 5
    %>

    template <
        std_size_t n, template <typename ...> class f,
        typename state, typename xs,
        template <typename ...> class head,
        template <typename ...> class tail>
    struct bounded_impl {
        using left = bounded_impl<
            (n - <%= unroll+1 %>)/2,
            f,
            <%= tails(unroll+1).foldl("state", &f) %>,
            <%= tail(unroll+1) %>,
            head, tail
        >;
        using right = bounded_impl<
            (n - <%= unroll+1 %>) - (n - <%= unroll+1 %>)/2,
            f,
            typename left::result,
            typename left::rest,
            head, tail
        >;

        using rest = typename right::rest;
        using result = typename right::result;
    };

    <% for n in 0..unroll %>
        template <
            template <typename ...> class f,
            typename state, typename xs,
            template <typename ...> class head,
            template <typename ...> class tail>
        struct bounded_impl<<%= n %>, f, state, xs, head, tail> {
            using rest = <%= tail n %>;
            using result = <%= tails(n).foldl("state", &f) %>;
        };
    <% end %>

    /*!
     * @ingroup details
     *
     * Left fold stopping after `n` steps.
     *
     * The metafunction is unlifted for performance.
     */
    template <
        std_size_t n,
        template <typename ...> class f,
        typename state,
        typename xs,
        template <typename ...> class head = mpl11::head,
        template <typename ...> class tail = mpl11::tail
    >
    using bounded = typename bounded_impl<n, f, state, xs, head, tail>::result;
}}}} // end namespace boost::mpl11::detail::left_folds

#endif // !BOOST_MPL11_DETAIL_LEFT_FOLDS_BOUNDED_HPP
