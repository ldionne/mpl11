/*!
 * @file
 * Contains unit tests for the various index-based lookup implementations.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#include <boost/mpl11/detail/at_index/multiple_inheritance.hpp>
#include <boost/mpl11/detail/at_index/multiple_inheritance2.hpp>
#include <boost/mpl11/detail/at_index/overload_resolution.hpp>

#include <boost/mpl11/detail/test/at_index.hpp>


using namespace boost::mpl11;

struct tests
    : detail::test_at_index<detail::at_index::multiple_inheritance>
    , detail::test_at_index<detail::at_index::overload_resolution>
    , detail::test_at_index<detail::at_index::multiple_inheritance2>
{ };


int main() { }
