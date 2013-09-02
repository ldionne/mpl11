/*!
 * @file
 * Defines `boost::mpl11::algorithm::advance`.
 */

#ifndef BOOST_MPL11_ALGORITHM_ADVANCE_HPP
#define BOOST_MPL11_ALGORITHM_ADVANCE_HPP

#include <boost/mpl11/categories.hpp>
#include <boost/mpl11/detail/best_category_for.hpp>
#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/intrinsic/next.hpp>
#include <boost/mpl11/intrinsic/prior.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
namespace algorithm {
    /*!
     * @ingroup algorithm
     *
     * Moves `Iterator` by the distance `N`.
     *
     * For `RandomAccessIterator`s and `BidirecitonalIterator`s, the distance
     * may be negative. For `ForwardIterator`s, it may not.
     *
     *
     * ### Semantics and default implementation
     *
     * For `ForwardIterator`s, equivalent to using `next` until the requested
     * distance has been traversed.
     *
     * For `RandomAccessIterator`s and `BidirecitonalIterator`s, equivalent
     * to using either `next` or `prior` in the same way as for
     * `ForwardIterator`s, depending on the sign of the distance.
     */
    template <typename Iterator, typename N>
    struct advance
        : detail::tag_dispatched<tag::advance, Iterator, N>
    { };

    //! Convenience alias to `advance<Iterator, long_<N>>`.
    template <typename Iterator, long N>
    using advance_c = advance<Iterator, long_<N>>;
} // end namespace algorithm

namespace advance_detail {
    template <template <typename ...> class Next,
              template <typename ...> class Prior>
    struct move {
        template <typename Iterator, typename N, bool = N::value == 0>
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
        static_assert(N::value >= 0,
        "The distance argument to `advance` may not be negative "
        "for forward iterators.");

        // We can't derive from `move<>::apply<>`, because we want the
        // static_assert to be instantiated before the invalid metafunction
        // if `N::value` is negative.
        using type = typename move<intrinsic::next, intrinsic::prior>::
                     template apply<Iterator, N>::type;
    };

    template <typename Iterator, typename N, bool = N::value < 0>
    struct advance_bidirectional
        : move<intrinsic::prior, intrinsic::next>::template apply<Iterator, N>
    { };

    template <typename Iterator, typename N /* >= 0 */>
    struct advance_bidirectional<Iterator, N, false>
        : move<intrinsic::next, intrinsic::prior>::template apply<Iterator, N>
    { };

    template <typename Iterator, typename N>
    struct advance_impl<category::bidirectional_iterator, Iterator, N>
        : advance_bidirectional<Iterator, N>
    { };
} // end namespace advance_detail

template <typename Iterator, typename N>
struct dispatch<detail::default_<tag::advance>, Iterator, N>
    : advance_detail::advance_impl<
        typename detail::best_category_for<Iterator,
            category::bidirectional_iterator,
            category::forward_iterator
        >::type,
        Iterator, N
    >
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ALGORITHM_ADVANCE_HPP
