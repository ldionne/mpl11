/*!
 * @file
 * Defines `boost::mpl11::shift_right`.
 */

#ifndef BOOST_MPL11_SHIFT_RIGHT_HPP
#define BOOST_MPL11_SHIFT_RIGHT_HPP

#include <boost/mpl11/fwd/shift_right.hpp>

#include <boost/mpl11/detail/left_associative_operator.hpp>


BOOST_MPL11_DEFINE_LEFT_ASSOCIATIVE_OPERATOR(shift_right, shift_right_impl)

#endif // !BOOST_MPL11_SHIFT_RIGHT_HPP
