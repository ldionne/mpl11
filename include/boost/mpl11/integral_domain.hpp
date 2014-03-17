/*!
 * @file
 * Defines the @ref IntegralDomain typeclass.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_MPL11_INTEGRAL_DOMAIN_HPP
#define BOOST_MPL11_INTEGRAL_DOMAIN_HPP

#include <boost/mpl11/fwd/integral_domain.hpp>

#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/core.hpp>


namespace boost { namespace mpl11 {
    template <typename Left, typename Right, typename>
    struct IntegralDomain : false_ { };

    template <typename x, typename y>
    struct div :
        IntegralDomain<
            typename datatype<typename x::type>::type,
            typename datatype<typename y::type>::type
        >::template div_impl<typename x::type, typename y::type>
    { };

    template <typename x, typename y>
    struct mod :
        IntegralDomain<
            typename datatype<typename x::type>::type,
            typename datatype<typename y::type>::type
        >::template mod_impl<typename x::type, typename y::type>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INTEGRAL_DOMAIN_HPP
