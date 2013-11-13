/*!
 * @file
 * Defines `boost::mpl11::not_equal`.
 */

#ifndef BOOST_MPL11_NOT_EQUAL_HPP
#define BOOST_MPL11_NOT_EQUAL_HPP

#include <boost/mpl11/fwd/not_equal.hpp>

#include <boost/mpl11/detail/comparison_operator.hpp>


BOOST_MPL11_DEFINE_COMPARISON_OPERATOR(not_equal, not_equal_impl)

#endif // !BOOST_MPL11_NOT_EQUAL_HPP
