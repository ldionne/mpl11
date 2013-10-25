/*!
 * @file
 * Defines `boost::mpl11::ForwardIterable`.
 */

#ifndef BOOST_MPL11_FORWARD_ITERABLE_FORWARD_ITERABLE_HPP
#define BOOST_MPL11_FORWARD_ITERABLE_FORWARD_ITERABLE_HPP

#include <boost/mpl11/fwd/forward_iterable.hpp>

#include <boost/mpl11/comparable/comparable.hpp>
#include <boost/mpl11/iterable/iterable.hpp>
#include <boost/mpl11/orderable/orderable.hpp>


namespace boost { namespace mpl11 {
    // Elements are traversed linearly.
    struct ForwardIterable : Iterable, Comparable, Orderable {
        template <typename I>
        struct front;

        // Side-by-side comparison of the elements.
        template <typename I1, typename I2>
        struct equal_to;

        // Lexicographical ordering of the elements.
        template <typename I1, typename I2>
        struct less;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FORWARD_ITERABLE_FORWARD_ITERABLE_HPP
