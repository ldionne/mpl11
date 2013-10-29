/*!
 * @file
 * Defines `boost::mpl11::ForwardIterator`.
 */

#ifndef BOOST_MPL11_FORWARD_ITERATOR_FORWARD_ITERATOR_HPP
#define BOOST_MPL11_FORWARD_ITERATOR_FORWARD_ITERATOR_HPP

#include <boost/mpl11/fwd/forward_iterator.hpp>

#include <boost/mpl11/comparable.hpp>
#include <boost/mpl11/detail/move.hpp>
#include <boost/mpl11/equal.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/next.hpp>


namespace boost { namespace mpl11 {
    struct ForwardIterator : Comparable {
        //! This operation must be provided by the user.
        template <typename Iterator>
        struct next_impl;

        //! This operation must be provided by the user.
        template <typename Iterator>
        struct deref_impl;

        /*!
         * Performs `N::value` applications of `mpl11::next` to `Iterator`.
         *
         *
         * @note
         * A static assertion is triggered if `N::value` is negative.
         */
        template <typename Iterator, typename N>
        struct advance_impl {
            static_assert(N::value >= 0,
            "The distance argument to `advance` may not be negative "
            "for forward iterators.");

            // We can't inherit from `detail::move` because we want the
            // `static_assert` to be triggered before the metafunction is
            // evaluated if `N` is negative.
            using type = typename detail::move<next, Iterator, N::value>::type;
        };

        /*!
         * Counts the number of applications of `mpl11::next` required
         * for `First` to become equal to `Last`.
         *
         *
         * @todo
         * Use size_t to count the distance.
         */
        template <
            typename First, typename Last,
            unsigned long long Dist = 0,
            bool = equal<First, Last>::value
        >
        struct distance_impl {
            using type = integral_c<unsigned long long, Dist>;
        };

        template <typename First, typename Last, unsigned long long Dist>
        struct distance_impl<First, Last, Dist, false>
            : distance_impl<typename next<First>::type, Last, Dist + 1>
        { };
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FORWARD_ITERATOR_FORWARD_ITERATOR_HPP
