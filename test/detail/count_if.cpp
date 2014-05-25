/*!
 * @file
 * Contains unit tests for the `count_if` algorithm.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#include <boost/mpl11/detail/count_if/variadic_sizeof.hpp>
#include <boost/mpl11/detail/count_if/variadic_sum.hpp>

#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/functional.hpp>
using namespace boost::mpl11;


template <template <template <typename ...> class, typename ...> class count_if>
struct test_count_if {
    static_assert(count_if<id>::value == 0, "");

    static_assert(count_if<id, true_>::value == 1, "");
    static_assert(count_if<id, false_>::value == 0, "");

    static_assert(count_if<id, true_, true_>::value == 2, "");
    static_assert(count_if<id, true_, false_>::value == 1, "");
    static_assert(count_if<id, false_, true_>::value == 1, "");
    static_assert(count_if<id, false_, false_>::value == 0, "");

    static_assert(count_if<id, true_, true_, true_>::value == 3, "");
    static_assert(count_if<id, true_, true_, false_>::value == 2, "");
    static_assert(count_if<id, true_, false_, true_>::value == 2, "");
    static_assert(count_if<id, true_, false_, false_>::value == 1, "");
    static_assert(count_if<id, false_, true_, true_>::value == 2, "");
    static_assert(count_if<id, false_, true_, false_>::value == 1, "");
    static_assert(count_if<id, false_, false_, true_>::value == 1, "");
    static_assert(count_if<id, false_, false_, false_>::value == 0, "");
};

struct tests
    : test_count_if<detail::count_if::variadic_sizeof>
    , test_count_if<detail::count_if::variadic_sum>
{ };


int main() { }
