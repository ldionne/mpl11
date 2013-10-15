/*!
 * @file
 * Defines `boost::mpl11::advance`.
 */

#ifndef BOOST_MPL11_ADVANCE_HPP
#define BOOST_MPL11_ADVANCE_HPP

#include <boost/mpl11/fwd/advance.hpp>
#include <boost/mpl11/integral_c.hpp> // for advance_c

#include <boost/mpl11/apply_wrap.hpp>
#include <boost/mpl11/category/bidirectional_iterator.hpp>
#include <boost/mpl11/category/forward_iterator.hpp>
#include <boost/mpl11/category_of.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/next.hpp>
#include <boost/mpl11/prior.hpp>


namespace boost { namespace mpl11 {
namespace advance_detail {
    template <template <typename ...> class Next,
              typename Iterator, unsigned long N>
    struct advance_impl
        : advance_impl<Next, typename Next<Iterator>::type, N - 1>
    { };

    template <template <typename ...> class Next, typename Iterator>
    struct advance_impl<Next, Iterator, 0>
        : identity<Iterator>
    { };
} // end namespace advance_detail

template <typename Iterator, typename N>
struct dispatch<tag::advance, Iterator, N>
    : apply_wrap<
        dispatch<
            tag::by_category<tag::advance>,
            typename category_of<Iterator>::type
        >,
        Iterator, N
    >
{ };

template <>
struct dispatch<tag::by_category<tag::advance>, category::forward_iterator> {
    template <typename Iterator, typename N>
    struct apply {
        static_assert(N::value >= 0,
        "The distance argument to `advance` may not be negative "
        "for forward iterators.");

        // We can't derive from `advance_impl<>`, because we want
        // the `static_assert` to be instantiated before the invalid
        // metafunction if `N::value` is negative.
        using type = typename advance_detail::advance_impl<
            next, Iterator, N::value
        >::type;
    };
};

template <>
struct dispatch<tag::by_category<tag::advance>,
                category::bidirectional_iterator> {
    template <typename Iterator, typename N, bool = N::value < 0>
    struct apply;

    template <typename Iterator, typename N>
    struct apply<Iterator, N, true>
        : advance_detail::advance_impl<prior, Iterator, -N::value>
    { };

    template <typename Iterator, typename N>
    struct apply<Iterator, N, false>
        : advance_detail::advance_impl<next, Iterator, N::value>
    { };
};
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ADVANCE_HPP
