/*!
 * @file
 * Defines unit tests for index-based lookup algorithms.
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

#ifndef BOOST_MPL11_DETAIL_TEST_AT_INDEX_HPP
#define BOOST_MPL11_DETAIL_TEST_AT_INDEX_HPP

#include <boost/mpl11/core.hpp>
#include <boost/mpl11/detail/std_is_same.hpp>
#include <boost/mpl11/detail/std_size_t.hpp>
#include <boost/mpl11/detail/test/expect.hpp>


namespace boost { namespace mpl11 { namespace detail {
namespace test_at_index_detail {
    template <int> struct x { struct type; };
    using u = undefined;

    template <template <std_size_t, typename ...> class at_index>
    struct test_at_index
        : instantiate<
            <%=
            1.upto(10).map { |size|
                (0...size).map { |index|
                    xs = (0...size).map{ |n| n == index ? "x<#{n}>" : "u" }.join(', ')
                    s = <<-EOS
                        typename expect<at_index<#{index}, #{xs}>>::
                        template to_eq<x<#{index}>>
                    EOS
                    s.squeeze(' ')
                }.join(",\n")
            }.join(",\n\n")
            %>
        >
    { };
}

using test_at_index_detail::test_at_index;
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_TEST_AT_INDEX_HPP
