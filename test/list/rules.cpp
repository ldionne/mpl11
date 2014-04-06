/*!
 * @file
 * Contains unit tests for rewrite rules of @ref List.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#include <boost/mpl11/list.hpp>

#include <boost/mpl11/core.hpp>
#include <boost/mpl11/detail/std_is_same.hpp>
#include <boost/mpl11/functional.hpp>


using namespace boost::mpl11;

template <typename ...xs>
struct check_length {
    template <typename ...ys>
    using seq = foldr<lift<cons>, list<xs...>, list<ys...>>;
    static_assert(length<seq<>>::value == sizeof...(xs), "");
    static_assert(length<seq<undefined>>::value == 1 + sizeof...(xs), "");
    static_assert(length<seq<undefined, undefined>>::value == 2 + sizeof...(xs), "");
};

template <unsigned long index>
struct check_at {
    struct x;
    static_assert(detail::std_is_same<
        typename at_c<index, repeat<box<x>>>::type, x
    >::value, "");
};

struct tests
    : check_length<>
    , check_length<undefined>
    , check_length<undefined, undefined>
    , check_length<undefined, undefined, undefined>

    , check_at<0>
    , check_at<1>
    , check_at<2>
    , check_at<3>
    , check_at<4>
{ };


int main() { }
