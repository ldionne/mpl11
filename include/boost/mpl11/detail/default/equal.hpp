/*!
 * @file
 * Defines the default implementation of `boost::mpl11::algorithm::equal`.
 */

#ifndef BOOST_MPL11_DETAIL_DEFAULT_EQUAL_HPP
#define BOOST_MPL11_DETAIL_DEFAULT_EQUAL_HPP

#include <boost/mpl11/algorithm/all_of.hpp>
#include <boost/mpl11/algorithm/equal.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/intrinsic/and.hpp>
#include <boost/mpl11/intrinsic/equal_to.hpp>
#include <boost/mpl11/intrinsic/size.hpp>
#include <boost/mpl11/quote.hpp>
#include <boost/mpl11/tags.hpp>
#include <boost/mpl11/unpack_args.hpp>
#include <boost/mpl11/view/zipped.hpp>


namespace boost { namespace mpl11 {
template <typename Sequence1, typename Sequence2>
struct dispatch<detail::default_<tag::equal>, Sequence1, Sequence2>
    : algorithm::equal<Sequence1, Sequence2, quote<intrinsic::equal_to>>
{ };

template <typename Sequence1, typename Sequence2, typename Predicate>
struct dispatch<detail::default_<tag::equal>, Sequence1, Sequence2, Predicate>
    : intrinsic::and_<
        intrinsic::equal_to<
            typename intrinsic::size<Sequence1>::type,
            typename intrinsic::size<Sequence2>::type
        >,
        algorithm::all_of<
            view::zipped<Sequence1, Sequence2>,
            unpack_args<Predicate>
        >
    >
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_DETAIL_DEFAULT_EQUAL_HPP
