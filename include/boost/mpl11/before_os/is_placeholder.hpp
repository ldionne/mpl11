/*!
 * @file
 * Defines `boost::mpl11::is_placeholder`.
 */

#ifndef BOOST_MPL11_IS_PLACEHOLDER_HPP
#define BOOST_MPL11_IS_PLACEHOLDER_HPP

#include <boost/mpl11/fwd/is_placeholder.hpp>

#include <boost/mpl11/bool.hpp>


namespace boost { namespace mpl11 {
    template <typename T>
    struct is_placeholder
        : false_
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_IS_PLACEHOLDER_HPP
