/*!
 * @file
 * Defines `boost::mpl11::has_optimization`.
 */

#ifndef BOOST_MPL11_HAS_OPTIMIZATION_HPP
#define BOOST_MPL11_HAS_OPTIMIZATION_HPP

#include <boost/mpl11/fwd/has_optimization.hpp>

#include <boost/mpl11/integral_c.hpp>


namespace boost { namespace mpl11 {
    template <typename T, typename Optimization>
    struct has_optimization
        : false_
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_HAS_OPTIMIZATION_HPP
