/*!
 * @file
 * Defines the @ref Orderable typeclass.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_MPL11_ORDERABLE_HPP
#define BOOST_MPL11_ORDERABLE_HPP

#include <boost/mpl11/fwd/orderable.hpp>

#include <boost/mpl11/fwd/bool.hpp>
#include <boost/mpl11/fwd/core.hpp>
#include <boost/mpl11/fwd/logical.hpp>


namespace boost { namespace mpl11 {
    template <>
    struct instantiate<Orderable> {
        template <typename Left, typename Right = Left>
        struct with : true_ {
            template <typename x, typename y>
            using less_equal_impl = not_<less<box<y>, box<x>>>;

            template <typename x, typename y>
            using greater_impl = less<box<y>, box<x>>;

            template <typename x, typename y>
            using greater_equal_impl = not_<less<box<x>, box<y>>>;

            template <typename x, typename y>
            using min_impl = if_c<less<box<x>, box<y>>::value, box<x>, box<y>>;

            template <typename x, typename y>
            using max_impl = if_c<less<box<x>, box<y>>::value, box<y>, box<x>>;
        };
    };
}} // end namespace boost::mpl11


#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/core.hpp>
#include <boost/mpl11/detail/strict_variadic_foldl.hpp>
#include <boost/mpl11/functional.hpp>
#include <boost/mpl11/logical.hpp>


namespace boost { namespace mpl11 {
    template <typename Left, typename Right, typename>
    struct Orderable : false_ { };

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
