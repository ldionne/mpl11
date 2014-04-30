/*!
 * @file
 * Defines unit tests for `logical or`s.
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

#ifndef BOOST_MPL11_DETAIL_TEST_LOGICAL_OR_HPP
#define BOOST_MPL11_DETAIL_TEST_LOGICAL_OR_HPP

#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/core.hpp>
#include <boost/mpl11/detail/test/expect.hpp>


namespace boost { namespace mpl11 { namespace detail {
    <%
      def bool_sequences(size)
        bools = size.times.map { ['true_', 'false_'] }
        return bools[0].product(*bools[1..-1])
      end

      def short_circuitable_bool_sequences(size)
        bool_sequences(size)
          .map { |seq|
            seq = seq.take_while(&'false_'.method(:==))
            seq << 'true_' unless seq.size == size
            seq + (size - seq.size).times.map { 'undefined' }
          }
          .uniq
          .select { |seq| seq.include? 'undefined' }
      end
    %>

    template <template <typename ...> class or_>
    struct test_logical_or_strict
        : instantiate<
            typename expect<or_<>>::template to_eq<false_>
            <% for n in 1..5 %>
                <% for xs in bool_sequences(n) %>
                    ,typename expect<
                        or_<<%= xs.join(',') %>>
                    >::template to_eq<
                        bool_<<%= xs.include?('true_') %>>
                    >
                <% end %>
            <% end %>
        >
    { };

    template <template <typename ...> class or_>
    struct test_logical_or_lazy
        : instantiate<
            test_logical_or_strict<or_>
            <% for n in 2..10 %>
                <% for xs in short_circuitable_bool_sequences(n) %>
                    ,typename expect<
                        or_<<%= xs.join(',') %>>
                    >::template to_eq<
                        bool_<<%= xs.include?('true_') %>>
                    >
                <% end %>
            <% end %>
        >
    { };
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_TEST_LOGICAL_OR_HPP
