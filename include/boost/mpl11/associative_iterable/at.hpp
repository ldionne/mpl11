/*!
 * @file
 * Defines `boost::mpl11::AssociativeIterable::at`.
 */

#ifndef BOOST_MPL11_ASSOCIATIVE_ITERABLE_AT_HPP
#define BOOST_MPL11_ASSOCIATIVE_ITERABLE_AT_HPP

#include <boost/mpl11/associative_iterable/associative_iterable.hpp>
#include <boost/mpl11/at.hpp>
#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/detail/not_implemented.hpp>


namespace boost { namespace mpl11 {
    template <typename I, typename Key, typename Default>
    struct AssociativeIterable::at
        : detail::not_implemented<at<I, Key, Default>>
    { };

    namespace assoc_detail { struct not_found; }

    template <typename I, typename Key>
    struct AssociativeIterable::at<I, Key>
        : mpl11::at<I, Key, assoc_detail::not_found>
    {
        static_assert(!detail::is_same<
                        typename at::type, assoc_detail::not_found
                      >::type::value,
        "Could not find the value associated to a given key in an "
        "associative iterable and no default return value was specified.");
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ASSOCIATIVE_ITERABLE_AT_HPP
