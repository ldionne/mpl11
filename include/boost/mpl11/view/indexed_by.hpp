/*!
 * @file
 * Defines `boost::mpl11::view::indexed_by`.
 */

#ifndef BOOST_MPL11_VIEW_INDEXED_BY_HPP
#define BOOST_MPL11_VIEW_INDEXED_BY_HPP

#include <boost/mpl11/functional/quote.hpp> // for the default parameters
#include <boost/mpl11/identity.hpp>         // of the view

#include <boost/mpl11/categories.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/functional/apply.hpp>
#include <boost/mpl11/intrinsic/begin_fwd.hpp>
#include <boost/mpl11/intrinsic/category_of_fwd.hpp>
#include <boost/mpl11/intrinsic/end_fwd.hpp>
#include <boost/mpl11/intrinsic/key_of_fwd.hpp>
#include <boost/mpl11/intrinsic/value_of_fwd.hpp>


namespace boost { namespace mpl11 {
    template <typename Sequence, typename Key, typename Value>
    struct dispatch<tag::begin, view::indexed_by<Sequence, Key, Value>>
        : begin<Sequence>
    { };

    template <typename Sequence, typename Key, typename Value>
    struct dispatch<tag::end, view::indexed_by<Sequence, Key, Value>>
        : end<Sequence>
    { };

    template <typename Sequence, typename Key, typename Value>
    struct dispatch<tag::category_of, view::indexed_by<Sequence, Key, Value>>
        : identity<
            category::associative_sequence
        >
    { };

    template <typename S, typename Key, typename Value, typename Element>
    struct dispatch<tag::value_of, view::indexed_by<S, Key, Value>, Element>
        : apply<Value, Element>
    { };

    template <typename S, typename Key, typename Value, typename Element>
    struct dispatch<tag::key_of, view::indexed_by<S, Key, Value>, Element>
        : apply<Key, Element>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_VIEW_INDEXED_BY_HPP
