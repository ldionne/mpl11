/*!
 * @file
 * Defines unit tests for key-based lookup algorithms.
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

#ifndef BOOST_MPL11_DETAIL_TEST_AT_KEY_HPP
#define BOOST_MPL11_DETAIL_TEST_AT_KEY_HPP

#include <boost/mpl11/core.hpp>
#include <boost/mpl11/detail/pair.hpp>
#include <boost/mpl11/detail/std_is_same.hpp>
#include <boost/mpl11/detail/test/expect.hpp>


namespace boost { namespace mpl11 { namespace detail {
namespace test_at_key_detail {
    template <int> struct k { struct type; };
    template <int> struct v { struct type; };
    using u = undefined;

    template <template <typename ...> class at_key>
    struct test_at_key
        : instantiate<
            <%=
            1.upto(10).map { |size|
                (0...size).map { |index|
                    pairs = (0...size).map{ |n|
                        n == index ? "pair<k<#{n}>, v<#{n}>>"
                                   : "pair<k<#{n}>, u>"
                    }.join(', ')
                    s = <<-EOS
                        typename expect<at_key<k<#{index}>, #{pairs}>>::
                        template to_eq<v<#{index}>>
                    EOS
                    s.squeeze(' ')
                }.join(",\n")
            }.join(",\n\n")
            %>
        >
    { };
}

using test_at_key_detail::test_at_key;
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_TEST_AT_KEY_HPP
