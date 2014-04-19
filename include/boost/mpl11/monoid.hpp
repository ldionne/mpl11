/*!
 * @file
 * Defines the @ref Monoid typeclass.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_MPL11_MONOID_HPP
#define BOOST_MPL11_MONOID_HPP

#include <boost/mpl11/fwd/monoid.hpp>

#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/core.hpp>
#include <boost/mpl11/detail/left_folds/variadic_aliased.hpp>
#include <boost/mpl11/functional.hpp>


namespace boost { namespace mpl11 {
    template <typename Left, typename Right, typename>
    struct Monoid : false_ { };

    template <typename x1, typename x2, typename ...xn>
    struct plus
        : detail::left_folds::variadic_aliased<lift<plus>, x1, x2, xn...>
    { };

    template <typename x, typename y>
    struct plus<x, y> :
        Monoid<
            typename datatype<typename x::type>::type,
            typename datatype<typename y::type>::type
        >::template plus_impl<typename x::type, typename y::type>
    { };

    template <typename Datatype>
    struct zero : Monoid<Datatype>::template zero_impl<> { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_MONOID_HPP
