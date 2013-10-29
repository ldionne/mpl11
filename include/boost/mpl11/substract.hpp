/*!
 * @file
 * Defines `boost::mpl11::substract`.
 */

#ifndef BOOST_MPL11_SUBSTRACT_HPP
#define BOOST_MPL11_SUBSTRACT_HPP

#include <boost/mpl11/fwd/substract.hpp>

#include <boost/mpl11/detail/left_associative_operator.hpp>


BOOST_MPL11_DEFINE_LEFT_ASSOCIATIVE_OPERATOR(substract, substract_impl)

#endif // !BOOST_MPL11_SUBSTRACT_HPP
