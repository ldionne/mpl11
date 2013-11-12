/*!
 * @file
 * Defines `boost::mpl11::ForwardIterator`.
 */

#ifndef BOOST_MPL11_FORWARD_ITERATOR_HPP
#define BOOST_MPL11_FORWARD_ITERATOR_HPP

#include <boost/mpl11/fwd/forward_iterator.hpp>

// Required by fwd/forward_iterator.hpp
#include <boost/mpl11/comparable.hpp>
#include <boost/mpl11/equal.hpp>
#include <boost/mpl11/integral_c.hpp>

#include <boost/mpl11/detail/move.hpp>
#include <boost/mpl11/next.hpp>


namespace boost { namespace mpl11 {
    template <typename Iterator, typename N>
    struct ForwardIterator::advance_impl {
        static_assert(N::value >= 0,
        "The distance argument to `advance` may not be negative "
        "for forward iterators.");

        // We can't inherit from `detail::move` because we want the
        // `static_assert` to be triggered before the metafunction is
        // evaluated if `N` is negative.
        using type = typename detail::move<next, Iterator, N::value>::type;
    };

    template <typename First, typename Last, typename Distance, bool Done>
    struct ForwardIterator::distance_impl
        : Distance
    { };

    template <typename First, typename Last, typename Distance>
    struct ForwardIterator::distance_impl<First, Last, Distance, false>
        : distance_impl<
            typename next<First>::type, Last, size_t<Distance::value + 1>
        >
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FORWARD_ITERATOR_HPP
