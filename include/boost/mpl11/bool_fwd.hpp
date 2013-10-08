/*!
 * @file
 * Forward declares `boost::mpl11::true_` and `boost::mpl11::false_`.
 */

#ifndef BOOST_MPL11_BOOL_FWD_HPP
#define BOOST_MPL11_BOOL_FWD_HPP

#include <boost/mpl11/integral_c_fwd.hpp>


namespace boost { namespace mpl11 {
    using true_ = bool_<true>;
    using false_ = bool_<false>;
}}

#endif // !BOOST_MPL11_BOOL_FWD_HPP
