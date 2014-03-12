/*!
 * @file
 * Defines the @ref Comparable typeclass.
 */

#ifndef BOOST_MPL11_COMPARABLE_HPP
#define BOOST_MPL11_COMPARABLE_HPP

#include <boost/mpl11/fwd/comparable.hpp>

#include <boost/mpl11/fwd/core.hpp>
#include <boost/mpl11/fwd/logical.hpp>


namespace boost { namespace mpl11 {
    template <>
    struct instantiate<Comparable> {
        template <typename Left, typename Right = Left>
        struct with {
            template <typename x, typename y>
            using equal_impl = not_<not_equal<x, y>>;

            template <typename x, typename y>
            using not_equal_impl = not_<equal<x, y>>;
        };
    };
}}


#include <boost/mpl11/core.hpp>
#include <boost/mpl11/detail/apply_to_common.hpp>
#include <boost/mpl11/detail/std_is_same.hpp>
#include <boost/mpl11/logical.hpp>


namespace boost { namespace mpl11 {
    template <typename Left, typename Right, typename>
    struct Comparable {
        template <typename x, typename y>
        using equal_impl = detail::apply_to_common<equal, x, y>;

        template <typename x, typename y>
        using not_equal_impl = detail::apply_to_common<not_equal, x, y>;
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
        >::template equal_impl<x, y>
    { };

    template <typename x, typename y>
    struct not_equal :
        Comparable<
            typename datatype<typename x::type>::type,
            typename datatype<typename y::type>::type
        >::template not_equal_impl<x, y>
    { };

    template <>
    struct Comparable<Foreign> : instantiate<Comparable>::with<Foreign> {
        template <typename x, typename y>
        using equal_impl = detail::std_is_same<
            typename x::type, typename y::type
        >;

        template <typename x, typename y>
        using not_equal_impl = not_<detail::std_is_same<
            typename x::type, typename y::type
        >>;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_COMPARABLE_HPP
