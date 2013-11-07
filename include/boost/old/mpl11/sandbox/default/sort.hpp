/*!
 * @file
 * Defines the default implementation of `boost::mpl11::sort`.
 */

#ifndef BOOST_MPL11_DETAIL_DEFAULT_SORT_HPP
#define BOOST_MPL11_DETAIL_DEFAULT_SORT_HPP

#include <boost/mpl11/copy.hpp>
#include <boost/mpl11/sort.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/quote.hpp>
#include <boost/mpl11/clear.hpp>
#include <boost/mpl11/less.hpp>
#include <boost/mpl11/tags.hpp>
#include <boost/mpl11/view/sorted.hpp>


namespace boost { namespace mpl11 {
    template <typename Sequence>
    struct dispatch<detail::default_<tag::sort>, Sequence>
        : sort<Sequence, quote<less>>
    { };

    template <typename Sequence, typename Predicate>
    struct dispatch<detail::default_<tag::sort>, Sequence, Predicate>
        : sort<
            Sequence, Predicate, typename clear<Sequence>::type
        >
    { };

    template <typename Sequence, typename Predicate, typename Destination>
    struct dispatch<detail::default_<tag::sort>, Sequence, Predicate, Destination>
        : copy<
            sorted_view<Sequence, Predicate>, Destination
        >
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_DETAIL_DEFAULT_SORT_HPP
