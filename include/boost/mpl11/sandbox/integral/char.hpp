/*!
 * @file
 * This file defines `boost::mpl11::char_`.
 */

#ifndef BOOST_MPL11_INTEGRAL_CHAR_HPP
#define BOOST_MPL11_INTEGRAL_CHAR_HPP

#include <boost/mpl11/integral_c.hpp>


namespace boost { namespace mpl11 {
    template <char c>
    using char_ = integral_c<char, c>;
}}

#endif // !BOOST_MPL11_INTEGRAL_CHAR_HPP
