/*!
 * @file
 * Defines `boost::mpl11::Integral::minus`.
 */

#ifndef BOOST_MPL11_INTEGRAL_MINUS_HPP
#define BOOST_MPL11_INTEGRAL_MINUS_HPP

#include <boost/mpl11/integral/integral.hpp>
#include <boost/mpl11/negate.hpp>
#include <boost/mpl11/plus.hpp>


namespace boost { namespace mpl11 {
    template <typename M, typename N>
    struct Integral::minus
        : plus<M, typename negate<N>::type>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INTEGRAL_MINUS_HPP
