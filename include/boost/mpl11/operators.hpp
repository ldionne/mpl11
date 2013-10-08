/*!
 * @file
 * Includes all the intrinsics provided with the library.
 */

#ifndef BOOST_MPL11_INTRINSICS_HPP
#define BOOST_MPL11_INTRINSICS_HPP

/*!
 * @defgroup operators Operators
 */

/*!
 * @ingroup operators
 * @defgroup comparison_operators Comparison Operators
 *
 * Compares several types with a given operator.
 *
 * Comparison operators are standard tag-dispatched metafunctions, whose
 * semantics and default implementation share a common pattern described here.
 *
 *
 * ### Semantics and default implementation
 *
 * Let `F` be a comparison operator representing a C++ operator `Op`.
 *
 * When invoked with arguments `T1`, `T2`, ...`Tn`, equivalent to
 * `and_<F<T1, T2>, F<T2, Tn...>>`.
 *
 * When invoked with arguments `T1` and `T2`, the semantics and default
 * implementation depend on the operator.
 *
 *
 * @warning
 * Differences from the original MPL:
 * - Standard tag dispatching is used with these metafunctions.
 * - More than two types can be compared at once.
 */

/*!
 * @ingroup operators
 * @defgroup logical_operators Logical Operators
 *
 * Returns the result of a short-circuiting logical operator on its arguments.
 *
 * The semantics and default implementation of the `and_` and `or_` logical
 * operators share a common pattern described here.
 *
 *
 * ### Semantics and default implementation of `and_` and `or_`
 *
 * Let `F` be a logical operator representing a C++ logical operator `Op`.
 *
 * When invoked with arguments `F1`, `F2`, ...`Fn`, equivalent to
 * `F<F1, F<F2, Fn...>>`.
 *
 * When invoked with arguments `F1` and `F2`, equivalent to
 * `identity<bool_<F1::type::value Op F2::type::value>>`, except that
 * `F2::type::value` is never evaluated if the value of `F1::type::value`
 * allows short-circuiting because of the semantics of `Op`. In other words,
 * left-to-right and lazy evaluation of `F1::type::value` and
 * `F2::type::value` are guaranteed.
 */

/*!
 * @ingroup operators
 * @defgroup arithmetic_operators Arithmetic Operators
 *
 * Performs a given arithmetic operation on one or more types.
 */

#include <boost/mpl11/operator/and.hpp>
#include <boost/mpl11/operator/divides.hpp>
#include <boost/mpl11/operator/equal_to.hpp>
#include <boost/mpl11/operator/greater.hpp>
#include <boost/mpl11/operator/greater_equal.hpp>
#include <boost/mpl11/operator/less.hpp>
#include <boost/mpl11/operator/less_equal.hpp>
#include <boost/mpl11/operator/minus.hpp>
#include <boost/mpl11/operator/modulus.hpp>
#include <boost/mpl11/operator/multiplies.hpp>
#include <boost/mpl11/operator/negate.hpp>
#include <boost/mpl11/operator/not.hpp>
#include <boost/mpl11/operator/not_equal_to.hpp>
#include <boost/mpl11/operator/or.hpp>
#include <boost/mpl11/operator/plus.hpp>

#endif // !BOOST_MPL11_INTRINSICS_HPP
