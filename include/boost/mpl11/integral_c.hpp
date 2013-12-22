/*!
 * @file
 * Defines `boost::mpl11::integral_c`.
 */

#ifndef BOOST_MPL11_INTEGRAL_C_HPP
#define BOOST_MPL11_INTEGRAL_C_HPP

#include <boost/mpl11/fwd/integral_c.hpp>

// Since `integral_c` is used everywhere, only the minimum should be
// included before it is defined. The forward declaration of `integral_c`
// is often not enough because we derive from it in many metafunctions.
#include <boost/mpl11/fwd/integral.hpp>


namespace boost { namespace mpl11 {
    template <typename T, T v>
    struct integral_c {
        using value_type = T;
        static constexpr value_type value = v;
        constexpr operator value_type() const { return value; }

        using type = integral_c;
        using mpl_class = Integral;
    };
}} // end namespace boost::mpl11

#include <boost/mpl11/integral.hpp>

#endif // !BOOST_MPL11_INTEGRAL_C_HPP
