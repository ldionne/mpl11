/*!
 * @file
 * Defines the `check_finite_iterable` utility to ease unit testing of
 * `Iterable`s.
 */

#ifndef BOOST_MPL11_TEST_CHECK_FINITE_ITERABLE_HPP
#define BOOST_MPL11_TEST_CHECK_FINITE_ITERABLE_HPP

#include <boost/mpl11/detail/static_assert.hpp>
#include <boost/mpl11/detail/std_equal.hpp>
#include <boost/mpl11/fwd/comparable.hpp>
#include <boost/mpl11/fwd/iterable.hpp>
#include "minimal_iterable.hpp"


namespace check_finite_iter_detail {
    using namespace boost::mpl11;

    template <typename x, typename y,
        typename Expected = typename x::type,
        typename Actual = typename y::type>
    using assert_eq = detail::static_assert_<equal<x, y>>;

    template <typename x, typename y,
        typename Expected = typename x::type,
        typename Actual = typename y::type>
    using assert_std_eq = detail::static_assert_<detail::std_equal<x, y>>;

    template <typename reference, typename iter,
        bool = is_empty<reference>::value>
    struct impl
        : assert_eq<head<reference>, head<iter>>
        , assert_std_eq<tail<reference>, tail<iter>>
        , assert_eq<is_empty<reference>, is_empty<iter>>
    { };

    template <typename reference, typename iter>
    struct impl<reference, iter, true>
        : detail::static_assert_<is_empty<iter>>
    { };
} // end namespace check_finite_iter_detail


/*!
 * Generic unit test for finite iterables.
 *
 * To use `check_finite_iterable`, simply instantiate it with the first
 * argument being the tested iterable and `xs...` being the
 * expected contents of the iterable.
 */
template <typename iter, typename ...xs>
using check_finite_iterable =
    check_finite_iter_detail::impl<minimal_iterable<xs...>, iter>;

#endif // !BOOST_MPL11_TEST_CHECK_FINITE_ITERABLE_HPP
