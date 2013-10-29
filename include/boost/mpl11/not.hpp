/*!
 * @file
 * Defines `boost::mpl11::not_`.
 */

#ifndef BOOST_MPL11_NOT_HPP
#define BOOST_MPL11_NOT_HPP

#include <boost/mpl11/fwd/not.hpp>

#include <boost/mpl11/class_of.hpp>


namespace boost { namespace mpl11 {
    template <typename F>
    struct not_
        : class_of<typename F::type>::type::template not_impl<typename F::type>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_NOT_HPP
