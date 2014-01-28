/*!
 * @file
 * Defines the @ref Orderable typeclass.
 */

#ifndef BOOST_MPL11_ORDERABLE_HPP
#define BOOST_MPL11_ORDERABLE_HPP

#include <boost/mpl11/fwd/orderable.hpp>

#include <boost/mpl11/core.hpp>
#include <boost/mpl11/detail/std_conditional.hpp>
#include <boost/mpl11/detail/strict_variadic_foldl.hpp>
#include <boost/mpl11/functional.hpp>
#include <boost/mpl11/logical.hpp>


namespace boost { namespace mpl11 {
    template <>
    struct Orderable<typeclass<Orderable>, typeclass<Orderable>> {
        template <typename left, typename right>
        using less_equal_impl = not_<less<box<right>, box<left>>>;

        template <typename left, typename right>
        using greater_impl = less<box<right>, box<left>>;

        template <typename left, typename right>
        using greater_equal_impl = not_<less<box<left>, box<right>>>;

        template <typename left, typename right>
        using min_impl = detail::std_conditional<
            less<box<left>, box<right>>::value, left, right
        >;

        template <typename left, typename right>
        using max_impl = detail::std_conditional<
            less<box<left>, box<right>>::value, right, left
        >;
    };


    template <typename x1, typename x2, typename ...xs>
    struct less
        : and_<less<x1, x2>, less<x2, xs...>>
    { };

    template <typename x, typename y>
    struct less<x, y> :
        Orderable<
            typename datatype<typename x::type>::type,
            typename datatype<typename y::type>::type
        >::template less_impl<typename x::type, typename y::type>
    { };


    template <typename x1, typename x2, typename ...xs>
    struct less_equal
        : and_<less_equal<x1, x2>, less_equal<x2, xs...>>
    { };

    template <typename x, typename y>
    struct less_equal<x, y> :
        Orderable<
            typename datatype<typename x::type>::type,
            typename datatype<typename y::type>::type
        >::template less_equal_impl<typename x::type, typename y::type>
    { };


    template <typename x1, typename x2, typename ...xs>
    struct greater
        : and_<greater<x1, x2>, greater<x2, xs...>>
    { };

    template <typename x, typename y>
    struct greater<x, y> :
        Orderable<
            typename datatype<typename x::type>::type,
            typename datatype<typename y::type>::type
        >::template greater_impl<typename x::type, typename y::type>
    { };


    template <typename x1, typename x2, typename ...xs>
    struct greater_equal
        : and_<greater_equal<x1, x2>, greater_equal<x2, xs...>>
    { };

    template <typename x, typename y>
    struct greater_equal<x, y> :
        Orderable<
            typename datatype<typename x::type>::type,
            typename datatype<typename y::type>::type
        >::template greater_equal_impl<typename x::type, typename y::type>
    { };


    template <typename x1, typename x2, typename ...xs>
    struct min
        : detail::strict_variadic_foldl<quote<min>, x1, x2, xs...>
    { };

    template <typename x, typename y>
    struct min<x, y> :
        Orderable<
            typename datatype<typename x::type>::type,
            typename datatype<typename y::type>::type
        >::template min_impl<typename x::type, typename y::type>
    { };


    template <typename x1, typename x2, typename ...xs>
    struct max
        : detail::strict_variadic_foldl<quote<max>, x1, x2, xs...>
    { };

    template <typename x, typename y>
    struct max<x, y> :
        Orderable<
            typename datatype<typename x::type>::type,
            typename datatype<typename y::type>::type
        >::template max_impl<typename x::type, typename y::type>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ORDERABLE_HPP
