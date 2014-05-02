/*!
 * @file
 * Contains unit tests for the various logical or implementations.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#include <boost/mpl11/detail/logical_or/lazy_naive_struct.hpp>
#include <boost/mpl11/detail/logical_or/strict_is_same.hpp>
#include <boost/mpl11/detail/logical_or/strict_noexcept.hpp>
#include <boost/mpl11/detail/logical_or/strict_overload.hpp>
#include <boost/mpl11/detail/logical_or/strict_specialization.hpp>

#include <boost/mpl11/detail/test/logical_or.hpp>


using namespace boost::mpl11;

struct tests
    : detail::test_logical_or_strict<detail::logical_or::strict_overload>
    , detail::test_logical_or_strict<detail::logical_or::strict_noexcept>
    , detail::test_logical_or_strict<detail::logical_or::strict_specialization>
    , detail::test_logical_or_strict<detail::logical_or::strict_is_same>

    , detail::test_logical_or_lazy<detail::logical_or::lazy_naive_struct>
{ };


int main() { }
