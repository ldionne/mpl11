/*!
 * @file
 * Defines `boost::mpl11::Integral::negate`.
 */

#ifndef BOOST_MPL11_INTEGRAL_NEGATE_HPP
#define BOOST_MPL11_INTEGRAL_NEGATE_HPP

#include <boost/mpl11/detail/not_implemented.hpp>
#include <boost/mpl11/integral/integral.hpp>


namespace boost { namespace mpl11 {
    template <typename I>
    struct Integral::negate
        : detail::not_implemented<negate<I>>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INTEGRAL_NEGATE_HPP
