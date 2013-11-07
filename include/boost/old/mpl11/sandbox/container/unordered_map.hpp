/*!
 * @file
 * Defines `boost::mpl11::container::unordered_map`.
 */

#ifndef BOOST_MPL11_CONTAINER_UNORDERED_MAP_HPP
#define BOOST_MPL11_CONTAINER_UNORDERED_MAP_HPP

#include <boost/mpl11/fwd/unordered_map.hpp>


namespace boost { namespace mpl11 {
//////////////////////////////////////////////////////////////////////////////
// Implementation of the iterator
//////////////////////////////////////////////////////////////////////////////
namespace unordered_map_detail {
    template <typename Map>
    struct end_iterator {
    protected:
        template <typename K>
        struct has_key
            : identity<false_>
        { };

        template <typename K, typename Def>
        struct at
            : identity<Def>
        { };
    };

    template <typename Map, typename Key, typename Value, typename Next>
    struct iterator {
    protected:
        template <typename K, bool = equal_to<K, Key>::type::value>
        struct has_key
            : Next::template has_key<K>
        { };

        template <typename K>
        struct has_key<K, true>
            : identity<true_>
        { };

        template <typename K, typename Def,
                  bool = equal_to<K, Key>::type::value>
        struct at
            : Next::template at<K, Def>
        { };

        template <typename K, typename Def>
        struct at<K, Def, true>
            : identity<Value>
        { };
    };
} // end namespace unordered_map_detail

template <typename M, typename K, typename V, typename Next>
struct dispatch<tag::next, unordered_map_detail::iterator<M, K, V, Next>>
    : identity<Next>
{ };

template <typename M, typename Key, typename Value, typename N>
struct dispatch<tag::deref, unordered_map_detail::iterator<M, Key, Value, N>>
    : identity<pair<Key, Value>>
{ };

template <typename M, typename K, typename V, typename N>
struct dispatch<tag::category_of, unordered_map_detail::iterator<M, K, V, N>>
    : identity<category::forward_iterator>
{ };


//////////////////////////////////////////////////////////////////////////////
// Implementation of the container
//////////////////////////////////////////////////////////////////////////////
namespace container {
    /*!
     * Metafunction returning an `unordered_map` containing the elements
     * in the range delimited by [`First`, `Last`).
     */
    template <typename First, typename Last>
    struct unordered_map<First, Last>
        : algorithm::copy<iterator_range<First, Last>, unordered_map<>>
    { };
} // end namespace container


}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_CONTAINER_UNORDERED_MAP_HPP
