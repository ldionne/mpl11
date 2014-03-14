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

#include <boost/mpl11/fwd/core.hpp>
#include <boost/mpl11/fwd/logical.hpp>


namespace boost { namespace mpl11 {
    template <>
    struct instantiate<Orderable> {
        template <typename Left, typename Right = Left>
        struct with {
            template <typename x, typename y>
            using less_equal_impl = not_<less<y, x>>;

            template <typename x, typename y>
            using greater_impl = less<y, x>;

            template <typename x, typename y>
            using greater_equal_impl = not_<less<x, y>>;

            template <typename x, typename y>
            using min_impl = if_c<less<x, y>::value, x, y>;

            template <typename x, typename y>
            using max_impl = if_c<less<x, y>::value, y, x>;
        };
    };
}} // end namespace boost::mpl11


#include <boost/mpl11/core.hpp>
#include <boost/mpl11/detail/common_method.hpp>
#include <boost/mpl11/detail/strict_variadic_foldl.hpp>
#include <boost/mpl11/functional.hpp>
#include <boost/mpl11/logical.hpp>


namespace boost { namespace mpl11 {
    template <typename Left, typename Right, typename>
    struct Orderable {
    private:
        using Common = Orderable<typename common_datatype<Left, Right>::type>;

    public:
        template <typename x, typename y>
        using less_impl =
            typename detail::common_method<Left, Right>::
            template apply<Common::template less_impl, x, y>;

        template <typename x, typename y>
        using less_equal_impl =
            typename detail::common_method<Left, Right>::
            template apply<Common::template less_equal_impl, x, y>;

        template <typename x, typename y>
        using greater_impl =
            typename detail::common_method<Left, Right>::
            template apply<Common::template greater_impl, x, y>;

        template <typename x, typename y>
        using greater_equal_impl =
            typename detail::common_method<Left, Right>::
            template apply<Common::template greater_equal_impl, x, y>;

        template <typename x, typename y>
        using min_impl =
            typename detail::common_method<Left, Right>::
            template apply<Common::template min_impl, x, y>;

        template <typename x, typename y>
        using max_impl =
            typename detail::common_method<Left, Right>::
            template apply<Common::template max_impl, x, y>;
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
        >::template less_impl<x, y>
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
        >::template less_equal_impl<x, y>
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
        >::template greater_impl<x, y>
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
        >::template greater_equal_impl<x, y>
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
        >::template min_impl<x, y>
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
        >::template max_impl<x, y>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ORDERABLE_HPP
