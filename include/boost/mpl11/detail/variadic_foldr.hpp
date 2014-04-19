/*!
 * @file
 * Defines `boost::mpl11::detail::variadic_foldr`.
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

#ifndef BOOST_MPL11_DETAIL_VARIADIC_FOLDR_HPP
#define BOOST_MPL11_DETAIL_VARIADIC_FOLDR_HPP

namespace boost { namespace mpl11 { namespace detail {


/*!
 * @ingroup details
 *
 * Right fold over a parameter pack.
 */
template <typename f, typename state, typename ...xs>
struct variadic_foldr;

template <typename f, typename state , typename x0, typename x1, typename x2, typename x3, typename x4, typename x5, typename ...xs>
struct variadic_foldr<f, state , x0, x1, x2, x3, x4, x5, xs...>
    :  f::type::template apply<x0, typename f::type::template apply<x1, typename f::type::template apply<x2, typename f::type::template apply<x3, typename f::type::template apply<x4, typename f::type::template apply<x5, variadic_foldr<f, state, xs...>>>>>>>
{ };


    template <typename f, typename state  >
    struct variadic_foldr<f, state  >
        : state
    { };

    template <typename f, typename state , typename x0 >
    struct variadic_foldr<f, state , x0 >
        :  f::type::template apply<x0, state>
    { };

    template <typename f, typename state , typename x0, typename x1 >
    struct variadic_foldr<f, state , x0, x1 >
        :  f::type::template apply<x0, typename f::type::template apply<x1, state>>
    { };

    template <typename f, typename state , typename x0, typename x1, typename x2 >
    struct variadic_foldr<f, state , x0, x1, x2 >
        :  f::type::template apply<x0, typename f::type::template apply<x1, typename f::type::template apply<x2, state>>>
    { };

    template <typename f, typename state , typename x0, typename x1, typename x2, typename x3 >
    struct variadic_foldr<f, state , x0, x1, x2, x3 >
        :  f::type::template apply<x0, typename f::type::template apply<x1, typename f::type::template apply<x2, typename f::type::template apply<x3, state>>>>
    { };

    template <typename f, typename state , typename x0, typename x1, typename x2, typename x3, typename x4 >
    struct variadic_foldr<f, state , x0, x1, x2, x3, x4 >
        :  f::type::template apply<x0, typename f::type::template apply<x1, typename f::type::template apply<x2, typename f::type::template apply<x3, typename f::type::template apply<x4, state>>>>>
    { };

}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_VARIADIC_FOLDR_HPP
