/*!
 * @file
 * Defines `boost::mpl11::AssociativeIterable::key_of`.
 */

#ifndef BOOST_MPL11_ASSOCIATIVE_ITERABLE_KEY_OF_HPP
#define BOOST_MPL11_ASSOCIATIVE_ITERABLE_KEY_OF_HPP

#include <boost/mpl11/associative_iterable/associative_iterable.hpp>
#include <boost/mpl11/detail/not_implemented.hpp>


namespace boost { namespace mpl11 {
    template <typename I, typename Element>
    struct AssociativeIterable::key_of
        : detail::not_implemented<key_of<I, Element>>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ASSOCIATIVE_ITERABLE_KEY_OF_HPP
