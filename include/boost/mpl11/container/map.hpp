/*!
 * @file
 * This file defines the `boost::mpl11::map` container.
 */

#ifndef BOOST_MPL11_CONTAINER_MAP_HPP
#define BOOST_MPL11_CONTAINER_MAP_HPP

#include <boost/mpl11/algorithm/foldl.hpp>
#include <boost/mpl11/container/vector.hpp>
#include <boost/mpl11/detail/O1_lookup.hpp>
#include <boost/mpl11/functional/apply.hpp>
#include <boost/mpl11/if.hpp>
#include <boost/mpl11/intrinsic/at.hpp>
#include <boost/mpl11/intrinsic/clear.hpp>
#include <boost/mpl11/intrinsic/deref.hpp>
#include <boost/mpl11/intrinsic/erase.hpp>
#include <boost/mpl11/intrinsic/erase_key.hpp>
#include <boost/mpl11/intrinsic/first.hpp>
#include <boost/mpl11/intrinsic/has_key.hpp>
#include <boost/mpl11/intrinsic/insert.hpp>
#include <boost/mpl11/intrinsic/key.hpp>
#include <boost/mpl11/intrinsic/second.hpp>
#include <boost/mpl11/intrinsic/value.hpp>
#include <boost/mpl11/is_same.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
template <typename ...Elements>
class map : public vector<Elements...> {
    using lookup = detail::O1_lookup<map, Elements...>;

    struct implementation {
        template <typename Operation, typename ...Args>
        struct apply
            : mpl11::apply<Operation, vector<Elements...>, Args...>
        { };

        template <typename Key>
        struct apply<intrinsic::has_key, Key>
            : lookup::template has_key<Key>
        { };

        struct fail;
        template <typename Key>
        struct apply<intrinsic::at, Key>
            : apply<intrinsic::at, Key, fail>
        { };

        template <typename Key, typename Default>
        struct apply<intrinsic::at, Key, Default>
            : lookup::template at<Key, Default>
        {
            static_assert(!is_same<typename apply::type, fail>::value,
                "the requested key could not be found in the map "
                "and no default return value was specified");
        };

        template <typename Element>
        struct apply<intrinsic::key, Element>
            : first<Element>
        { };

        template <typename Element>
        struct apply<intrinsic::value, Element>
            : second<Element>
        { };

        template <typename ...Ignore>
        struct apply<intrinsic::clear, Ignore...> {
            using type = map<>;
        };

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
    };

public:
    struct mpl11 { using dispatcher = implementation; };
    using type = map;
};
}}}

#endif // !BOOST_MPL11_CONTAINER_MAP_HPP
