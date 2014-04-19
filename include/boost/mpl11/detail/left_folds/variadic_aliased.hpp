/*!
 * @file
 * Defines `boost::mpl11::detail::left_folds::variadic_aliased`.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

//////////////////////////////////////////////////////////////////////////
// GENERATED HEADER: DO NOT EDIT.
//////////////////////////////////////////////////////////////////////////

#ifndef BOOST_MPL11_DETAIL_LEFT_FOLDS_VARIADIC_ALIASED_HPP
#define BOOST_MPL11_DETAIL_LEFT_FOLDS_VARIADIC_ALIASED_HPP

#include <boost/mpl11/detail/std_size_t.hpp>


namespace boost { namespace mpl11 { namespace detail { namespace left_folds {
    

    template <std_size_t n>
    struct variadic_aliased_impl;

    template <>
    struct variadic_aliased_impl<    6   > {
        template <typename f, typename state , typename x1, typename x2, typename x3, typename x4, typename x5, typename x6, typename ...xs>
        using apply =
            typename variadic_aliased_impl<  (sizeof...(xs) > 6 ? 6 : sizeof...(xs))    >::template apply<
                f,
                typename f::type::template apply<typename f::type::template apply<typename f::type::template apply<typename f::type::template apply<typename f::type::template apply<typename f::type::template apply<state, x1>, x2>, x3>, x4>, x5>, x6>,
                xs...
            >;
    };

    
        template <>
        struct variadic_aliased_impl<    0    > {
            template <typename f, typename state >
            using apply = state;
        };
    
        template <>
        struct variadic_aliased_impl<    1    > {
            template <typename f, typename state , typename x1>
            using apply = typename f::type::template apply<state, x1>;
        };
    
        template <>
        struct variadic_aliased_impl<    2    > {
            template <typename f, typename state , typename x1, typename x2>
            using apply = typename f::type::template apply<typename f::type::template apply<state, x1>, x2>;
        };
    
        template <>
        struct variadic_aliased_impl<    3    > {
            template <typename f, typename state , typename x1, typename x2, typename x3>
            using apply = typename f::type::template apply<typename f::type::template apply<typename f::type::template apply<state, x1>, x2>, x3>;
        };
    
        template <>
        struct variadic_aliased_impl<    4    > {
            template <typename f, typename state , typename x1, typename x2, typename x3, typename x4>
            using apply = typename f::type::template apply<typename f::type::template apply<typename f::type::template apply<typename f::type::template apply<state, x1>, x2>, x3>, x4>;
        };
    
        template <>
        struct variadic_aliased_impl<    5    > {
            template <typename f, typename state , typename x1, typename x2, typename x3, typename x4, typename x5>
            using apply = typename f::type::template apply<typename f::type::template apply<typename f::type::template apply<typename f::type::template apply<typename f::type::template apply<state, x1>, x2>, x3>, x4>, x5>;
        };
    

    /*!
     * @ingroup details
     *
     * Recursive alias-based variadic left fold.
     */
    template <typename f, typename state, typename ...xs>
    struct variadic_aliased
        : variadic_aliased_impl<    (sizeof...(xs) > 6 ? 6 : sizeof...(xs))     >::
          template apply<f, state, xs...>
    { };
}}}} // end namespace boost::mpl11::detail::left_folds

#endif // !BOOST_MPL11_DETAIL_LEFT_FOLDS_VARIADIC_ALIASED_HPP
