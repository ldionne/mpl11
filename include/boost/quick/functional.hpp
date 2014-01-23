/*!
 * @file
 * Defines the @ref Functional module.
 */

#ifndef BOOST_MPL11_FUNCTIONAL_HPP
#define BOOST_MPL11_FUNCTIONAL_HPP

#include <boost/mpl11/fwd/functional.hpp>


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
    template <typename f, typename ...args>
    struct apply
        : f::type::template apply<args...>
    { };

    ////////////////////
    // flip
    ////////////////////
    template <typename f>
    struct flip {
        using type = flip;

        template <typename a0, typename a1, typename ...aN>
        using apply = typename f::type::template apply<a1, a0, aN...>;
    };

    ////////////////////
    // partial
    ////////////////////
    template <typename f, typename ...x>
    struct partial {
        using type = partial;

        template <typename ...args>
        using apply = typename f::type::template apply<f, x..., args...>;
    };

    template <template <typename ...> class f, typename ...x>
    struct partial<quote<f>, x...> {
        using type = partial;

        template <typename ...args>
        using apply = f<x..., args...>;
    };

    template <template <typename ...> class f, typename ...x>
    struct partial<into<f>, x...> {
        using type = partial;

        template <typename ...args>
        struct apply {
            using type = f<x..., args...>;
        };
    };

    ////////////////////
    // compose
    ////////////////////
    template <typename f, typename ...fs>
    struct compose {
        using type = compose;

        template <typename ...args>
        using apply = typename f::type::template apply<
            typename compose<fs...>::type::template apply<args...>
        >;
    };

    template <typename f>
    struct compose<f> : f { };

    ////////////////////
    // quote
    ////////////////////
    template <template <typename ...> class f>
    struct quote {
        using type = quote;

        template <typename ...args>
        using apply = f<args...>;
    };

    ////////////////////
    // into
    ////////////////////
    template <template <typename ...> class tp>
    struct into {
        using type = into;

        template <typename ...args>
        struct apply {
            using type = tp<args...>;
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
    // on
    ////////////////////
    template <typename f, typename ...fs>
    struct on {
        using type = on;

        template <typename ...x>
        using apply = typename f::type::template apply<
            typename compose<fs...>::type::template apply<x>...
        >;
    };

    template <typename f>
    struct on<f> : f { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FUNCTIONAL_HPP
