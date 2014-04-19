/*!
 * @file
 * Contains unit tests for `boost::mpl11::detail::foldl_n`.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#include <boost/mpl11/detail/foldl_n.hpp>

#include <boost/mpl11/list.hpp>
#include <boost/mpl11/detail/test/foldl.hpp>


using namespace boost::mpl11;

template <typename f, typename z, typename xs>
using foldl_n = detail::foldl_n<length<xs>::value, f, z, xs>;

struct tests
    : detail::test_foldl<foldl_n, list>
{ };


int main() { }
