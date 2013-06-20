/*!
 * @file
 * This file defines the `boost::mpl11::detail::O1_lookup` helper.
 */

#ifndef BOOST_MPL11_DETAIL_O1_LOOKUP_HPP
#define BOOST_MPL11_DETAIL_O1_LOOKUP_HPP

#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/intrinsic/key.hpp>
#include <boost/mpl11/intrinsic/value.hpp>


namespace boost { namespace mpl11 { inline namespace v2 { namespace detail {
namespace O1_lookup_detail {
    // This is a wrapper to allow us to work with incomplete types.
    template <typename T>
    struct wrap { using type = T; };

    template <typename Wrapped>
    struct unwrap : Wrapped { };

    template <typename Map, typename ...Elements>
    struct lookup_cell;

    template <typename Map, typename Element, typename ...Rest>
    struct lookup_cell<Map, Element, Rest...> : lookup_cell<Map, Rest...> {
        using Key = typename key<Map, Element>::type;
        using Value = typename value<Map, Element>::type;

        using lookup_cell<Map, Rest...>::has_key;
        static true_ has_key(wrap<Key>);

        using lookup_cell<Map, Rest...>::at;
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
}

template <typename Map, typename ...Elements>
struct O1_lookup {
    template <typename Key>
    struct has_key {
        using type = decltype(
            O1_lookup_detail::lookup_cell<Map, Elements...>::has_key(
                O1_lookup_detail::wrap<Key>{}
            )
        );
    };

    template <typename Key, typename Default>
    struct at {
        using type = typename O1_lookup_detail::unwrap<
            decltype(
                O1_lookup_detail::lookup_cell<Map, Elements...>::at(
                    O1_lookup_detail::wrap<Key>{},
                    O1_lookup_detail::wrap<Default>{}
                )
            )
        >::type;
    };
};
}}}}

#endif // !BOOST_MPL11_DETAIL_O1_LOOKUP_HPP
