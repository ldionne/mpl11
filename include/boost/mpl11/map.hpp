/*!
 * @file
 * This file defines the `boost::mpl11::map` container.
 */

#ifndef BOOST_MPL11_MAP_HPP
#define BOOST_MPL11_MAP_HPP

#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/detail/none.hpp>
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
struct map;

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

    template <typename Map, typename Cell>
    struct map_iterator {
        struct mpl11 { using tag = map_iterator; };
    };
}

template <typename ...Elements>
struct map : map_detail::make_map<Elements...> {
    struct mpl11 { using tag = map; };

private:
    friend extension::begin_impl<map>;
    friend extension::end_impl<map>;
    using lookup_begin = map_detail::lookup_cell<map, Elements...>;
    using lookup_end = map_detail::lookup_cell<map>;
};

namespace extension {
    template <typename Map, typename Cell>
    struct next_impl<map_detail::map_iterator<Map, Cell>> {
        template <typename Iterator>
        struct apply {
            using type = map_detail::map_iterator<
                Map, typename Cell::next_cell
            >;
        };
    };

    template <typename Map, typename Cell>
    struct deref_impl<map_detail::map_iterator<Map, Cell>> {
        template <typename Iterator>
        struct apply {
            using type = typename Cell::this_element;
        };
    };

    template <typename ...Elements>
    struct begin_impl<map<Elements...>> {
        template <typename Map>
        struct apply {
            using type = map_detail::map_iterator<
                Map, typename Map::lookup_begin
            >;
        };
    };

    template <typename ...Elements>
    struct end_impl<map<Elements...>> {
        template <typename Map>
        struct apply {
            using type = map_detail::map_iterator<
                Map, typename Map::lookup_end
            >;
        };
    };

    template <typename ...Elements>
    struct size_impl<map<Elements...>> {
        template <typename Map>
        struct apply
            : size_t<sizeof...(Elements)>
        { };
    };

    template <typename ...Elements>
    struct empty_impl<map<Elements...>> {
        template <typename Map>
        struct apply
            : bool_<sizeof...(Elements) == 0>
        { };
    };

    template <typename ...Elements>
    struct front_impl<map<Elements...>> {
        template <typename Map>
        struct apply
            : deref<typename begin<Map>::type>
        { };
    };

    template <typename ...Elements>
    struct has_key_impl<map<Elements...>> {
        template <typename Map, typename Key>
        struct apply
            : decltype(Map::lookup_begin::has_key(map_detail::wrap<Key>{}))
        { };
    };

    template <typename ...Elements>
    struct at_impl<map<Elements...>> {
        struct fail;
        template <typename Map, typename Key, typename Default = fail>
        struct apply
            : map_detail::unwrap<
               decltype(Map::lookup_begin::at(map_detail::wrap<Key>{},
                                              map_detail::wrap<Default>{}))
            >
        {
            static_assert(!is_same<typename apply::type, fail>::value,
                "the requested key could not be found in the map");
        };
    };

    template <typename ...Elements>
    struct key_impl<map<Elements...>> {
        template <typename Map, typename Element>
        struct apply : first<Element> { };
    };

    template <typename ...Elements>
    struct value_impl<map<Elements...>> {
        template <typename Map, typename Element>
        struct apply : second<Element> { };
    };

    template <typename ...Elements>
    struct clear_impl<map<Elements...>> {
        template <typename Map, typename Element>
        struct apply {
            using type = map<>;
        };
    };

    template <typename ...Elements>
    struct insert_impl<map<Elements...>> {
        template <typename Map, typename Hint, typename Element = detail::none>
        struct apply : apply<Map, Element> { };

        template <typename Map, typename Element>
        struct apply<Map, Element, detail::none> {
            using type = map<Element, Elements...>;
        };
    };

    template <typename ...Elements>
    struct erase_impl<map<Elements...>> {
        template <typename Map, typename Position>
        struct apply
            : erase_key<Map,
                typename key<Map,
                    typename deref<Position>::type
                >::type
            >
        { };
    };
}
}}}

#endif // !BOOST_MPL11_MAP_HPP
