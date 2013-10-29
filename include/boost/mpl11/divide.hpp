/*!
 * @file
 * Defines `boost::mpl11::divide`.
 */

#ifndef BOOST_MPL11_DIVIDE_HPP
#define BOOST_MPL11_DIVIDE_HPP

#include <boost/mpl11/fwd/divide.hpp>

#include <boost/mpl11/detail/left_associative_operator.hpp>


BOOST_MPL11_DEFINE_LEFT_ASSOCIATIVE_OPERATOR(divide, divide_impl)

#endif // !BOOST_MPL11_DIVIDE_HPP
