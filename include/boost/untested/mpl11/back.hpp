/*!
 * @file
 * Defines `boost::mpl11::back`.
 */

#ifndef BOOST_MPL11_BACK_HPP
#define BOOST_MPL11_BACK_HPP

#include <boost/mpl11/fwd/back.hpp>

#include <boost/mpl11/class.hpp>


namespace boost { namespace mpl11 {
    template <typename Sequence>
    struct back
        : class_<Sequence>::type::template back<Sequence>
    { };
}}

#endif // !BOOST_MPL11_BACK_HPP
