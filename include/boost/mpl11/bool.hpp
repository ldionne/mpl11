/*!
 * @file
 * This file defines `boost::mpl11::bool_`.
 */

#ifndef BOOST_MPL11_BOOL_HPP
#define BOOST_MPL11_BOOL_HPP

#include <boost/mpl11/integral_c.hpp>


namespace boost { namespace mpl11 {
    template <bool b>
    using bool_ = integral_c<bool, b>;

    using true_ = bool_<true>;
    using false_ = bool_<false>;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_BOOL_HPP
