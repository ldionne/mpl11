/*!
 * @file
 * Includes all the intrinsics provided with the library.
 */

#ifndef BOOST_MPL11_INTRINSICS_HPP
#define BOOST_MPL11_INTRINSICS_HPP

/*!
 * @defgroup intrinsic Intrinsics
 */

/*!
 * @ingroup intrinsic
 * @defgroup comparison_intrinsic Comparison Intrinsics
 *
 * Compares several types with a given operator.
 *
 * Comparison intrinsics are standard tag-dispatched intrinsics, whose
 * semantics and default implementation share a common pattern described here.
 *
 *
 * ### Semantics and default implementation
 *
 * Let `F` be a comparison intrinsic representing an operator `Op`.
 *
 * When invoked with arguments `T1`, `T2`, ...`Tn`, equivalent to
 * `and_<F<T1, T2>, F<T2, Tn...>>`.
 *
 * When invoked with arguments `T1` and `T2`, equivalent to
 * `identity<bool_<T1::value Op T2::value>>` if `T1` and `T2`
 * are `IntegralConstant`s, and unspecified otherwise.
 *
 *
 * @warning
 * Differences from the original MPL:
 * - Standard tag dispatching is used with comparison intrinsics.
 * - More than two types can be compared at once.
 */

/*!
 * @ingroup intrinsic
 * @defgroup logical_intrinsic Logical Intrinsics
 *
 * Returns the result of a short-circuiting logical operator on its arguments.
 *
 * The semantics and default implementation of the `and_` and `or_` logical
 * intrinsics share a common pattern described here.
 *
 *
 * ### Semantics and default implementation of `and_` and `or_`
 *
 * Let `F` be a logical intrinsic representing a logical operator `Op`.
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
 * @namespace boost::mpl11::intrinsic
 * Contains all the intrinsics provided with the library.
 */

#include <boost/mpl11/intrinsic/and.hpp>
#include <boost/mpl11/intrinsic/at.hpp>
#include <boost/mpl11/intrinsic/back.hpp>
#include <boost/mpl11/intrinsic/begin.hpp>
#include <boost/mpl11/intrinsic/category_of.hpp>
#include <boost/mpl11/intrinsic/clear.hpp>
#include <boost/mpl11/intrinsic/deref.hpp>
#include <boost/mpl11/intrinsic/end.hpp>
#include <boost/mpl11/intrinsic/equal_to.hpp>
#include <boost/mpl11/intrinsic/erase.hpp>
#include <boost/mpl11/intrinsic/erase_key.hpp>
#include <boost/mpl11/intrinsic/first.hpp>
#include <boost/mpl11/intrinsic/front.hpp>
#include <boost/mpl11/intrinsic/greater.hpp>
#include <boost/mpl11/intrinsic/greater_equal.hpp>
#include <boost/mpl11/intrinsic/has_key.hpp>
#include <boost/mpl11/intrinsic/insert.hpp>
#include <boost/mpl11/intrinsic/insert_range.hpp>
#include <boost/mpl11/intrinsic/is_empty.hpp>
#include <boost/mpl11/intrinsic/key_of.hpp>
#include <boost/mpl11/intrinsic/less.hpp>
#include <boost/mpl11/intrinsic/less_equal.hpp>
#include <boost/mpl11/intrinsic/next.hpp>
#include <boost/mpl11/intrinsic/not.hpp>
#include <boost/mpl11/intrinsic/not_equal_to.hpp>
#include <boost/mpl11/intrinsic/or.hpp>
#include <boost/mpl11/intrinsic/pop_back.hpp>
#include <boost/mpl11/intrinsic/pop_front.hpp>
#include <boost/mpl11/intrinsic/prior.hpp>
#include <boost/mpl11/intrinsic/push_back.hpp>
#include <boost/mpl11/intrinsic/push_front.hpp>
#include <boost/mpl11/intrinsic/second.hpp>
#include <boost/mpl11/intrinsic/size.hpp>
#include <boost/mpl11/intrinsic/value_of.hpp>

#endif // !BOOST_MPL11_INTRINSICS_HPP
