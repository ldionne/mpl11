/*!
 * @file
 * This file defines the `boost::mpl11::set` container.
 */

#ifndef BOOST_MPL11_CONTAINER_SET_HPP
#define BOOST_MPL11_CONTAINER_SET_HPP

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/container/map.hpp>
#include <boost/mpl11/container/pair.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
namespace set_detail {
template <typename Map>
class set_impl {
    template <typename Iterator>
    class iterator {
        struct implementation {
            template <typename Operation, typename ...Args>
            struct apply
                : mpl11::apply<Operation, Iterator, Args...>
            { };

            template <typename ...Args>
            struct apply<intrinsic::next, Args...> {
                using type = iterator<
                    typename next<Iterator, Args...>::type
                >;
            };

            template <typename ...Args>
            struct apply<intrinsic::deref, Args...>
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
        template <typename Operation, typename ...Args>
        struct apply
            : mpl11::apply<Operation, Map, Args...>
        { };

        // We wrap all the intrinsics that return a map so that they return a
        // set.
        template <typename Hint, typename Element>
        struct apply<intrinsic::insert, Hint, Element>
            : wrap<insert<Map, pair<Element, Element>>>
        { };

        template <typename Element>
        struct apply<intrinsic::insert, Element>
            : wrap<insert<Map, pair<Element, Element>>>
        { };

        template <typename ...Args>
        struct apply<intrinsic::erase, Args...>
            : wrap<erase<Map, Args...>>
        { };

        template <typename ...Args>
        struct apply<intrinsic::erase_key, Args...>
            : wrap<erase_key<Map, Args...>>
        { };

        template <typename ...Args>
        struct apply<intrinsic::clear, Args...>
            : wrap<clear<Map, Args...>>
        { };

        // We wrap front so that it returns a single type instead of a pair.
        template <typename ...Args>
        struct apply<intrinsic::front, Args...>
            : key<Map, typename front<Map, Args...>::type>
        { };

        // We wrap value and key so that they return the element itself.
        template <typename Element>
        struct apply<intrinsic::key, Element> {
            using type = Element;
        };

        template <typename Element>
        struct apply<intrinsic::value, Element> {
            using type = Element;
        };

        // We wrap begin and end so that they return modified iterators
        template <typename ...Args>
        struct apply<intrinsic::begin, Args...> {
            using type = iterator<
                typename begin<Map, Args...>::type
            >;
        };

        template <typename ...Args>
        struct apply<intrinsic::end, Args...> {
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
