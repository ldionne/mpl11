/*!
 * @file
 * Defines the @ref Monoid typeclass.
 */

#ifndef BOOST_MPL11_MONOID_HPP
#define BOOST_MPL11_MONOID_HPP

#include <boost/mpl11/fwd/monoid.hpp>

#include <boost/mpl11/core.hpp>
#include <boost/mpl11/detail/common_method.hpp>


namespace boost { namespace mpl11 {
    template <typename Left, typename Right>
    struct Monoid {
        template <typename x, typename y>
        using plus_impl =
            typename detail::common_method<Left, Right>::
            template apply<
                Monoid<typename common_datatype<Left, Right>::type>::
                template plus_impl, x, y
            >;
    };

    template <typename x, typename y>
    struct plus :
        Monoid<
            typename datatype<typename x::type>::type,
            typename datatype<typename y::type>::type
        >::template plus_impl<x, y>
    { };

    template <typename Datatype>
    struct zero : Monoid<Datatype>::template zero_impl<> { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_MONOID_HPP
