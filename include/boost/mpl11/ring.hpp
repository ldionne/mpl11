/*!
 * @file
 * Defines the @ref Ring typeclass.
 */

#ifndef BOOST_MPL11_RING_HPP
#define BOOST_MPL11_RING_HPP

#include <boost/mpl11/fwd/ring.hpp>

#include <boost/mpl11/core.hpp>
#include <boost/mpl11/detail/apply_to_common.hpp>
#include <boost/mpl11/detail/strict_variadic_foldl.hpp>
#include <boost/mpl11/functional.hpp>


namespace boost { namespace mpl11 {
    template <typename Left, typename Right, typename>
    struct Ring {
        template <typename x, typename y>
        using mult_impl = detail::apply_to_common<mult, x, y>;
    };

    template <typename x1, typename x2, typename ...xn>
    struct mult
        : detail::strict_variadic_foldl<quote<mult>, x1, x2, xn...>
    { };

    template <typename x, typename y>
    struct mult<x, y> :
        Ring<
            typename datatype<typename x::type>::type,
            typename datatype<typename y::type>::type
        >::template mult_impl<x, y>
    { };

    template <typename Datatype>
    struct one : Ring<Datatype>::template one_impl<> { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_RING_HPP
