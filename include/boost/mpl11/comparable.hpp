/*!
 * @file
 * Defines the @ref Comparable typeclass.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_MPL11_COMPARABLE_HPP
#define BOOST_MPL11_COMPARABLE_HPP

#include <boost/mpl11/fwd/comparable.hpp>

#include <boost/mpl11/fwd/bool.hpp>
#include <boost/mpl11/fwd/core.hpp>
#include <boost/mpl11/fwd/logical.hpp>


namespace boost { namespace mpl11 {
    template <>
    struct instantiate<Comparable> {
        template <typename Left, typename Right = Left>
        struct with : true_ {
            template <typename x, typename y>
            using equal_impl = not_<not_equal<box<x>, box<y>>>;

            template <typename x, typename y>
            using not_equal_impl = not_<equal<box<x>, box<y>>>;
        };
    };
}}


#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/core.hpp>
#include <boost/mpl11/detail/std_is_same.hpp>
#include <boost/mpl11/logical.hpp>


namespace boost { namespace mpl11 {
    template <typename Left, typename Right, typename>
    struct Comparable : instantiate<Comparable>::template with<Left, Right> {
        template <typename x, typename y>
        using equal_impl = bool_<detail::std_is_same<x, y>::value>;

        template <typename x, typename y>
        using not_equal_impl = bool_<!detail::std_is_same<x, y>::value>;
    };

    template <typename x1, typename x2, typename ...xs>
    struct equal
        : and_<equal<x1, x2>, equal<x2, xs...>>
    { };

    template <typename x, typename y>
    struct equal<x, y> :
        Comparable<
            typename datatype<typename x::type>::type,
            typename datatype<typename y::type>::type
        >::template equal_impl<typename x::type, typename y::type>
    { };

    template <typename x, typename y>
    struct not_equal :
        Comparable<
            typename datatype<typename x::type>::type,
            typename datatype<typename y::type>::type
        >::template not_equal_impl<typename x::type, typename y::type>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_COMPARABLE_HPP
