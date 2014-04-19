/*!
 * @file
 * Defines `boost::mpl11::detail::variadic_foldl_alias`.
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

#ifndef BOOST_MPL11_DETAIL_VARIADIC_FOLDL_ALIAS_HPP
#define BOOST_MPL11_DETAIL_VARIADIC_FOLDL_ALIAS_HPP

#include <boost/mpl11/detail/std_size_t.hpp>


namespace boost { namespace mpl11 { namespace detail {
namespace variadic_foldl_alias_detail {
    

    template <std_size_t n>
    struct impl;

    template <>
    struct impl<    6   > {
        template <typename f, typename state , typename x1, typename x2, typename x3, typename x4, typename x5, typename x6, typename ...xs>
        using apply =
            typename impl<  (sizeof...(xs) > 6 ? 6 : sizeof...(xs))    >::template apply<
                f,
                typename f::type::template apply<typename f::type::template apply<typename f::type::template apply<typename f::type::template apply<typename f::type::template apply<typename f::type::template apply<state, x1>, x2>, x3>, x4>, x5>, x6>,
                xs...
            >;
    };

    
        template <>
        struct impl<    0    > {
            template <typename f, typename state >
            using apply = state;
        };
    
        template <>
        struct impl<    1    > {
            template <typename f, typename state , typename x1>
            using apply = typename f::type::template apply<state, x1>;
        };
    
        template <>
        struct impl<    2    > {
            template <typename f, typename state , typename x1, typename x2>
            using apply = typename f::type::template apply<typename f::type::template apply<state, x1>, x2>;
        };
    
        template <>
        struct impl<    3    > {
            template <typename f, typename state , typename x1, typename x2, typename x3>
            using apply = typename f::type::template apply<typename f::type::template apply<typename f::type::template apply<state, x1>, x2>, x3>;
        };
    
        template <>
        struct impl<    4    > {
            template <typename f, typename state , typename x1, typename x2, typename x3, typename x4>
            using apply = typename f::type::template apply<typename f::type::template apply<typename f::type::template apply<typename f::type::template apply<state, x1>, x2>, x3>, x4>;
        };
    
        template <>
        struct impl<    5    > {
            template <typename f, typename state , typename x1, typename x2, typename x3, typename x4, typename x5>
            using apply = typename f::type::template apply<typename f::type::template apply<typename f::type::template apply<typename f::type::template apply<typename f::type::template apply<state, x1>, x2>, x3>, x4>, x5>;
        };
    
} // end namespace variadic_foldl_alias_detail

/*!
 * @ingroup details
 *
 * Recursive alias-based variadic left fold.
 */
template <typename f, typename state, typename ...xs>
struct variadic_foldl_alias
    : variadic_foldl_alias_detail::impl<    (sizeof...(xs) > 6 ? 6 : sizeof...(xs))     >::
      template apply<f, state, xs...>
{ };
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_VARIADIC_FOLDL_ALIAS_HPP
