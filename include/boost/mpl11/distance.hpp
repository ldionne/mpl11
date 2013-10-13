/*!
 * @file
 * Defines `boost::mpl11::distance`.
 */

#ifndef BOOST_MPL11_DISTANCE_HPP
#define BOOST_MPL11_DISTANCE_HPP

#include <boost/mpl11/fwd/distance.hpp>

#include <boost/mpl11/arg.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/foldl.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/iterator_range.hpp>
#include <boost/mpl11/next.hpp>


namespace boost { namespace mpl11 {
    template <typename First, typename Last>
    struct dispatch<tag::default_<tag::distance>, First, Last>
        : foldl<
            iterator_range<First, Last>,
            ulong<0>,
            next<_1>
        >
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_DISTANCE_HPP
