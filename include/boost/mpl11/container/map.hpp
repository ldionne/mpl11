/*!
 * @file
 * This file defines the `boost::mpl11::map` container.
 */

#ifndef BOOST_MPL11_CONTAINER_MAP_HPP
#define BOOST_MPL11_CONTAINER_MAP_HPP

#include <boost/mpl11/algorithm/fold.hpp>
#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/if.hpp>
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

struct iterator_implementation {
    template <template <typename ...> class Impl, typename ...Args>
    struct apply;

    template <template <typename> class Iterator, typename Cell>
    struct apply<next, Iterator<Cell>> {
        using type = Iterator<typename Cell::next_cell>;
    };

    template <template <typename> class Iterator, typename Cell>
    struct apply<deref, Iterator<Cell>> {
        using type = typename Cell::this_element;
    };
};

template <typename Cell>
struct map_iterator {
    struct mpl11 { using dispatcher = iterator_implementation; };
};

struct map_implementation {
    template <template <typename ...> class Impl, typename ...Args>
    struct apply;

    template <template <typename ...> class Map, typename ...Elements>
    struct apply<begin, Map<Elements...>> {
        using type = map_iterator<
            lookup_cell<Map<Elements...>, Elements...>
        >;
    };

    template <template <typename ...> class Map, typename ...Elements>
    struct apply<end, Map<Elements...>> {
        using type = map_iterator<
            lookup_cell<Map<Elements...>>
        >;
    };

    template <template <typename ...> class Map, typename ...Elements>
    struct apply<size, Map<Elements...>>
        : size_t<sizeof...(Elements)>
    { };

    template <template <typename ...> class Map, typename ...Elements>
    struct apply<empty, Map<Elements...>>
        : bool_<sizeof...(Elements) == 0>
    { };

    template <typename Map>
    struct apply<front, Map>
        : deref<typename begin<Map>::type>
    { };

    template <template <typename ...> class Map, typename ...Elements,
              typename Key>
    struct apply<has_key, Map<Elements...>, Key>
        : decltype(
            lookup_cell<Map<Elements...>, Elements...>::has_key(wrap<Key>{})
        )
    { };

    struct fail;
    template <typename Map, typename Key>
    struct apply<at, Map, Key>
        : apply<at, Map, Key, fail>
    { };

    template <template <typename ...> class Map, typename ...Elements,
              typename Key, typename Default>
    struct apply<at, Map<Elements...>, Key, Default>
        : unwrap<
            decltype(lookup_cell<Map<Elements...>, Elements...>::
                at(wrap<Key>{}, wrap<Default>{})
            )
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

    template <template <typename ...> class Map, typename ...Elements>
    struct apply<clear, Map<Elements...>> {
        using type = Map<>;
    };

    template <typename Map, typename Hint, typename Element>
    struct apply<insert, Map, Hint, Element>
        : apply<insert, Map, Element>
    { };

    template <template <typename ...> class Map, typename ...Elements,
              typename Element>
    struct apply<insert, Map<Elements...>, Element> {
        using type = Map<Element, Elements...>;
    };

    template <typename Map, typename Position>
    struct apply<erase, Map, Position>
        : erase_key<Map,
            typename key<Map,
                typename deref<Position>::type
            >::type
        >
    { };

private:
    template <typename KeyToErase>
    struct erase_helper {
        template <typename Map, typename Element>
        struct apply
            : if_<is_same<typename key<Map, Element>::type, KeyToErase>,
                Map,
                eval<insert<Map, Element>>
            >
        { };
    };

public:
    template <template <typename ...> class Map, typename ...Elements,
              typename Key>
    struct apply<erase_key, Map<Elements...>, Key>
        : fold<Map<Elements...>, Map<>, erase_helper<Key>>
    { };

    template <template <typename ...> class Map,
              typename State, typename BinaryOp>
    struct apply<fold, Map<>, State, BinaryOp> {
        using type = State;
    };

    template <template <typename ...> class Map,
              typename Head, typename ...Tail,
              typename State, typename BinaryOp>
    struct apply<fold, Map<Head, Tail...>, State, BinaryOp>
        : fold<
            Map<Tail...>,
            typename mpl11::apply<BinaryOp, State, Head>::type,
            BinaryOp
        >
    { };
};
} // end namespace map_detail

template <typename ...Elements>
struct map {
    struct mpl11 { using dispatcher = map_detail::map_implementation; };
    using type = map;
};
}}}

#endif // !BOOST_MPL11_CONTAINER_MAP_HPP
