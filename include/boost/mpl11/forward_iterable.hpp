/*!
 * @file
 * Defines `boost::mpl11::ForwardIterable`.
 */

#ifndef BOOST_MPL11_FORWARD_ITERABLE_HPP
#define BOOST_MPL11_FORWARD_ITERABLE_HPP

#include <boost/mpl11/fwd/forward_iterable.hpp>

#include <boost/mpl11/begin.hpp>
#include <boost/mpl11/comparable.hpp>
#include <boost/mpl11/deref.hpp>
#include <boost/mpl11/detail/lexicographical_compare.hpp>
#include <boost/mpl11/detail/std_equal.hpp>
#include <boost/mpl11/is_empty.hpp>
#include <boost/mpl11/iterable.hpp>
#include <boost/mpl11/orderable.hpp>


namespace boost { namespace mpl11 {
    struct ForwardIterable : Iterable, Comparable, Orderable {
        /*!
         * Returns `mpl11::deref<mpl11::begin<I>::type>::type` if
         * `is_empty<I>::value` is `false`, and triggers a static
         * assertion otherwise.
         */
        template <typename I>
        struct front_impl {
            static_assert(!is_empty<I>::value,
            "Attempt to use `front` on an empty iterable.");

            using type = typename deref<typename begin<I>::type>::type;
        };

        //! Performs an element-wise comparison of the two iterables.
        template <typename I1, typename I2>
        struct equal_impl
            : detail::std_equal<
                typename begin<I1>::type, typename end<I1>::type,
                typename begin<I2>::type, typename end<I2>::type
            >
        { };

        //! Performs a lexicographical comparison of the two iterables.
        template <typename I1, typename I2>
        struct less_impl
            : detail::lexicographical_compare<
                typename begin<I1>::type, typename end<I1>::type,
                typename begin<I2>::type, typename end<I2>::type
            >
        { };
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FORWARD_ITERABLE_HPP
