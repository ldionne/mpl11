/*!
 * @file
 * Defines the default implementation of `boost::mpl11::algorithm::any_of`.
 */

#ifndef BOOST_MPL11_DETAIL_DEFAULT_ANY_OF_HPP
#define BOOST_MPL11_DETAIL_DEFAULT_ANY_OF_HPP

#include <boost/mpl11/algorithm/any_of.hpp>
#include <boost/mpl11/algorithm/none_of.hpp>
#include <boost/mpl11/arg.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/intrinsic/not.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
template <typename Sequence, typename Predicate>
struct dispatch<detail::default_<tag::any_of>, Sequence, Predicate>
    : intrinsic::not_<algorithm::none_of<Sequence, Predicate>>
{ };

template <typename Sequence>
struct dispatch<detail::default_<tag::any_of>, Sequence>
    : algorithm::any_of<Sequence, _1>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_DETAIL_DEFAULT_ANY_OF_HPP
