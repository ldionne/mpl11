/*!
 * @file
 * Defines the @ref Group typeclass.
 */

#ifndef BOOST_MPL11_GROUP_HPP
#define BOOST_MPL11_GROUP_HPP

#include <boost/mpl11/fwd/group.hpp>

#include <boost/mpl11/core.hpp>
#include <boost/mpl11/detail/common_method.hpp>


namespace boost { namespace mpl11 {
    template <typename Left, typename Right>
    struct Group {
        template <typename x, typename y>
        using minus_impl =
            typename detail::common_method<Left, Right>::
            template apply<
                Group<typename common_datatype<Left, Right>::type>::
                template minus_impl, x, y
            >;
    };

    template <typename x, typename y>
    struct minus :
        Group<
            typename datatype<typename x::type>::type,
            typename datatype<typename y::type>::type
        >::template minus_impl<x, y>
    { };

    template <typename x>
    struct negate :
        Group<typename datatype<typename x::type>::type>::
        template negate_impl<x>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_GROUP_HPP
