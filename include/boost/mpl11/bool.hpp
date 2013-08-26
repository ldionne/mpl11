/*!
 * @file
 * Defines `boost::mpl11::true_` and `boost::mpl11::false_`.
 */

#ifndef BOOST_MPL11_BOOL_HPP
#define BOOST_MPL11_BOOL_HPP

#include <boost/mpl11/integral_c.hpp>


namespace boost { namespace mpl11 {
    using true_ = bool_<true>;
    using false_ = bool_<false>;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_BOOL_HPP
