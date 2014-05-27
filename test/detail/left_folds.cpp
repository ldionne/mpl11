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
#include <boost/mpl11/detail/left_folds/until_aliased.hpp>
#include <boost/mpl11/detail/left_folds/until_naive.hpp>
#include <boost/mpl11/detail/left_folds/until_unrolled.hpp>
#include <boost/mpl11/detail/left_folds/variadic_aliased.hpp>
#include <boost/mpl11/detail/left_folds/variadic_arrow.hpp>
#include <boost/mpl11/detail/left_folds/variadic_naive.hpp>
#include <boost/mpl11/detail/left_folds/variadic_unrolled.hpp>
#include <boost/mpl11/detail/left_folds/variadic_variabletp.hpp>

#include <boost/mpl11/detail/test/foldl.hpp>
#include <boost/mpl11/list.hpp>


using namespace boost::mpl11;

template <typename f, typename z, typename ...xs>
using bounded = detail::left_folds::bounded<
    sizeof...(xs), f::type::template apply, z, list<xs...>
>;

template <typename f, typename z, typename ...xs>
using variadic_naive = detail::left_folds::variadic_naive<
    f::type::template apply, z, xs...
>;

template <typename f, typename z, typename ...xs>
using variadic_unrolled = detail::left_folds::variadic_unrolled<
    f::type::template apply, z, xs...
>;

template <typename f, typename z, typename ...xs>
using variadic_aliased = detail::left_folds::variadic_aliased<
    f::type::template apply, z, xs...
>;

template <typename f, typename z, typename ...xs>
using variadic_arrow = detail::left_folds::variadic_arrow<
    f::type::template apply, z, xs...
>;

template <typename f, typename z, typename ...xs>
using variadic_variabletp = detail::left_folds::variadic_variabletp<
    f::type::template apply, z, xs...
>;

template <typename f, typename z, typename ...xs>
using until_unrolled = detail::left_folds::until_unrolled<
    is_empty, f::type::template apply, z, list<xs...>
>;

template <typename f, typename z, typename ...xs>
using until_aliased = detail::left_folds::until_aliased<
    is_empty, f::type::template apply, z, list<xs...>
>;

template <typename f, typename z, typename ...xs>
using until_naive = detail::left_folds::until_naive<
    is_empty, f::type::template apply, z, list<xs...>
>;


struct tests
    : detail::test_foldl<bounded>
    , detail::test_foldl<variadic_aliased>
    , detail::test_foldl<variadic_naive>
    , detail::test_foldl<variadic_unrolled>
    , detail::test_foldl<variadic_arrow>
    , detail::test_foldl<variadic_variabletp>
    , detail::test_foldl<until_aliased>
    , detail::test_foldl<until_naive>
    , detail::test_foldl<until_unrolled>
{ };


int main() { }
