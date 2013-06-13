/*!
 * @file
 * This file defines `boost::mpl11::bind`.
 */

#ifndef BOOST_MPL11_BIND_HPP
#define BOOST_MPL11_BIND_HPP

#include <boost/mpl11/apply_raw.hpp>
#include <boost/mpl11/detail/basic_map.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
#if 0
namespace bind_detail {
    template <typename Sequence> struct apply_raw_first_to_rest;
    template <typename First, typename ...Rest>
    struct apply_raw_first_to_rest<vector<First, Rest...>>
        : apply_raw<First, Rest...>
    { };

    template <template <typename ...> class Destination, typename Source>
    struct unpack_into;

    template <template <typename ...> class Destination,
              template <typename ...> class Source, typename ...T>
    struct unpack_into<Destination, Source<T...>> {
        using type = Destination<T...>;
    };

    template <typename T, typename ArgumentMap>
    struct substitute_rec
        : identity<T>
    { };

    template <template <typename...> class N, typename ...T, typename ArgumentMap>
    struct substitute_rec<N<T...>, ArgumentMap> {
        using subs = typename flatten<
            vector<typename substitute<T, ArgumentMap>::type...>
        >::type;
        using type = typename unpack_into<N, subs>::type;
    };

    template <typename T, typename ArgumentMap>
    struct substitute
        : eval_if<is_placeholder<T>, apply<T, ArgumentMap>>::template
          eval_else<substitute_rec<T, ArgumentMap>>
    { };

    template <template <typename ...> class N, typename ...T, typename Argmap>
    struct substitute<N<T...>, Argmap> {
        using type = N<typename substitute<T, Argmap>::type...>;
    };

    template <unsigned long N, typename ...Args>
    struct make_argmap { using type = detail::basic_map<>; };

    template <unsigned long N, typename A0, typename ...An>
    struct make_argmap<N, A0, ...An>
        : make_argmap<N + 1, An...>::type::template push_front<
            pair<typename as_key<A0, N>::type, typename as_value<A0, N>::type>
        >
    { };
}


template <typename ...Placeholders>
struct bind {
    template <typename ...Args>
    struct apply
        : bind_detail::apply_raw_first_to_rest<
            typename bind_detail::substitute<
                vector<Placeholders...>,
                typename bind_detail::make_argmap<0, Args...>::type
            >::type
        >
    { };
};
#else
template <typename M, typename ...Placeholders>
struct bind {
    template <typename ...Args>
    struct apply
        : apply_raw<M, Args...>
    { };
};
#endif
}}}

#endif // !BOOST_MPL11_BIND_HPP
