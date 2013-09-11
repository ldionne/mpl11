/*!
 * @file
 * Defines the default implementation of `boost::mpl11::algorithm::all_of`.
 */

#ifndef BOOST_MPL11_DETAIL_DEFAULT_ALL_OF_HPP
#define BOOST_MPL11_DETAIL_DEFAULT_ALL_OF_HPP

#include <boost/mpl11/algorithm/all_of.hpp>
#include <boost/mpl11/algorithm/none_of.hpp>
#include <boost/mpl11/apply_wrap.hpp>
#include <boost/mpl11/arg.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/lambda.hpp>
#include <boost/mpl11/operator/not.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
template <typename Sequence, typename Predicate>
struct dispatch<detail::default_<tag::all_of>, Sequence, Predicate>
    : algorithm::none_of<
        Sequence,
        not_<apply_wrap<typename lambda<Predicate>::type, _1>>
    >
{ };

template <typename Sequence>
struct dispatch<detail::default_<tag::all_of>, Sequence>
    : algorithm::all_of<Sequence, _1>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_DETAIL_DEFAULT_ALL_OF_HPP
