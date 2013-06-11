/*!
 * @file
 * This file defines `boost::mpl11::bind`.
 */

#ifndef BOOST_MPL11_BIND_HPP
#define BOOST_MPL11_BIND_HPP

namespace boost { namespace mpl11 { inline namespace v2 {
namespace bind_detail {
    template <typename Sequence> struct apply_raw_first_to_rest;
    template <typename First, typename ...Rest>
    struct apply_raw_first_to_rest<vector<First, Rest...>>
        : apply_raw<First, Rest...>
    { };

    template <typename Placeholders, typename Argmap>
    struct substitute { };

    template <typename ...Args>
    struct make_argmap;

    template <>
    struct make_argmap<> { using type = map<>; };

    template <typename A0, typename ...An>
    struct make_argmap
        : insert<typename make_argmap<An...>::type,
            pair<typename as_key<A0>::type, A0>
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
                typename bind_detail::make_argmap<Args...>::type
            >::type
        >
    { };
};
}}}

#endif // !BOOST_MPL11_BIND_HPP
