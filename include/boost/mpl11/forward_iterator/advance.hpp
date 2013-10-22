/*!
 * @file
 * Defines `boost::mpl11::ForwardIterator::advance`.
 */

#ifndef BOOST_MPL11_FORWARD_ITERATOR_ADVANCE_HPP
#define BOOST_MPL11_FORWARD_ITERATOR_ADVANCE_HPP

#include <boost/mpl11/detail/move.hpp>
#include <boost/mpl11/forward_iterator/forward_iterator.hpp>
#include <boost/mpl11/next.hpp>


namespace boost { namespace mpl11 {
    template <typename Iterator, typename N>
    struct ForwardIterator::advance {
        static_assert(N::value >= 0,
        "The distance argument to `advance` may not be negative "
        "for forward iterators.");

        // We can't inherit from `detail::move` because we want the
        // `static_assert` to be triggered before the metafunction is
        // evaluated if `N` is negative.
        using type = typename detail::move<next, Iterator, N::value>::type;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FORWARD_ITERATOR_ADVANCE_HPP
