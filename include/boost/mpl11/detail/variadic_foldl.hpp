/*!
 * @file
 * Defines `boost::mpl11::detail::variadic_foldl`.
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

#ifndef BOOST_MPL11_DETAIL_VARIADIC_FOLDL_HPP
#define BOOST_MPL11_DETAIL_VARIADIC_FOLDL_HPP

namespace boost { namespace mpl11 { namespace detail {


/*!
 * @ingroup details
 *
 * Left fold over a parameter pack.
 */
template <typename f, typename state, typename ...xs>
struct variadic_foldl;

template <typename f, typename state , typename x0, typename x1, typename x2, typename x3, typename x4, typename x5, typename ...xs>
struct variadic_foldl<f, state , x0, x1, x2, x3, x4, x5, xs...>
    : variadic_foldl<
        f,
        typename f::type::template apply<typename f::type::template apply<typename f::type::template apply<typename f::type::template apply<typename f::type::template apply<typename f::type::template apply<state, x0>, x1>, x2>, x3>, x4>, x5>,
        xs...
    >
{ };


    template <typename f, typename state  >
    struct variadic_foldl<f, state  >
        : state
    { };

    template <typename f, typename state , typename x0 >
    struct variadic_foldl<f, state , x0 >
        :  f::type::template apply<state, x0>
    { };

    template <typename f, typename state , typename x0, typename x1 >
    struct variadic_foldl<f, state , x0, x1 >
        :  f::type::template apply<typename f::type::template apply<state, x0>, x1>
    { };

    template <typename f, typename state , typename x0, typename x1, typename x2 >
    struct variadic_foldl<f, state , x0, x1, x2 >
        :  f::type::template apply<typename f::type::template apply<typename f::type::template apply<state, x0>, x1>, x2>
    { };

    template <typename f, typename state , typename x0, typename x1, typename x2, typename x3 >
    struct variadic_foldl<f, state , x0, x1, x2, x3 >
        :  f::type::template apply<typename f::type::template apply<typename f::type::template apply<typename f::type::template apply<state, x0>, x1>, x2>, x3>
    { };

    template <typename f, typename state , typename x0, typename x1, typename x2, typename x3, typename x4 >
    struct variadic_foldl<f, state , x0, x1, x2, x3, x4 >
        :  f::type::template apply<typename f::type::template apply<typename f::type::template apply<typename f::type::template apply<typename f::type::template apply<state, x0>, x1>, x2>, x3>, x4>
    { };

}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_VARIADIC_FOLDL_HPP
