/*!
 * @file
 * Defines `boost::mpl11::subtract`.
 */

#ifndef BOOST_MPL11_SUBTRACT_HPP
#define BOOST_MPL11_SUBTRACT_HPP

#include <boost/mpl11/fwd/subtract.hpp>

#include <boost/mpl11/detail/left_associative_operator.hpp>


BOOST_MPL11_DEFINE_LEFT_ASSOCIATIVE_OPERATOR(subtract, subtract_impl)

#endif // !BOOST_MPL11_SUBTRACT_HPP
