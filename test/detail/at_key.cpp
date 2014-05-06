/*!
 * @file
 * Contains unit tests for the various key-based lookup implementations.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#include <boost/mpl11/detail/at_key/multiple_inheritance.hpp>
#include <boost/mpl11/detail/at_key/single_inheritance.hpp>

#include <boost/mpl11/detail/test/at_key.hpp>


using namespace boost::mpl11;

struct tests
    : detail::test_at_key<detail::at_key::multiple_inheritance>
    , detail::test_at_key<detail::at_key::single_inheritance>
{ };


int main() { }
