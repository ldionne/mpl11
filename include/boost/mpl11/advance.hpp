/*!
 * @file
 * Defines `boost::mpl11::advance`.
 */

#ifndef BOOST_MPL11_ADVANCE_HPP
#define BOOST_MPL11_ADVANCE_HPP

#include <boost/mpl11/arg.hpp>
#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/if.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/next.hpp>
#include <boost/mpl11/prior.hpp>
#include <boost/mpl11/traversal_categories.hpp>
#include <boost/mpl11/traversal_category_of.hpp>


namespace boost { namespace mpl11 {
namespace advance_detail {
    template <typename Iterator, typename N, bool = N::type::value == 0>
    struct advance_forward
        : advance_forward<
            typename next<Iterator>::type, typename prior<N>::type
        >
    { };

    template <typename Iterator, typename N>
    struct advance_forward<Iterator, N, true>
        : identity<Iterator>
    { };

    template <typename Iterator, typename N, bool = N::type::value == 0>
    struct advance_backward
        : advance_backward<
            typename prior<Iterator>::type, typename next<N>::type
        >
    { };

    template <typename Iterator, typename N>
    struct advance_backward<Iterator, N, true>
        : identity<Iterator>
    { };

    template <typename Category, typename Iterator, typename N>
    struct advance_impl {
        static_assert(detail::always_false<Category, Iterator, N>::value,
        "Attempt to use the default implementation of `advance` with an "
        "iterator whose traversal category is unknown.");

        struct type;
    };

    template <typename Iterator, typename N>
    struct advance_impl<tag::forward, Iterator, N> {
        static_assert(N::type::value >= 0,
        "The distance argument to `advance` may not be negative "
        "for forward iterators.");

        // We can't derive from `advance_forward`, because we want the
        // static_assert to be instantiated before the invalid metafunction
        // if `N::type::value` is negative.
        using type = typename advance_forward<Iterator, N>::type;
    };

    template <typename Iterator, typename N>
    struct advance_impl<tag::bidirectional, Iterator, N>
        : if_c<N::type::value < 0,
            advance_backward<Iterator, N>,
            advance_forward<Iterator, N>
        >::type
    { };

    template <typename Iterator, typename N>
    struct advance_impl<tag::random_access, Iterator, N>
        : advance_impl<tag::bidirectional, Iterator, N>
    { };
} // end namespace advance_detail

namespace tag { struct advance; }

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
        advance_detail::advance_impl<traversal_category_of<_2>, _2, _3>
    >
{ };

//! Convenience alias to `advance<Iterator, long_<N>>`.
template <typename Iterator, long N>
using advance_c = advance<Iterator, long_<N>>;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ADVANCE_HPP
