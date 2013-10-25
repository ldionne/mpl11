/*!
 * @file
 * Defines `boost::mpl11::Integral`.
 */

#ifndef BOOST_MPL11_INTEGRAL_INTEGRAL_HPP
#define BOOST_MPL11_INTEGRAL_INTEGRAL_HPP

#include <boost/mpl11/fwd/integral.hpp>

#include <boost/mpl11/natural/natural.hpp>


namespace boost { namespace mpl11 {
    struct Integral : Natural {
        template <typename M, typename N>
        struct minus;

        template <typename M, typename N>
        struct negate;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INTEGRAL_INTEGRAL_HPP
