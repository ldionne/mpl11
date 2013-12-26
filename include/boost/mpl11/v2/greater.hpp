/*!
 * @file
 * Defines `boost::mpl11::greater`.
 */

#ifndef BOOST_MPL11_GREATER_HPP
#define BOOST_MPL11_GREATER_HPP

#include <boost/mpl11/v2/fwd/greater.hpp>

#include <boost/mpl11/v2/fwd/orderable.hpp>


#define BOOST_MPL11_OPERATOR greater
#define BOOST_MPL11_OPERATOR_IMPL greater_impl
#define BOOST_MPL11_TYPECLASS Orderable
#include <boost/mpl11/v2/detail/comparison_operator.hpp>

#endif // !BOOST_MPL11_GREATER_HPP
