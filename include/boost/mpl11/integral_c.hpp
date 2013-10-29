/*!
 * @file
 * Defines `boost::mpl11::integral_c`.
 */

#ifndef BOOST_MPL11_INTEGRAL_C_HPP
#define BOOST_MPL11_INTEGRAL_C_HPP

#include <boost/mpl11/fwd/integral_c.hpp>

#include <boost/mpl11/fwd/class_of.hpp>
#include <boost/mpl11/integral_constant.hpp>


namespace boost { namespace mpl11 {
    template <typename I, I N>
    struct integral_c {
        using value_type = I;
        static constexpr value_type value = N;
        constexpr operator value_type() const { return value; }
    };

    template <typename I, I N>
    struct class_of<integral_c<I, N>> {
        using type = IntegralConstant<integral_c>;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INTEGRAL_C_HPP
