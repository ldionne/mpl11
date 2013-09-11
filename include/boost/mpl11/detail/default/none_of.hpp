/*!
 * @file
 * Defines the default implementation of `boost::mpl11::algorithm::none_of`.
 */

#ifndef BOOST_MPL11_DETAIL_DEFAULT_NONE_OF_HPP
#define BOOST_MPL11_DETAIL_DEFAULT_NONE_OF_HPP

#include <boost/mpl11/algorithm/find_if.hpp>
#include <boost/mpl11/algorithm/none_of.hpp>
#include <boost/mpl11/arg.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/intrinsic/end.hpp>
#include <boost/mpl11/operator/equal_to.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
template <typename Sequence>
struct dispatch<detail::default_<tag::none_of>, Sequence>
    : algorithm::none_of<Sequence, _1>
{ };

template <typename Sequence, typename Predicate>
struct dispatch<detail::default_<tag::none_of>, Sequence, Predicate>
    : equal_to<
        typename algorithm::find_if<Sequence, Predicate>::type,
        typename intrinsic::end<Sequence>::type
    >
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_DETAIL_DEFAULT_NONE_OF_HPP
