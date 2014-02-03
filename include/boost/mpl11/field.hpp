/*!
 * @file
 * Defines the @ref Field typeclass.
 */

#ifndef BOOST_MPL11_FIELD_HPP
#define BOOST_MPL11_FIELD_HPP

#include <boost/mpl11/fwd/field.hpp>

#include <boost/mpl11/core.hpp>
#include <boost/mpl11/detail/common_method.hpp>


namespace boost { namespace mpl11 {
    template <typename Left, typename Right>
    struct Field {
        template <typename x, typename y>
        using div_impl =
            typename detail::common_method<Left, Right>::
            template apply<
                Field<typename common_datatype<Left, Right>::type>::
                template div_impl, x, y
            >;
    };

    template <typename x, typename y>
    struct div :
        Field<
            typename datatype<typename x::type>::type,
            typename datatype<typename y::type>::type
        >::template div_impl<x, y>
    { };

    template <typename x>
    struct recip :
        Field<typename datatype<typename x::type>::type>::
        template recip_impl<x>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FIELD_HPP
