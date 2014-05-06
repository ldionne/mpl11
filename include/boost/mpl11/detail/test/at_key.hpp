/*!
 * @file
 * Defines unit tests for at_key algorithms.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_MPL11_DETAIL_TEST_AT_KEY_HPP
#define BOOST_MPL11_DETAIL_TEST_AT_KEY_HPP

#include <boost/mpl11/detail/pair.hpp>
#include <boost/mpl11/detail/std_is_same.hpp>
#include <boost/mpl11/detail/test/expect.hpp>


namespace boost { namespace mpl11 { namespace detail {
namespace test_at_key_detail {
    template <int> struct k { using type = k; };
    template <int> struct v { using type = v; };
    template <int i, int j> using p = pair<k<i>, v<j>>;

    template <template <typename ...> class at_key>
    struct test_at_key
        : instantiate<

            typename expect<at_key<k<0>, p<0, 0>>>::
            to::template be_<std_is_same>::template with<v<0>>

            , typename expect<at_key<k<0>, p<0, 0>, p<1, 1>>>::
              to::template be_<std_is_same>::template with<v<0>>
            , typename expect<at_key<k<1>, p<0, 0>, p<1, 1>>>::
              to::template be_<std_is_same>::template with<v<1>>
        >
    { };
}

using test_at_key_detail::test_at_key;
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_TEST_AT_KEY_HPP
