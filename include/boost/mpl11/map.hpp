/*!
 * @file
 * This file defines the `boost::mpl11::map` container.
 */

#ifndef BOOST_MPL11_MAP_HPP
#define BOOST_MPL11_MAP_HPP

#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/size_t.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
template <typename Map>
class map_implementation;

template <template <typename ...> class MapTemplate, typename ...Pairs>
class map_implementation<MapTemplate<Pairs...>> {
    using Map = MapTemplate<Pairs...>;
    using KeyValues = map_detail::key_value_base<Pairs...>;

    template <typename Pos> class iterator;
    template <typename S, S pos>
    class iterator<integral_c<S, pos> > {
        using deref = at<Position, Map>;
        using next = iterator<integral_c<S, pos + 1> >;
        using prior = iterator<integral_c<S, pos - 1> >;
    };

    using size = size_t<sizeof...(Pairs)>;
    using begin = iterator<size_t<0> >;
    using end = iterator<size>;
    using empty = bool_<size::value == 0>;
    using clear = MapTemplate<>;

    // at
    template <typename Key, typename Default = fail>
    using at = typename KeyValues::template at<Key, Default>;

    // has_key
    template <typename Key>
    using has_key = typename KeyValues::template has_key<Key>;
};
}}}

#endif // !BOOST_MPL11_MAP_HPP
