/*!
 * @file
 * Defines unit tests for left fold algorithms.
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

#ifndef BOOST_MPL11_TEST_FOLDL_HPP
#define BOOST_MPL11_TEST_FOLDL_HPP

#include <boost/mpl11/functional.hpp>
#include <boost/mpl11/test/expect.hpp>


namespace boost { namespace mpl11 { namespace test {
    namespace foldl_detail {
        template <int> struct x { using type = x; };

        template <typename ...x>
        struct f { using type = f<typename x::type...>; };

        <%
            def xs(range)
              range.map(&:to_s).map{|n| "x<#{n}>"}
            end
        %>

        template <
            template <typename ...> class fold,
            template <typename ...> class foldable>
        struct test_foldl :
            <% for n in 0..20 %>
                <%= ',' unless n == 0 -%>
                expect<fold<lift<f>, x<0>, foldable<
                    <%= xs(1..n).join(',') %>
                >>>::template to_eq<
                    <%= xs(1..n).foldl('x<0>'){|x,y| "f<#{x}, #{y}>" } %>
                >
            <% end %>
        { };
    } // end namespace foldl_detail

    using foldl_detail::test_foldl;
}}} // end namespace boost::mpl11::test

#endif // !BOOST_MPL11_TEST_FOLDL_HPP
