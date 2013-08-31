/*!
 * @file
 * Defines `boost::mpl11::advance`.
 */

#ifndef BOOST_MPL11_ADVANCE_HPP
#define BOOST_MPL11_ADVANCE_HPP

#include <boost/mpl11/arg.hpp>
#include <boost/mpl11/categories.hpp>
#include <boost/mpl11/detail/best_category_for.hpp>
#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/next.hpp>
#include <boost/mpl11/prior.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
namespace advance_detail {
    template <template <typename ...> class Next,
              template <typename ...> class Prior>
    struct move {
        template <typename Iterator, typename N, bool = N::type::value == 0>
        struct apply
            : apply<typename Next<Iterator>::type, typename Prior<N>::type>
        { };

        template <typename Iterator, typename N>
        struct apply<Iterator, N, true>
            : identity<Iterator>
        { };
    };

    template <typename Category, typename Iterator, typename N>
    struct advance_impl;

    template <typename Iterator, typename N>
    struct advance_impl<category::forward_iterator, Iterator, N> {
        static_assert(N::type::value >= 0,
        "The distance argument to `advance` may not be negative "
        "for forward iterators.");

        // We can't derive from `move<>::apply<>`, because we want the
        // static_assert to be instantiated before the invalid metafunction
        // if `N::type::value` is negative.
        using type = typename move<next, prior>::
                     template apply<Iterator, N>::type;
    };

    template <typename Iterator, typename N, bool = N::type::value < 0>
    struct advance_bidirectional
        : move<prior, next>::template apply<Iterator, N>
    { };

    template <typename Iterator, typename N /* >= 0 */>
    struct advance_bidirectional<Iterator, N, false>
        : move<next, prior>::template apply<Iterator, N>
    { };

    template <typename Iterator, typename N>
    struct advance_impl<category::bidirectional_iterator, Iterator, N>
        : advance_bidirectional<Iterator, N>
    { };
} // end namespace advance_detail

/*!
 * Moves `Iterator` by the distance `N`.
 *
 * For bidirectional and random access iterators, the distance may be
 * negative. For forward iterators, it may not.
 *
 * The default implementation for forward iterators uses `next` until the
 * requested distance has been traversed.
 *
 * The default implementation for bidirectional and random access iterators
 * uses either `next` or `prior` in the same way as for forward iterators,
 * depending on the sign of the distance.
 */
template <typename Iterator, typename N>
struct advance
    : detail::tag_dispatched<tag::advance, Iterator, N>::template
      with_default<
        advance_detail::advance_impl<
            detail::best_category_for<_1,
                category::bidirectional_iterator,
                category::forward_iterator
            >,
            _1, _2
        >
      >
{ };

//! Convenience alias to `advance<Iterator, long_<N>>`.
template <typename Iterator, long N>
using advance_c = advance<Iterator, long_<N>>;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ADVANCE_HPP
