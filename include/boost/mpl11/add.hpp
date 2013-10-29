/*!
 * @file
 * Defines `boost::mpl11::add`.
 */

#ifndef BOOST_MPL11_ADD_HPP
#define BOOST_MPL11_ADD_HPP

#include <boost/mpl11/fwd/add.hpp>

#include <boost/mpl11/detail/left_associative_operator.hpp>


BOOST_MPL11_DEFINE_LEFT_ASSOCIATIVE_OPERATOR(add, add_impl)

#endif // !BOOST_MPL11_ADD_HPP
