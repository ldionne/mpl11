/*!
 * @file
 * Defines `boost::mpl11::not_equal`.
 */

#ifndef BOOST_MPL11_NOT_EQUAL_HPP
#define BOOST_MPL11_NOT_EQUAL_HPP

#include <boost/mpl11/v2/fwd/not_equal.hpp>

#include <boost/mpl11/v2/fwd/comparable.hpp>


#define BOOST_MPL11_OPERATOR not_equal
#define BOOST_MPL11_OPERATOR_IMPL not_equal_impl
#define BOOST_MPL11_TYPECLASS Comparable
#include <boost/mpl11/v2/detail/comparison_operator.hpp>

#endif // !BOOST_MPL11_NOT_EQUAL_HPP
