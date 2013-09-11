/*!
 * @file
 * Defines the default implementation of `boost::mpl11::algorithm::distance`.
 */

#ifndef BOOST_MPL11_DETAIL_DEFAULT_DISTANCE_HPP
#define BOOST_MPL11_DETAIL_DEFAULT_DISTANCE_HPP

#include <boost/mpl11/algorithm/foldl.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/functional/arg.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/intrinsic/next.hpp>
#include <boost/mpl11/tags.hpp>
#include <boost/mpl11/view/bounded_by.hpp>


namespace boost { namespace mpl11 {
template <typename First, typename Last>
struct dispatch<detail::default_<tag::distance>, First, Last>
    : algorithm::foldl<
        view::bounded_by<First, Last>,
        ulong<0>,
        next<_1>
    >
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_DETAIL_DEFAULT_DISTANCE_HPP
