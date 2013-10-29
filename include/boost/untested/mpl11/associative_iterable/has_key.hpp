/*!
 * @file
 * Defines `boost::mpl11::AssociativeIterable::has_key`.
 */

#ifndef BOOST_MPL11_ASSOCIATIVE_ITERABLE_HAS_KEY_HPP
#define BOOST_MPL11_ASSOCIATIVE_ITERABLE_HAS_KEY_HPP

#include <boost/mpl11/associative_iterable/associative_iterable.hpp>
#include <boost/mpl11/detail/not_implemented.hpp>


namespace boost { namespace mpl11 {
    template <typename I, typename Key>
    struct AssociativeIterable::has_key
        : detail::not_implemented<has_key<I, Key>>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ASSOCIATIVE_ITERABLE_HAS_KEY_HPP
