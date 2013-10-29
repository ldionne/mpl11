/*!
 * @file
 * Defines `boost::mpl11::shift_left`.
 */

#ifndef BOOST_MPL11_SHIFT_LEFT_HPP
#define BOOST_MPL11_SHIFT_LEFT_HPP

#include <boost/mpl11/fwd/shift_left.hpp>

#include <boost/mpl11/detail/left_associative_operator.hpp>


BOOST_MPL11_DEFINE_LEFT_ASSOCIATIVE_OPERATOR(shift_left, shift_left_impl)

#endif // !BOOST_MPL11_SHIFT_LEFT_HPP
