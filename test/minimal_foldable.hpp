/*!
 * @file
 * Defines the `minimal_foldable` helper for unit tests.
 */

#ifndef BOOST_MPL11_TEST_MINIMAL_FOLDABLE_HPP
#define BOOST_MPL11_TEST_MINIMAL_FOLDABLE_HPP

#include <boost/mpl11/core.hpp>
#include <boost/mpl11/foldable.hpp>


struct MinimalFoldable;

template <typename ...xs>
struct minimal_foldable {
    using type = minimal_foldable;
    using mpl_datatype = MinimalFoldable;
};

namespace boost { namespace mpl11 {
    template <>
    struct Foldable<MinimalFoldable>
        : instantiate<Foldable>::with<MinimalFoldable>
    {
        template <typename f, typename state, typename structure>
        struct foldl_impl : state { };

        template <typename f, typename state, typename x, typename ...xs>
        struct foldl_impl<f, state, minimal_foldable<x, xs...>>
            : foldl_impl<
                f,
                typename f::type::template apply<state, x>,
                minimal_foldable<xs...>
            >
        { };


        template <typename f, typename state, typename structure>
        struct foldr_impl : state { };

        template <typename f, typename state, typename x, typename ...xs>
        struct foldr_impl<f, state, minimal_foldable<x, xs...>>
            : f::type::template apply<
                x, foldr_impl<f, state, minimal_foldable<xs...>>
            >
        { };


        template <typename f, typename structure>
        struct foldl1_impl;

        template <typename f, typename x, typename ...xs>
        struct foldl1_impl<f, minimal_foldable<x, xs...>>
            : foldl_impl<f, x, minimal_foldable<xs...>>
        { };


        template <typename f, typename structure>
        struct foldr1_impl;

        template <typename f, typename x>
        struct foldr1_impl<f, minimal_foldable<x>> : x { };

        template <typename f, typename x, typename ...xs>
        struct foldr1_impl<f, minimal_foldable<x, xs...>>
            : f::type::template apply<
                x, foldr1_impl<f, minimal_foldable<xs...>>
            >
        { };
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_TEST_MINIMAL_FOLDABLE_HPP
