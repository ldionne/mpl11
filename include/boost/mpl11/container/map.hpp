/*!
 * @file
 * This file defines the `boost::mpl11::map` container.
 */

#ifndef BOOST_MPL11_CONTAINER_MAP_HPP
#define BOOST_MPL11_CONTAINER_MAP_HPP

#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/intrinsic/at.hpp>
#include <boost/mpl11/intrinsic/begin.hpp>
#include <boost/mpl11/intrinsic/clear.hpp>
#include <boost/mpl11/intrinsic/deref.hpp>
#include <boost/mpl11/intrinsic/empty.hpp>
#include <boost/mpl11/intrinsic/end.hpp>
#include <boost/mpl11/intrinsic/erase.hpp>
#include <boost/mpl11/intrinsic/erase_key.hpp>
#include <boost/mpl11/intrinsic/first.hpp>
#include <boost/mpl11/intrinsic/front.hpp>
#include <boost/mpl11/intrinsic/has_key.hpp>
#include <boost/mpl11/intrinsic/insert.hpp>
#include <boost/mpl11/intrinsic/key.hpp>
#include <boost/mpl11/intrinsic/next.hpp>
#include <boost/mpl11/intrinsic/second.hpp>
#include <boost/mpl11/intrinsic/size.hpp>
#include <boost/mpl11/intrinsic/value.hpp>
#include <boost/mpl11/size_t.hpp>

#include <boost/type_traits/is_same.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
template <typename ...Elements>
class map;

namespace map_detail {
    // This is a wrapper to allow us to work with incomplete types.
    template <typename T>
    struct wrap { using type = T; };

    template <typename T>
    struct unwrap : T { };

    template <typename Map, typename ...Elements>
    struct lookup_cell;

    template <typename Map, typename Element, typename ...Rest>
    struct lookup_cell<Map, Element, Rest...> : lookup_cell<Map, Rest...> {
    private:
        using Next = lookup_cell<Map, Rest...>;
        using Key = typename key<Map, Element>::type;
        using Value = typename value<Map, Element>::type;

    public:
        using this_element = Element;
        using next_cell = Next;

        using Next::has_key;
        static true_ has_key(wrap<Key>);

        using Next::at;
        template <typename Default>
        static wrap<Value> at(wrap<Key>, Default);
    };

    template <typename Map>
    struct lookup_cell<Map> {
        template <typename Key>
        static false_ has_key(Key);

        template <typename Key, typename Default>
        static Default at(Key, Default);
    };


    template <typename ...Elements>
    struct make_map {
        using type = map<Elements...>;
    };
}

template <typename ...Elements>
class map : public map_detail::make_map<Elements...> {
    using lookup_begin = map_detail::lookup_cell<map, Elements...>;
    using lookup_end = map_detail::lookup_cell<map>;

    template <typename Cell>
    class iterator {
        struct implementation {
            template <template <typename ...> class Impl, typename ...Args>
            struct apply;

            template <typename Iterator>
            struct apply<next, Iterator> {
                using type = iterator<typename Cell::next_cell>;
            };

            template <typename Iterator>
            struct apply<deref, Iterator> {
                using type = typename Cell::this_element;
            };
        };

    public:
        struct mpl11 { using dispatcher = implementation; };
    };

    struct implementation {
        template <template <typename ...> class Impl, typename ...Args>
        struct apply;

        template <typename Map>
        struct apply<begin, Map> {
            using type = iterator<lookup_begin>;
        };

        template <typename Map>
        struct apply<end, Map> {
            using type = iterator<lookup_end>;
        };

        template <typename Map>
        struct apply<size, Map>
            : size_t<sizeof...(Elements)>
        { };

        template <typename Map>
        struct apply<empty, Map>
            : bool_<sizeof...(Elements) == 0>
        { };

        template <typename Map>
        struct apply<front, Map>
            : deref<typename begin<Map>::type>
        { };

        template <typename Map, typename Key>
        struct apply<has_key, Map, Key>
            : decltype(lookup_begin::has_key(map_detail::wrap<Key>{}))
        { };

        struct fail;
        template <typename Map, typename Key>
        struct apply<at, Map, Key> : apply<at, Map, Key, fail> { };

        template <typename Map, typename Key, typename Default>
        struct apply<at, Map, Key, Default>
            : map_detail::unwrap<
                decltype(lookup_begin::at(map_detail::wrap<Key>{},
                                          map_detail::wrap<Default>{}))
            >
        {
            static_assert(!is_same<typename apply::type, fail>::value,
                "the requested key could not be found in the map "
                "and no default return value was specified");
        };

        template <typename Map, typename Element>
        struct apply<key, Map, Element>
            : first<Element>
        { };

        template <typename Map, typename Element>
        struct apply<value, Map, Element>
            : second<Element>
        { };

        template <typename Map>
        struct apply<clear, Map> {
            using type = map<>;
        };

        template <typename Map, typename Hint, typename Element>
        struct apply<insert, Map, Hint, Element>
            : apply<insert, Map, Element>
        { };

        template <typename Map, typename Element>
        struct apply<insert, Map, Element> {
            using type = map<Element, Elements...>;
        };

        template <typename Map, typename Position>
        struct apply<erase, Map, Position>
            : erase_key<Map,
                typename key<Map,
                    typename deref<Position>::type
                >::type
            >
        { };

        template <typename Map, typename Element, typename KeyToErase>
        struct erase_helper
            : if_<is_same<typename key<Map, Element>::type, KeyToErase>>
            ::template then<Map>
            ::template else_<eval<insert<Map, Element>>>
        { };

        template <typename Map, typename Key>
        struct apply<erase_key, Map, Key>
            : fold<
                Map, map<>, if_<is_same<key<_2, >>
            >
        {
            using type = map<>;
        };
    };

public:
    struct mpl11 { using dispatcher = implementation; };
};
}}}

#endif // !BOOST_MPL11_CONTAINER_MAP_HPP
