/*!
 * @file
 * Defines the @ref Ring typeclass.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_MPL11_RING_HPP
#define BOOST_MPL11_RING_HPP

#include <boost/mpl11/fwd/ring.hpp>

#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/core.hpp>
#include <boost/mpl11/detail/strict_variadic_foldl.hpp>
#include <boost/mpl11/functional.hpp>


namespace boost { namespace mpl11 {
    template <typename Left, typename Right, typename>
    struct Ring : false_ { };

    template <typename x1, typename x2, typename ...xn>
    struct mult
        : detail::strict_variadic_foldl<lift<mult>, x1, x2, xn...>
    { };

    template <typename x, typename y>
    struct mult<x, y> :
        Ring<
            typename datatype<typename x::type>::type,
            typename datatype<typename y::type>::type
        >::template mult_impl<typename x::type, typename y::type>
    { };

    template <typename Datatype>
    struct one : Ring<Datatype>::template one_impl<> { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_RING_HPP
