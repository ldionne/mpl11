/*!
 * @file
 * Defines `boost::mpl11::container::map`.
 */

#ifndef BOOST_MPL11_CONTAINER_MAP_HPP
#define BOOST_MPL11_CONTAINER_MAP_HPP

#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/categories.hpp>
#include <boost/mpl11/detail/doxygen_only.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/intrinsic/first.hpp>
#include <boost/mpl11/intrinsic/insert_range.hpp>
#include <boost/mpl11/intrinsic/second.hpp>
#include <boost/mpl11/tags.hpp>
#include <boost/mpl11/view/bounded_by.hpp>


namespace boost { namespace mpl11 {
namespace map_detail {
    template <typename ...Elements>
    struct basic_map;

    template <>
    struct basic_map<> {
        template <typename Default, typename Key>
        static auto at(identity<Key>) -> identity<Default>;

        template <typename Key>
        static auto has_key(identity<Key>) -> identity<false_>;
    };

    template <typename Pair, typename ...Elements>
    struct basic_map<Pair, Elements...> : basic_map<Elements...> {
        using Key = typename intrinsic::first<Pair>::type;

        using basic_map<Elements...>::at;
        template <typename Default>
        static auto at(identity<Key>) -> intrinsic::second<Pair>;

        using basic_map<Elements...>::has_key;
        static auto has_key(identity<Key>) -> identity<true_>;
    };

    template <typename ...Elements>
    struct map_iterator;
} // end namespace map_detail

template <typename Pair, typename ...Elements>
struct dispatch<tag::deref, map_detail::map_iterator<Pair, Elements...>>
    : identity<Pair>
{ };

template <typename Pair, typename ...Elements>
struct dispatch<tag::next, map_detail::map_iterator<Pair, Elements...>>
    : identity<map_detail::map_iterator<Elements...>>
{ };

template <typename ...Elements>
struct dispatch<tag::category_of, map_detail::map_iterator<Elements...>>
    : identity<category::forward_iterator>
{ };

namespace container {
    /*!
     * @ingroup container
     */
    template <typename ...Elements>
    struct map BOOST_MPL11_DOXYGEN_ONLY({ });

    /*!
     * Metafunction returning a `map` containing the elements in the range
     * delimited by [`First`, `Last`).
     */
    template <typename First, typename Last>
    struct map<First, Last>
        : intrinsic::insert_range<map<>, view::bounded_by<First, Last>>
    { };
} // end namespace container

template <typename ...Elements>
struct dispatch<tag::category_of, container::map<Elements...>>
    : identity<category::associative_sequence>
{ };

// ForwardSequence
template <typename ...Elements>
struct dispatch<tag::begin, container::map<Elements...>>
    : identity<map_detail::map_iterator<Elements...>>
{ };

template <typename ...Elements>
struct dispatch<tag::end, container::map<Elements...>>
    : identity<map_detail::map_iterator<>>
{ };

template <typename ...Elements>
struct dispatch<tag::size, container::map<Elements...>>
    : identity<ulong<sizeof...(Elements)>>
{ };

template <typename ...Elements>
struct dispatch<tag::is_empty, container::map<Elements...>>
    : identity<bool_<sizeof...(Elements) == 0>>
{ };


// AssociativeSequence
template <typename ...Elements, typename Key, typename Default>
struct dispatch<tag::at, container::map<Elements...>, Key, Default>
    : decltype(
        map_detail::basic_map<Elements...>::
            template at<Default>(identity<Key>{})
    )
{ };

template <typename ...Elements, typename Key>
struct dispatch<tag::has_key, container::map<Elements...>, Key>
    : decltype(
        map_detail::basic_map<Elements...>::has_key(identity<Key>{})
    )
{ };

template <typename ...Elements, typename Pair>
struct dispatch<tag::key_of, container::map<Elements...>, Pair>
    : intrinsic::first<Pair>
{ };

template <typename ...Elements, typename Pair>
struct dispatch<tag::value_of, container::map<Elements...>, Pair>
    : intrinsic::second<Pair>
{ };


// ExtensibleAssociativeSequence
template <typename ...Elements, typename Pair>
struct dispatch<tag::insert, container::map<Elements...>, Pair>
    : identity<
        container::map<Pair, Elements...>
    >
{ };

template <typename ...Elements>
struct dispatch<tag::clear, container::map<Elements...>>
    : identity<container::map<>>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_CONTAINER_MAP_HPP
