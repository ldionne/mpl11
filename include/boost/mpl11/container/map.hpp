/*!
 * @file
 * This file defines the `boost::mpl11::map` container.
 */

#ifndef BOOST_MPL11_CONTAINER_MAP_HPP
#define BOOST_MPL11_CONTAINER_MAP_HPP

#include <boost/mpl11/algorithm/foldl.hpp>
#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/functional/apply.hpp>
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
#include <boost/mpl11/is_same.hpp>
#include <boost/mpl11/size_t.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
template <typename ...Elements>
class map {
    using lookup_begin = map_detail::lookup_cell<map, Elements...>;
    using lookup_end = map_detail::lookup_cell<map>;
    template <typename T> using wrap = map_detail::wrap<T>;
    template <typename T> using unwrap = map_detail::unwrap<T>;

    template <typename Cell>
    class iterator {
        struct implementation {
            template <typename Intrinsic, typename ...Args>
            struct apply;

            template <typename ...Ignore>
            struct apply<intrinsic::next, Ignore...> {
                using type = iterator<typename Cell::next_cell>;
            };

            template <typename ...Ignore>
            struct apply<intrinsic::deref, Ignore...> {
                using type = typename Cell::this_element;
            };
        };

    public:
        struct mpl11 { using dispatcher = implementation; };
    };

    struct implementation {
        template <typename Operation, typename ...Args>
        struct apply;

        template <typename Hint, typename Element>
        struct apply<intrinsic::insert, Hint, Element>
            : apply<intrinsic::insert, Element>
        { };

        template <typename Element>
        struct apply<intrinsic::insert, Element> {
            using type = map<Element, Elements...>;
        };

        template <typename Position>
        struct apply<intrinsic::erase, Position>
            : erase_key<map,
                typename key<map,
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
        template <typename Key>
        struct apply<intrinsic::erase_key, Key>
            : foldl<map, map<>, erase_helper<Key>>
        { };

    private:
        template <typename Map, typename State, typename BinaryOp>
        struct foldl_impl;

        template <template <typename ...> class Map,
                  typename State, typename BinaryOp>
        struct foldl_impl<Map<>, State, BinaryOp> {
            using type = State;
        };

        template <template <typename ...> class Map,
                  typename Head, typename ...Tail,
                  typename State, typename BinaryOp>
        struct foldl_impl<Map<Head, Tail...>, State, BinaryOp>
            : foldl_impl<
                Map<Tail...>,
                typename mpl11::apply<BinaryOp, State, Head>::type,
                BinaryOp
            >
        { };

    public:
        template <typename State, typename BinaryOp>
        struct apply<algorithm::foldl, State, BinaryOp>
            : foldl_impl<map, State, BinaryOp>
        { };
    };

public:
    struct mpl11 { using dispatcher = implementation; };
    using type = map;
};
}}}

#endif // !BOOST_MPL11_CONTAINER_MAP_HPP
