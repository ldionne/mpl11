/*!
 * @file
 * Defines the @ref Functional module.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_MPL11_FUNCTIONAL_HPP
#define BOOST_MPL11_FUNCTIONAL_HPP

#include <boost/mpl11/fwd/functional.hpp>

#include <boost/mpl11/detail/config.hpp>
#include <boost/mpl11/detail/std_index_sequence.hpp>
#include <boost/mpl11/detail/std_size_t.hpp>
#include <boost/mpl11/detail/strict_variadic_foldl.hpp>


namespace boost { namespace mpl11 {
    ////////////////////
    // always
    ////////////////////
    template <typename x>
    struct always {
        using type = always;

        template <typename ...>
        using apply = x;
    };

    ////////////////////
    // apply
    ////////////////////
    template <typename f, typename ...x>
    struct apply
        : f::type::template apply<x...>
    { };

    ////////////////////
    // flip
    ////////////////////
    template <typename f>
    struct flip {
        using type = flip;

#if defined(BOOST_MPL11_CLANG_FLIP_BUG)
        template <typename x0, typename x1, typename ...xs>
        struct apply : f::type::template apply<x1, x0, xs...> {};
#else
        template <typename x0, typename x1, typename ...xs>
        using apply = typename f::type::template apply<x1, x0, xs...>;
#endif
    };

    ////////////////////
    // partial
    ////////////////////
    template <typename f, typename ...x>
    struct partial {
        using type = partial;

        template <typename ...y>
        using apply = typename f::type::template apply<x..., y...>;
    };

    template <template <typename ...> class f, typename ...x>
    struct partial<quote<f>, x...> {
        using type = partial;

#if defined(BOOST_MPL11_GCC_PACK_EXPANSION_BUG)
        template <typename ...y>
        struct apply : f<x..., y...> { };
#else
        template <typename ...y>
        using apply = f<x..., y...>;
#endif
    };

    template <template <typename ...> class f, typename ...x>
    struct partial<into<f>, x...> {
        using type = partial;

        template <typename ...y>
        struct apply {
            using type = f<x..., y...>;
        };
    };

    ////////////////////
    // apply_curried
    ////////////////////
    template <typename f, typename ...xs>
    struct apply_curried
        : detail::strict_variadic_foldl<quote<apply>, f, xs...>
    { };

    ////////////////////
    // curry
    ////////////////////
    template <detail::std_size_t n, typename f>
    struct curry {
#if !defined(BOOST_MPL11_NO_ASSERTIONS)
        static_assert(n > 0,
        "Invalid usage of curry<n, f> with a zero-valued n.");
#endif

        using type = curry;

        template <typename x>
        using apply = curry<n-1, partial<f, x>>;
    };

    template <typename f>
    struct curry<1, f> {
        using type = curry;

        template <typename x>
        using apply = typename f::type::template apply<x>;
    };

    ////////////////////
    // uncurry
    ////////////////////
    template <detail::std_size_t n, typename f>
    struct uncurry {
        using type = uncurry;

#if defined(BOOST_MPL11_NO_ASSERTIONS)
        template <typename ...xs>
        using apply = apply_curried<f, xs...>;
#else
        static_assert(n > 0,
        "Invalid usage of uncurry<n, f> with a zero-valued n.");

        template <typename ...xs>
        struct apply : apply_curried<f, xs...> {
            static_assert(sizeof...(xs) <= n,
            "Invalid usage of uncurry<n, f> with more than n arguments.");

            static_assert(sizeof...(xs) >= n,
            "Invalid usage of uncurry<n, f> with less than n arguments.");
        };
#endif
    };


    ////////////////////
    // quote
    ////////////////////
    template <template <typename ...> class f>
    struct quote {
        using type = quote;

#if defined(BOOST_MPL11_GCC_PACK_EXPANSION_BUG)
        template <typename ...x>
        struct apply : f<x...> { };
#else
        template <typename ...x>
        using apply = f<x...>;
#endif
    };

    ////////////////////
    // into
    ////////////////////
    template <template <typename ...> class tp>
    struct into {
        using type = into;

        template <typename ...x>
        struct apply {
            using type = tp<x...>;
        };
    };

    ////////////////////
    // fix
    ////////////////////
    template <typename f>
    struct fix
        : partial<f, fix<f>>
    { };

    ////////////////////
    // compose
    ////////////////////
    namespace functional_detail {
        template <bool has_zero_args>
        struct compose_impl;

        template <>
        struct compose_impl<true> {
            template <typename f, typename g>
            using apply = typename f::type::template apply<
                typename g::type::template apply<>
            >;
        };

        template <>
        struct compose_impl<false> {
            template <typename f, typename g, typename x, typename ...xs>
            using apply = typename f::type::template apply<
                typename g::type::template apply<x>, xs...
            >;
        };
    } // end namespace functional_detail

    template <typename f, typename ...fs>
    struct compose {
        using type = compose;

        template <typename ...xs>
        using apply =
            typename functional_detail::compose_impl<sizeof...(xs) == 0>::
            template apply<f, compose<fs...>, xs...>;
    };

    template <typename f>
    struct compose<f> : f { };

    ////////////////////
    // argmap
    ////////////////////
    template <typename f, typename g>
    struct argmap {
        using type = argmap;

        template <typename ...x>
        using apply = typename f::type::template apply<
            typename g::type::template apply<x>...
        >;
    };

    ////////////////////
    // on
    ////////////////////
    template <typename f, typename ...fs>
    struct on {
        using type = on;

        template <typename ...x>
        using apply = typename f::type::template apply<
            typename fs::type::template apply<x>...
        >;
    };

    template <
        template <typename ...> class f,
        template <typename ...> class ...fs
    >
    struct on<quote<f>, quote<fs>...> {
        using type = on;

        template <typename ...x>
        using apply = f<fs<x>...>;
    };

    ////////////////////
    // bind
    ////////////////////
    template <typename f, typename ...fs>
    struct bind {
        using type = bind;

        template <typename ...x>
        using apply = typename f::type::template apply<
            typename fs::type::template apply<x...>...
        >;
    };

    template <
        template <typename ...> class f,
        template <typename ...> class ...fs
    >
    struct bind<quote<f>, quote<fs>...> {
        using type = bind;

        template <typename ...x>
        using apply = f<fs<x...>...>;
    };


    ////////////////////
    // arg
    ////////////////////
    namespace functional_detail {
        template <detail::std_size_t n, typename x>
        struct pair { };

        template <typename ns, typename ...xs>
        struct index_map;

        template <detail::std_size_t ...ns, typename ...xs>
        struct index_map<detail::std_index_sequence<ns...>, xs...>
            : pair<ns, xs>...
        { };

        template <detail::std_size_t n, typename x>
        x at_index(pair<n, x>*);
    }

    template <>
    struct arg<0>;

    template <detail::std_size_t n>
    struct arg {
        using type = arg;

        template <typename ...an>
        using apply = decltype(functional_detail::at_index<n-1>(
            (functional_detail::index_map<
                typename detail::make_std_index_sequence<sizeof...(an)>::type,
                an...
            >*)nullptr
        ));
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FUNCTIONAL_HPP
