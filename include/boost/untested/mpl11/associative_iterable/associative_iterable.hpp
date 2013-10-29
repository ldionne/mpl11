/*!
 * @file
 * Defines `boost::mpl11::AssociativeIterable`.
 */

#ifndef BOOST_MPL11_ASSOCIATIVE_ITERABLE_ASSOCIATIVE_ITERABLE_HPP
#define BOOST_MPL11_ASSOCIATIVE_ITERABLE_ASSOCIATIVE_ITERABLE_HPP

#include <boost/mpl11/fwd/associative_iterable.hpp>

#include <boost/mpl11/comparable/comparable.hpp>
#include <boost/mpl11/detail/optional.hpp>
#include <boost/mpl11/iterable/iterable.hpp>


namespace boost { namespace mpl11 {
    // Order is not meaningful. Each element is comprised of a key and a value,
    // which can both be retrieved from the element and the iterable.
    struct AssociativeIterable : Iterable, Comparable {
        // - the version without a default is implemented
        // - the version with a default; we should think about it
        template <typename I, typename Key, typename Default = detail::optional>
        struct at;

        template <typename I, typename Key>
        struct has_key;

        template <typename I, typename Element>
        struct key_of;

        template <typename I, typename Element>
        struct value_of;

        template <typename I1, typename I2>
        struct equal_to;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ASSOCIATIVE_ITERABLE_ASSOCIATIVE_ITERABLE_HPP
