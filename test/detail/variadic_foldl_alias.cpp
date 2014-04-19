/*!
 * @file
 * Contains unit tests for `boost::mpl11::detail::variadic_foldl_alias`.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#include <boost/mpl11/detail/variadic_foldl_alias.hpp>

#include <boost/mpl11/detail/test/foldable.hpp>
#include <boost/mpl11/foldable.hpp>
#include <boost/mpl11/list.hpp>


struct Minimal;
template <typename ...xs>
struct minimal_ { using mpl_datatype = Minimal; };

template <typename ...xs>
struct minimal { using type = minimal_<xs...>; };

namespace boost { namespace mpl11 {
    template <>
    struct Foldable<Minimal> : instantiate<Foldable>::with<Minimal> {
        template <typename f, typename z, typename t>
        struct foldr_impl;

        template <typename f, typename z, typename ...xs>
        struct foldr_impl<f, z, minimal_<xs...>>
            : foldr<f, z, list<xs...>>
        { };

        template <typename f, typename z, typename t>
        struct foldl_impl;

        template <typename f, typename z, typename ...xs>
        struct foldl_impl<f, z, minimal_<xs...>>
            : detail::variadic_foldl_alias<f, z, xs...>
        { };
    };
}}

struct tests
    : boost::mpl11::detail::test_Foldable<minimal>
{ };


int main() { }
