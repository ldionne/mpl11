/*!
 * @file
 * Defines the default implementation of `boost::mpl11::algorithm::sort`.
 */

#ifndef BOOST_MPL11_DETAIL_DEFAULT_SORT_HPP
#define BOOST_MPL11_DETAIL_DEFAULT_SORT_HPP

#include <boost/mpl11/algorithm/copy.hpp>
#include <boost/mpl11/algorithm/sort.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/functional/quote.hpp>
#include <boost/mpl11/intrinsic/clear.hpp>
#include <boost/mpl11/operator/less.hpp>
#include <boost/mpl11/tags.hpp>
#include <boost/mpl11/view/sorted.hpp>


namespace boost { namespace mpl11 {
    template <typename Sequence>
    struct dispatch<detail::default_<tag::sort>, Sequence>
        : algorithm::sort<Sequence, quote<less>>
    { };

    template <typename Sequence, typename Predicate>
    struct dispatch<detail::default_<tag::sort>, Sequence, Predicate>
        : algorithm::sort<
            Sequence, Predicate, typename clear<Sequence>::type
        >
    { };

    template <typename Sequence, typename Predicate, typename Destination>
    struct dispatch<detail::default_<tag::sort>, Sequence, Predicate, Destination>
        : algorithm::copy<
            view::sorted<Sequence, Predicate>, Destination
        >
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_DETAIL_DEFAULT_SORT_HPP
