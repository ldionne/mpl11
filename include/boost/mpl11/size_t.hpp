/*!
 * @file
 * This file defines `boost::mpl11::size_t`.
 */

#ifndef BOOST_MPL11_SIZE_T_HPP
#define BOOST_MPL11_SIZE_T_HPP

#include <boost/mpl11/integral_c.hpp>

#include <cstddef>


namespace boost { namespace mpl11 {
    template <std::size_t N>
    using size_t = integral_c<std::size_t, N>;
}}

#endif // !BOOST_MPL11_SIZE_T_HPP
