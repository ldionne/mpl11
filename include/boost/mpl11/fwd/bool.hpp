/*!
 * @file
 * Forward declares `boost::mpl11::true_` and `boost::mpl11::false_`.
 */

#ifndef BOOST_MPL11_FWD_BOOL_HPP
#define BOOST_MPL11_FWD_BOOL_HPP

#include <boost/mpl11/fwd/integral_c.hpp>


namespace boost { namespace mpl11 {
    using true_ = bool_<true>;
    using false_ = bool_<false>;
}}

#endif // !BOOST_MPL11_FWD_BOOL_HPP
