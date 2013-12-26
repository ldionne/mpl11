/*!
 * @file
 * Defines `boost::mpl11::less_equal`.
 */

#ifndef BOOST_MPL11_LESS_EQUAL_HPP
#define BOOST_MPL11_LESS_EQUAL_HPP

#include <boost/mpl11/v2/fwd/less_equal.hpp>

#include <boost/mpl11/v2/fwd/orderable.hpp>


#define BOOST_MPL11_OPERATOR less_equal
#define BOOST_MPL11_OPERATOR_IMPL less_equal_impl
#define BOOST_MPL11_TYPECLASS Orderable
#include <boost/mpl11/v2/detail/comparison_operator.hpp>

#endif // !BOOST_MPL11_LESS_EQUAL_HPP
