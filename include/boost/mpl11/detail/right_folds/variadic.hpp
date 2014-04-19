/*!
 * @file
 * Defines `boost::mpl11::detail::right_folds::variadic`.
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

#ifndef BOOST_MPL11_DETAIL_RIGHT_FOLDS_VARIADIC_HPP
#define BOOST_MPL11_DETAIL_RIGHT_FOLDS_VARIADIC_HPP

namespace boost { namespace mpl11 { namespace detail { namespace right_folds {
    

    /*!
     * @ingroup details
     *
     * Right fold over a parameter pack.
     */
    template <typename f, typename state, typename ...xs>
    struct variadic;

    template <typename f, typename state , typename x0, typename x1, typename x2, typename x3, typename x4, typename x5, typename ...xs>
    struct variadic<f, state , x0, x1, x2, x3, x4, x5, xs...>
        :  f::type::template apply<x0, typename f::type::template apply<x1, typename f::type::template apply<x2, typename f::type::template apply<x3, typename f::type::template apply<x4, typename f::type::template apply<x5, variadic<f, state, xs...>>>>>>>
    { };

    
        template <typename f, typename state  >
        struct variadic<f, state  >
            : state
        { };
    
        template <typename f, typename state , typename x0 >
        struct variadic<f, state , x0 >
            :  f::type::template apply<x0, state>
        { };
    
        template <typename f, typename state , typename x0, typename x1 >
        struct variadic<f, state , x0, x1 >
            :  f::type::template apply<x0, typename f::type::template apply<x1, state>>
        { };
    
        template <typename f, typename state , typename x0, typename x1, typename x2 >
        struct variadic<f, state , x0, x1, x2 >
            :  f::type::template apply<x0, typename f::type::template apply<x1, typename f::type::template apply<x2, state>>>
        { };
    
        template <typename f, typename state , typename x0, typename x1, typename x2, typename x3 >
        struct variadic<f, state , x0, x1, x2, x3 >
            :  f::type::template apply<x0, typename f::type::template apply<x1, typename f::type::template apply<x2, typename f::type::template apply<x3, state>>>>
        { };
    
        template <typename f, typename state , typename x0, typename x1, typename x2, typename x3, typename x4 >
        struct variadic<f, state , x0, x1, x2, x3, x4 >
            :  f::type::template apply<x0, typename f::type::template apply<x1, typename f::type::template apply<x2, typename f::type::template apply<x3, typename f::type::template apply<x4, state>>>>>
        { };
    
}}}} // end namespace boost::mpl11::detail::right_folds

#endif // !BOOST_MPL11_DETAIL_RIGHT_FOLDS_VARIADIC_HPP
