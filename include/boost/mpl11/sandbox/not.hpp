/*!
 * @file
 * This file defines `boost::mpl11::not_`.
 */

#ifndef BOOST_MPL11_NOT_HPP
#define BOOST_MPL11_NOT_HPP

#include <boost/mpl11/bool.hpp>


namespace boost { namespace mpl11 {
    template <typename F>
    struct not_
        : bool_<!F::type::value>
    { };
}}

#endif // !BOOST_MPL11_NOT_HPP
