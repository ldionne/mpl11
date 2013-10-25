/*!
 * @file
 * Defines `boost::mpl11::OrderedAssociativeIterable`.
 */

#ifndef BOOST_MPL11_ORDERED_ASSOCIATIVE_ITERABLE_ORDERED_ASSOCIATIVE_ITERABLE_HPP
#define BOOST_MPL11_ORDERED_ASSOCIATIVE_ITERABLE_ORDERED_ASSOCIATIVE_ITERABLE_HPP

#include <boost/mpl11/fwd/ordered_associative_iterable.hpp>

#include <boost/mpl11/associative_iterable/associative_iterable.hpp>


namespace boost { namespace mpl11 {
    // Order _is_ meaningful, in the sense that elements are ordered in
    // the sequence according to some relation.
    struct OrderedAssociativeIterable : AssociativeIterable, Orderable {
        // Compare element by element: they are ordered.
        template <typename I1, typename I2>
        struct equal_to;

        // Compare lexicographically.
        template <typename I1, typename I2>
        struct less;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ORDERED_ASSOCIATIVE_ITERABLE_ORDERED_ASSOCIATIVE_ITERABLE_HPP
