/*!
 * @file
 * Defines `boost::mpl11::equal`.
 */

#ifndef BOOST_MPL11_EQUAL_HPP
#define BOOST_MPL11_EQUAL_HPP

#include <boost/mpl11/v2/fwd/equal.hpp>

#include <boost/mpl11/v2/fwd/comparable.hpp>


#define BOOST_MPL11_OPERATOR equal
#define BOOST_MPL11_OPERATOR_IMPL equal_impl
#define BOOST_MPL11_TYPECLASS Comparable
#include <boost/mpl11/v2/detail/comparison_operator.hpp>

#endif // !BOOST_MPL11_EQUAL_HPP
