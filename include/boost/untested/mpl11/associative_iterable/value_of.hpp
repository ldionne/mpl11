/*!
 * @file
 * Defines `boost::mpl11::AssociativeIterable::value_of`.
 */

#ifndef BOOST_MPL11_ASSOCIATIVE_ITERABLE_VALUE_OF_HPP
#define BOOST_MPL11_ASSOCIATIVE_ITERABLE_VALUE_OF_HPP

#include <boost/mpl11/associative_iterable/associative_iterable.hpp>
#include <boost/mpl11/detail/not_implemented.hpp>


namespace boost { namespace mpl11 {
    template <typename I, typename Element>
    struct AssociativeIterable::value_of
        : detail::not_implemented<value_of<I, Element>>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ASSOCIATIVE_ITERABLE_VALUE_OF_HPP
