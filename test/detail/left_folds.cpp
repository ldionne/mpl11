/*!
 * @file
 * Contains unit tests for the various left fold implementations.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#include <boost/mpl11/detail/left_folds/bounded.hpp>
#include <boost/mpl11/detail/left_folds/variadic.hpp>
#include <boost/mpl11/detail/left_folds/variadic_aliased.hpp>
#include <boost/mpl11/detail/left_folds/variadic_naive.hpp>

#include <boost/mpl11/detail/test/foldl.hpp>
#include <boost/mpl11/functional.hpp>
#include <boost/mpl11/list.hpp>


using namespace boost::mpl11;

template <typename f, typename z, typename xs>
using bounded = detail::left_folds::bounded<length<xs>::value, f, z, xs>;

template <typename f, typename z, typename xs>
using variadic_naive = unpack<
    partial<lift<detail::left_folds::variadic_naive>, f, z>,
    xs
>;

template <typename f, typename z, typename xs>
using variadic = unpack<
    partial<lift<detail::left_folds::variadic>, f, z>,
    xs
>;

template <typename f, typename z, typename xs>
using variadic_aliased = unpack<
    partial<lift<detail::left_folds::variadic_aliased>, f, z>,
    xs
>;


struct tests
    : detail::test_foldl<bounded, list>
    , detail::test_foldl<variadic_naive, list>
    , detail::test_foldl<variadic, list>
    , detail::test_foldl<variadic_aliased, list>
{ };


int main() { }
