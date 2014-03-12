/*!
 * @file
 * Defines the @ref IntegralDomain typeclass.
 */

#ifndef BOOST_MPL11_INTEGRAL_DOMAIN_HPP
#define BOOST_MPL11_INTEGRAL_DOMAIN_HPP

#include <boost/mpl11/fwd/integral_domain.hpp>

#include <boost/mpl11/core.hpp>
#include <boost/mpl11/detail/apply_to_common.hpp>


namespace boost { namespace mpl11 {
    template <typename Left, typename Right, typename>
    struct IntegralDomain {
        template <typename x, typename y>
        using div_impl = detail::apply_to_common<div, x, y>;

        template <typename x, typename y>
        using mod_impl = detail::apply_to_common<mod, x, y>;
    };

    template <typename x, typename y>
    struct div :
        IntegralDomain<
            typename datatype<typename x::type>::type,
            typename datatype<typename y::type>::type
        >::template div_impl<x, y>
    { };

    template <typename x, typename y>
    struct mod :
        IntegralDomain<
            typename datatype<typename x::type>::type,
            typename datatype<typename y::type>::type
        >::template mod_impl<x, y>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INTEGRAL_DOMAIN_HPP
