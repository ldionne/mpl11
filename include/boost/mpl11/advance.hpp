/*!
 * @file
 * Defines `boost::mpl11::advance`.
 */

#ifndef BOOST_MPL11_ADVANCE_HPP
#define BOOST_MPL11_ADVANCE_HPP

#include <boost/mpl11/fwd/advance.hpp>
#include <boost/mpl11/integral_c.hpp> // for advance_c

#include <boost/mpl11/categories.hpp>
#include <boost/mpl11/detail/best_category_for.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/next.hpp>
#include <boost/mpl11/prior.hpp>


namespace boost { namespace mpl11 {
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
        using type = typename move<next, prior>::
                     template apply<Iterator, N>::type;
    };

    template <typename Iterator, typename N, bool = N::value < 0>
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

template <typename Iterator, typename N>
struct dispatch<tag::default_<tag::advance>, Iterator, N>
    : advance_detail::advance_impl<
        typename detail::best_category_for<Iterator,
            category::bidirectional_iterator,
            category::forward_iterator
        >::type,
        Iterator, N
    >
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ADVANCE_HPP
