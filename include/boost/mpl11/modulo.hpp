/*!
 * @file
 * Defines `boost::mpl11::modulo`.
 */

#ifndef BOOST_MPL11_MODULO_HPP
#define BOOST_MPL11_MODULO_HPP

#include <boost/mpl11/fwd/modulo.hpp>

#include <boost/mpl11/detail/left_associative_operator.hpp>


BOOST_MPL11_DEFINE_LEFT_ASSOCIATIVE_OPERATOR(modulo, modulo_impl)

#endif // !BOOST_MPL11_MODULO_HPP
