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
#include <boost/mpl11/test/foldl.hpp>


namespace mpl11 = boost::mpl11;

template <typename f, typename z, typename xs>
using foldl_n = mpl11::detail::foldl_n<mpl11::length<xs>::value, f, z, xs>;

struct tests
    : mpl11::test::test_foldl<foldl_n, mpl11::list>
{ };


int main() { }
