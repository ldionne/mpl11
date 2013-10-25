/*!
 * @file
 * Defines `boost::mpl11::Iterable`.
 */

#ifndef BOOST_MPL11_ITERABLE_ITERABLE_HPP
#define BOOST_MPL11_ITERABLE_ITERABLE_HPP

#include <boost/mpl11/fwd/iterable.hpp>


namespace boost { namespace mpl11 {
    // Anything that can be traversed. The order of traversal is not meaningful.
    struct Iterable {
        template <typename I>
        struct begin;

        template <typename I>
        struct end;

        template <typename I>
        struct size;

        template <typename I>
        struct is_empty;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ITERABLE_ITERABLE_HPP
