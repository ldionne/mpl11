/*!
 * @file
 * Contains unit tests for the various right fold implementations.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#include <boost/mpl11/detail/right_folds/variadic.hpp>
#include <boost/mpl11/detail/right_folds/variadic_naive.hpp>

#include <boost/mpl11/detail/test/foldr.hpp>
#include <boost/mpl11/list.hpp>


using namespace boost::mpl11;

template <typename f, typename z, typename ...xs>
using variadic = detail::right_folds::variadic<
    f::type::template apply, z, xs...
>;

template <typename f, typename z, typename ...xs>
using variadic_naive = detail::right_folds::variadic_naive<
    f::type::template apply, z, xs...
>;


struct tests
    : detail::test_foldr<variadic>
    , detail::test_foldr<variadic_naive>
{ };


int main() { }
