/*!
 * @file
 * Defines `boost::mpl11::less`.
 */

#ifndef BOOST_MPL11_LESS_HPP
#define BOOST_MPL11_LESS_HPP

#include <boost/mpl11/v2/fwd/less.hpp>

#include <boost/mpl11/v2/fwd/orderable.hpp>


#define BOOST_MPL11_OPERATOR less
#define BOOST_MPL11_OPERATOR_IMPL less_impl
#define BOOST_MPL11_TYPECLASS Orderable
#include <boost/mpl11/v2/detail/comparison_operator.hpp>

#endif // !BOOST_MPL11_LESS_HPP
