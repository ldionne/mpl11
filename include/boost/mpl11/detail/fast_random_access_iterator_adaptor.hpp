/*!
 * @file
 * Defines `boost::mpl11::detail::fast_random_access_iterator_adaptor`.
 */

#ifndef BOOST_MPL11_DETAIL_ADAPTORS_RANDOM_ACCESS_ITERATOR_HPP
#define BOOST_MPL11_DETAIL_ADAPTORS_RANDOM_ACCESS_ITERATOR_HPP

#include <boost/mpl11/detail/fast_random_access_iterator_adaptor_fwd.hpp>

#include <boost/mpl11/fwd/advance.hpp>
#include <boost/mpl11/fwd/deref.hpp>
#include <boost/mpl11/fwd/distance.hpp>
#include <boost/mpl11/fwd/equal.hpp>
#include <boost/mpl11/fwd/greater.hpp>
#include <boost/mpl11/fwd/greater_equal.hpp>
#include <boost/mpl11/fwd/less.hpp>
#include <boost/mpl11/fwd/less_equal.hpp>
#include <boost/mpl11/fwd/next.hpp>
#include <boost/mpl11/fwd/not_equal.hpp>
#include <boost/mpl11/fwd/prev.hpp>


namespace boost { namespace mpl11 {
    // Comparable
    template <typename It1, typename It2, typename Tag>
    struct equal<
        detail::fast_random_access_iterator_adaptor<It1, Tag>,
        detail::fast_random_access_iterator_adaptor<It2, Tag>
    >
        : equal<It1, It2>
    { };

    template <typename It1, typename It2, typename Tag>
    struct not_equal<
        detail::fast_random_access_iterator_adaptor<It1, Tag>,
        detail::fast_random_access_iterator_adaptor<It2, Tag>
    >
        : not_equal<It1, It2>
    { };

    // Orderable
    template <typename It1, typename It2, typename Tag>
    struct less<
        detail::fast_random_access_iterator_adaptor<It1, Tag>,
        detail::fast_random_access_iterator_adaptor<It2, Tag>
    >
        : less<It1, It2>
    { };

    template <typename It1, typename It2, typename Tag>
    struct less_equal<
        detail::fast_random_access_iterator_adaptor<It1, Tag>,
        detail::fast_random_access_iterator_adaptor<It2, Tag>
    >
        : less_equal<It1, It2>
    { };

    template <typename It1, typename It2, typename Tag>
    struct greater<
        detail::fast_random_access_iterator_adaptor<It1, Tag>,
        detail::fast_random_access_iterator_adaptor<It2, Tag>
    >
        : greater<It1, It2>
    { };

    template <typename It1, typename It2, typename Tag>
    struct greater_equal<
        detail::fast_random_access_iterator_adaptor<It1, Tag>,
        detail::fast_random_access_iterator_adaptor<It2, Tag>
    >
        : greater_equal<It1, It2>
    { };

    // ForwardIterator
    template <typename Iterator, typename Tag>
    struct next<detail::fast_random_access_iterator_adaptor<Iterator, Tag>> {
        using type = detail::fast_random_access_iterator_adaptor<
            typename next<Iterator>::type, Tag
        >;
    };

    template <typename Iterator, typename Tag>
    struct deref<detail::fast_random_access_iterator_adaptor<Iterator, Tag>>
        : deref<Iterator>
    { };

    // BidirectionalIterator
    template <typename Iterator, typename Tag>
    struct prev<detail::fast_random_access_iterator_adaptor<Iterator, Tag>> {
        using type = detail::fast_random_access_iterator_adaptor<
            typename prev<Iterator>::type, Tag
        >;
    };

    // RandomAccessIterator
    template <typename Iterator, typename Tag, typename N>
    struct advance<
        detail::fast_random_access_iterator_adaptor<Iterator, Tag>, N
    >
    {
        using type = detail::fast_random_access_iterator_adaptor<
            typename advance<Iterator, N>::type, Tag
        >;
    };

    template <typename It1, typename It2, typename Tag>
    struct distance<
        detail::fast_random_access_iterator_adaptor<It1, Tag>,
        detail::fast_random_access_iterator_adaptor<It2, Tag>
    >
        : distance<It1, It2>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_DETAIL_ADAPTORS_RANDOM_ACCESS_ITERATOR_HPP
