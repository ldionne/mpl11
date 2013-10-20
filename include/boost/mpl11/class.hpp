/*!
 * @file
 * Defines `boost::mpl11::class_`.
 */

#ifndef BOOST_MPL11_CLASS_HPP
#define BOOST_MPL11_CLASS_HPP

#include <boost/mpl11/fwd/class.hpp>

#include <boost/mpl11/identity.hpp>


namespace boost { namespace mpl11 {
    template <typename Object>
    struct class_
        : identity<typename Object::mpl_class>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_CLASS_HPP
