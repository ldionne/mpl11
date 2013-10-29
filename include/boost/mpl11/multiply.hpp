/*!
 * @file
 * Defines `boost::mpl11::multiply`.
 */

#ifndef BOOST_MPL11_MULTIPLY_HPP
#define BOOST_MPL11_MULTIPLY_HPP

#include <boost/mpl11/fwd/multiply.hpp>

#include <boost/mpl11/detail/left_associative_operator.hpp>


BOOST_MPL11_DEFINE_LEFT_ASSOCIATIVE_OPERATOR(multiply, multiply_impl)

#endif // !BOOST_MPL11_MULTIPLY_HPP
