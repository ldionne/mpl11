/*!
 * @file
 * This file defines `boost::mpl11::int_`.
 */

#ifndef BOOST_MPL11_INT_HPP
#define BOOST_MPL11_INT_HPP

#include <boost/mpl11/integral_c.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
    template <int N>
    using int_ = integral_c<int, N>;
}}}

#endif // !BOOST_MPL11_INT_HPP
