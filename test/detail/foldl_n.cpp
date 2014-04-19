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

#include <boost/mpl11/foldable.hpp>
#include <boost/mpl11/list.hpp>
#include <boost/mpl11/test/foldable.hpp>


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
            : detail::foldl_n<sizeof...(xs), f, z, list<xs...>>
        { };
    };
}}

struct tests
    : boost::mpl11::test::Foldable<minimal>
{ };


int main() { }
