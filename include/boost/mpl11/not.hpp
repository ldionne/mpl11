/*!
 * @file
 * Defines `boost::mpl11::not_`.
 */

#ifndef BOOST_MPL11_NOT_HPP
#define BOOST_MPL11_NOT_HPP

#include <boost/mpl11/fwd/not.hpp>

#include <boost/mpl11/class.hpp>


namespace boost { namespace mpl11 {
    template <typename Boolean>
    struct not_
        : class_<Boolean>::type::template not_<Boolean>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_NOT_HPP
