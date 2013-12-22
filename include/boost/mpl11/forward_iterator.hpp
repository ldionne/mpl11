/*!
 * @file
 * Defines `boost::mpl11::ForwardIterator`.
 */

#ifndef BOOST_MPL11_FORWARD_ITERATOR_HPP
#define BOOST_MPL11_FORWARD_ITERATOR_HPP

#include <boost/mpl11/fwd/forward_iterator.hpp>

#include <boost/mpl11/comparable.hpp> // Required by fwd/forward_iterator.hpp
#include <boost/mpl11/detail/move.hpp>
#include <boost/mpl11/detail/std_size_t.hpp>
#include <boost/mpl11/equal.hpp>
#include <boost/mpl11/integral_c.hpp>
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

    namespace forward_iterator_detail {
        template <
            typename First, typename Last, detail::std_size_t Dist,
            bool Done = equal<First, Last>::value>
        struct count_between;

        template <typename First, typename Last, detail::std_size_t Dist>
        struct count_between<First, Last, Dist, true>
            : integral_c<decltype(Dist), Dist>
        { };

        template <typename First, typename Last, detail::std_size_t Dist>
        struct count_between<First, Last, Dist, false>
            : count_between<next_t<First>, Last, Dist + 1>
        { };
    } // end namespace forward_iterator_detail

    template <typename First, typename Last>
    struct ForwardIterator::distance_impl
        : forward_iterator_detail::count_between<First, Last, 0>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FORWARD_ITERATOR_HPP
