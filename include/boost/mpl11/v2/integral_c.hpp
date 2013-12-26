/*!
 * @file
 * Defines `boost::mpl11::integral_c`.
 */

#ifndef BOOST_MPL11_INTEGRAL_C_HPP
#define BOOST_MPL11_INTEGRAL_C_HPP

#include <boost/mpl11/fwd/integral_c.hpp>


namespace boost { namespace mpl11 {
    template <typename T, T v>
    struct integral_c {
        using value_type = T;
        static constexpr value_type value = v;
        constexpr operator value_type() const { return value; }
        constexpr operator() const { return value; }
        using type = integral_c;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INTEGRAL_C_HPP
