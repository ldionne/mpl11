/*!
 * @file
 * Defines `boost::mpl11::indexed_view`.
 */

#ifndef BOOST_MPL11_INDEXED_VIEW_HPP
#define BOOST_MPL11_INDEXED_VIEW_HPP

#include <boost/mpl11/fwd/indexed_view.hpp>
#include <boost/mpl11/quote.hpp>    // for the default parameters
#include <boost/mpl11/identity.hpp> // of the view

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/categories.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/fwd/begin.hpp>
#include <boost/mpl11/fwd/category_of.hpp>
#include <boost/mpl11/fwd/end.hpp>
#include <boost/mpl11/fwd/key_of.hpp>
#include <boost/mpl11/fwd/value_of.hpp>


namespace boost { namespace mpl11 {
    template <typename Sequence, typename Key, typename Value>
    struct dispatch<tag::begin, indexed_view<Sequence, Key, Value>>
        : begin<Sequence>
    { };

    template <typename Sequence, typename Key, typename Value>
    struct dispatch<tag::end, indexed_view<Sequence, Key, Value>>
        : end<Sequence>
    { };

    template <typename Sequence, typename Key, typename Value>
    struct dispatch<tag::category_of, indexed_view<Sequence, Key, Value>>
        : identity<
            category::associative_sequence
        >
    { };

    template <typename S, typename Key, typename Value, typename Element>
    struct dispatch<tag::value_of, indexed_view<S, Key, Value>, Element>
        : apply<Value, Element>
    { };

    template <typename S, typename Key, typename Value, typename Element>
    struct dispatch<tag::key_of, indexed_view<S, Key, Value>, Element>
        : apply<Key, Element>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INDEXED_VIEW_HPP
