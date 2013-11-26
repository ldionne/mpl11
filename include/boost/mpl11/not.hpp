/*!
 * @file
 * Defines `boost::mpl11::not_`.
 */

#ifndef BOOST_MPL11_NOT_HPP
#define BOOST_MPL11_NOT_HPP

#include <boost/mpl11/fwd/not.hpp>

#include <boost/mpl11/class_of.hpp>
#include <boost/mpl11/integral_c.hpp>


namespace boost { namespace mpl11 {
    template <typename F>
    struct not_
        : class_of<typename F::type>::type::template
            not_impl<typename F::type>
    { };

    template <bool B>
    struct not_c
        : bool_<!B>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_NOT_HPP
