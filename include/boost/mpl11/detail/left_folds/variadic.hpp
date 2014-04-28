/*!
 * @file
 * Defines `boost::mpl11::detail::left_folds::variadic`.
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

#ifndef BOOST_MPL11_DETAIL_LEFT_FOLDS_VARIADIC_HPP
#define BOOST_MPL11_DETAIL_LEFT_FOLDS_VARIADIC_HPP

namespace boost { namespace mpl11 { namespace detail { namespace left_folds {


/*!
 * @ingroup details
 *
 * Left fold over a parameter pack.
 *
 * The metafunction is unlifted for performance.
 */
template <template <typename ...> class f, typename state, typename ...xs>
struct variadic;

template <
    template <typename ...> class f,
    typename state
    , typename x0, typename x1, typename x2, typename x3, typename x4, typename x5,
    typename ...xs>
struct variadic<f, state , x0, x1, x2, x3, x4, x5, xs...>
    : variadic<
        f,
        f<f<f<f<f<f<state, x0>, x1>, x2>, x3>, x4>, x5>,
        xs...
    >
{ };


    template <
        template <typename ...> class f,
        typename state
        
    >
    struct variadic<f, state  >
        : state
    { };

    template <
        template <typename ...> class f,
        typename state
        , typename x0
    >
    struct variadic<f, state , x0 >
        : f<state, x0>
    { };

    template <
        template <typename ...> class f,
        typename state
        , typename x0, typename x1
    >
    struct variadic<f, state , x0, x1 >
        : f<f<state, x0>, x1>
    { };

    template <
        template <typename ...> class f,
        typename state
        , typename x0, typename x1, typename x2
    >
    struct variadic<f, state , x0, x1, x2 >
        : f<f<f<state, x0>, x1>, x2>
    { };

    template <
        template <typename ...> class f,
        typename state
        , typename x0, typename x1, typename x2, typename x3
    >
    struct variadic<f, state , x0, x1, x2, x3 >
        : f<f<f<f<state, x0>, x1>, x2>, x3>
    { };

    template <
        template <typename ...> class f,
        typename state
        , typename x0, typename x1, typename x2, typename x3, typename x4
    >
    struct variadic<f, state , x0, x1, x2, x3, x4 >
        : f<f<f<f<f<state, x0>, x1>, x2>, x3>, x4>
    { };

}}}} // end namespace boost::mpl11::detail::left_folds

#endif // !BOOST_MPL11_DETAIL_LEFT_FOLDS_VARIADIC_HPP
