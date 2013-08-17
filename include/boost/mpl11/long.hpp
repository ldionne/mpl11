/*!
 * @file
 * This file defines `boost::mpl11::long_`.
 */

#ifndef BOOST_MPL11_LONG_HPP
#define BOOST_MPL11_LONG_HPP

#include <boost/mpl11/integral_c.hpp>


namespace boost { namespace mpl11 {
    template <long N>
    using long_ = integral_c<long, N>;
}}

#endif // !BOOST_MPL11_LONG_HPP
