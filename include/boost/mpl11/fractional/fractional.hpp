/*!
 * @file
 * Defines `boost::mpl11::Fractional`.
 */

#ifndef BOOST_MPL11_FRACTIONAL_FRACTIONAL_HPP
#define BOOST_MPL11_FRACTIONAL_FRACTIONAL_HPP

#include <boost/mpl11/fwd/fractional.hpp>

#include <boost/mpl11/integral/integral.hpp>


namespace boost { namespace mpl11 {
    struct Fractional : Integral {
        template <typename M, typename N>
        struct over;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FRACTIONAL_FRACTIONAL_HPP
