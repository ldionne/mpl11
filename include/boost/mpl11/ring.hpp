/*!
 * @file
 * Defines the @ref Ring typeclass.
 */

#ifndef BOOST_MPL11_RING_HPP
#define BOOST_MPL11_RING_HPP

#include <boost/mpl11/fwd/ring.hpp>

#include <boost/mpl11/core.hpp>
#include <boost/mpl11/detail/common_method.hpp>


namespace boost { namespace mpl11 {
    template <typename Left, typename Right>
    struct Ring {
        template <typename x, typename y>
        using mult_impl =
            typename detail::common_method<Left, Right>::
            template apply<
                Ring<typename common_datatype<Left, Right>::type>::
                template mult_impl, x, y
            >;
    };

    template <typename x, typename y>
    struct mult :
        Ring<
            typename datatype<typename x::type>::type,
            typename datatype<typename y::type>::type
        >::template mult_impl<x, y>
    { };

    template <typename Datatype>
    struct one : Ring<Datatype>::template one_impl<> { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_RING_HPP
