/*!
 * @file
 * This file defines the `boost::mpl11::set` container.
 */

#ifndef BOOST_MPL11_CONTAINER_SET_HPP
#define BOOST_MPL11_CONTAINER_SET_HPP

#include <boost/mpl11/container/map.hpp>
#include <boost/mpl11/container/pair.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
namespace set_detail {
template <typename Map>
class set_impl {
    template <typename Iterator>
    class iterator {
        struct implementation {
            template <template <typename ...> class Impl,
                      typename Ignore, typename ...Args>
            struct apply
                : Impl<Iterator, Args...>
            { };

            template <typename Ignore, typename ...Args>
            struct apply<next, Ignore, Args...> {
                using type = iterator<
                    typename next<Iterator, Args...>::type
                >;
            };

            template <typename Ignore, typename ...Args>
            struct apply<prior, Ignore, Args...> {
                using type = iterator<
                    typename prior<Iterator, Args...>::type
                >;
            };

            template <typename Ignore, typename ...Args>
            struct apply<deref, Ignore, Args...>
                : key<Map, typename deref<Iterator, Args...>::type>
            { };
        };

    public:
        struct mpl11 { using delegate = implementation; };
    };

    template <typename Metafunction>
    struct wrap {
        using type = set_impl<typename Metafunction::type>;
    };

    struct implementation {
        template <template <typename ...> class Impl,
                  typename Ignore, typename ...Args>
        struct apply
            : Impl<Map, Args...>
        { };

        // We wrap all the intrinsics that return a map so that they return a
        // set.
        template <typename Ignore, typename Hint, typename Element>
        struct apply<insert, Ignore, Hint, Element>
            : wrap<insert<Map, pair<Element, Element>>>
        { };

        template <typename Ignore, typename Element>
        struct apply<insert, Ignore, Element>
            : wrap<insert<Map, pair<Element, Element>>>
        { };

        template <typename Ignore, typename ...Args>
        struct apply<erase, Ignore, Args...>
            : wrap<erase<Map, Args...>>
        { };

        template <typename Ignore, typename ...Args>
        struct apply<erase_key, Ignore, Args...>
            : wrap<erase_key<Map, Args...>>
        { };

        template <typename Ignore, typename ...Args>
        struct apply<clear, Ignore, Args...>
            : wrap<clear<Map, Args...>>
        { };

        // We wrap front so that it returns a single type instead of a pair.
        template <typename Ignore, typename ...Args>
        struct apply<front, Ignore, Args...>
            : key<Map, typename front<Map, Args...>::type>
        { };

        // We wrap value and key so that they return the element itself.
        template <typename Ignore, typename Element>
        struct apply<key, Ignore, Element> {
            using type = Element;
        };

        template <typename Ignore, typename Element>
        struct apply<value, Ignore, Element> {
            using type = Element;
        };

        // We wrap begin and end so that they return modified iterators
        template <typename Ignore, typename ...Args>
        struct apply<begin, Ignore, Args...> {
            using type = iterator<
                typename begin<Map, Args...>::type
            >;
        };

        template <typename Ignore, typename ...Args>
        struct apply<end, Ignore, Args...> {
            using type = iterator<
                typename end<Map, Args...>::type
            >;
        };
    };

public:
    using type = set_impl;
    struct mpl11 { using dispatcher = implementation; };
};
} // end namespace set_detail

template <typename ...Elements>
using set = set_detail::set_impl<map<pair<Elements, Elements>...>>;
}}}

#endif // !BOOST_MPL11_CONTAINER_SET_HPP
