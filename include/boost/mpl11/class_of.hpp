/*!
 * @file
 * Defines `boost::mpl11::class_of`.
 */

#ifndef BOOST_MPL11_CLASS_OF_HPP
#define BOOST_MPL11_CLASS_OF_HPP

#include <boost/mpl11/fwd/class_of.hpp>


namespace boost { namespace mpl11 {
    template <typename T>
    struct class_of {
        using type = typename T::mpl_class;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_CLASS_OF_HPP
