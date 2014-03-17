/*!
 * @file
 * Defines the `check_foldable` utility to ease unit testing of `Foldable`s.
 */

#ifndef BOOST_MPL11_TEST_CHECK_FOLDABLE_HPP
#define BOOST_MPL11_TEST_CHECK_FOLDABLE_HPP

#include <boost/mpl11/detail/static_assert.hpp>
#include <boost/mpl11/detail/std_is_same.hpp>
#include <boost/mpl11/foldable.hpp>
#include <boost/mpl11/functional.hpp>

#include "minimal_foldable.hpp"


namespace check_foldable_detail {
    using namespace boost::mpl11;

    template <typename x, typename y,
        typename x_ = typename x::type, typename y_ = typename y::type
    >
    struct assert_same
        : detail::static_assert_<detail::std_is_same<x_, y_>>
    { };

    struct state { struct type; };

    template <typename x, typename y>
    struct f {
        using type = f<typename x::type, typename y::type>;
    };

    template <typename structure, typename ...xs>
    struct check_foldable
        : assert_same<
            foldl<lift<f>, state, structure>,
            foldl<lift<f>, state, minimal_foldable<xs...>>
        >
        , assert_same<
            foldr<lift<f>, state, structure>,
            foldr<lift<f>, state, minimal_foldable<xs...>>
        >
    { };

    template <typename structure, typename x, typename ...xs>
    struct check_foldable<structure, x, xs...>
        : assert_same<
            foldl<lift<f>, state, structure>,
            foldl<lift<f>, state, minimal_foldable<x, xs...>>
        >
        , assert_same<
            foldr<lift<f>, state, structure>,
            foldr<lift<f>, state, minimal_foldable<x, xs...>>
        >
        , assert_same<
            foldl1<lift<f>, structure>,
            foldl1<lift<f>, minimal_foldable<x, xs...>>
        >
        , assert_same<
            foldr1<lift<f>, structure>,
            foldr1<lift<f>, minimal_foldable<x, xs...>>
        >
    { };
} // end namespace check_foldable_detail

using check_foldable_detail::check_foldable;

#endif // !BOOST_MPL11_TEST_CHECK_FOLDABLE_HPP
