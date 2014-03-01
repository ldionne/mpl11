/*!
 * @file
 * Defines the @ref Functional module.
 */

#ifndef BOOST_MPL11_FUNCTIONAL_HPP
#define BOOST_MPL11_FUNCTIONAL_HPP

#include <boost/mpl11/fwd/functional.hpp>

#include <boost/mpl11/detail/config.hpp>


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

        template <typename ...y>
        using apply = f<x..., y...>;
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
    // quote
    ////////////////////
    template <template <typename ...> class f>
    struct quote {
        using type = quote;

        template <typename ...x>
        using apply = f<x...>;
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
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FUNCTIONAL_HPP
