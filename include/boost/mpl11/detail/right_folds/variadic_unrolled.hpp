/*!
 * @file
 * Defines `boost::mpl11::detail::right_folds::variadic_unrolled`.
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

#ifndef BOOST_MPL11_DETAIL_RIGHT_FOLDS_VARIADIC_UNROLLED_HPP
#define BOOST_MPL11_DETAIL_RIGHT_FOLDS_VARIADIC_UNROLLED_HPP

namespace boost { namespace mpl11 { namespace detail { namespace right_folds {
    

    /*!
     * @ingroup details
     *
     * Right fold over a parameter pack with loop unrolling.
     *
     * The metafunction is unlifted for performance.
     */
    template <template <typename ...> class f, typename state, typename ...xs>
    struct variadic_unrolled;

    template <
        template <typename ...> class f,
        typename state
        , typename x0, typename x1, typename x2, typename x3, typename x4, typename x5,
        typename ...xs>
    struct variadic_unrolled<f, state , x0, x1, x2, x3, x4, x5, xs...>
        : f<x0, f<x1, f<x2, f<x3, f<x4, f<x5, variadic_unrolled<f, state, xs...>>>>>>>
    { };

    
        template <
            template <typename ...> class f,
            typename state
            
        >
        struct variadic_unrolled<f, state  >
            : state
        { };
    
        template <
            template <typename ...> class f,
            typename state
            , typename x0
        >
        struct variadic_unrolled<f, state , x0 >
            : f<x0, state>
        { };
    
        template <
            template <typename ...> class f,
            typename state
            , typename x0, typename x1
        >
        struct variadic_unrolled<f, state , x0, x1 >
            : f<x0, f<x1, state>>
        { };
    
        template <
            template <typename ...> class f,
            typename state
            , typename x0, typename x1, typename x2
        >
        struct variadic_unrolled<f, state , x0, x1, x2 >
            : f<x0, f<x1, f<x2, state>>>
        { };
    
        template <
            template <typename ...> class f,
            typename state
            , typename x0, typename x1, typename x2, typename x3
        >
        struct variadic_unrolled<f, state , x0, x1, x2, x3 >
            : f<x0, f<x1, f<x2, f<x3, state>>>>
        { };
    
        template <
            template <typename ...> class f,
            typename state
            , typename x0, typename x1, typename x2, typename x3, typename x4
        >
        struct variadic_unrolled<f, state , x0, x1, x2, x3, x4 >
            : f<x0, f<x1, f<x2, f<x3, f<x4, state>>>>>
        { };
    
}}}} // end namespace boost::mpl11::detail::right_folds

#endif // !BOOST_MPL11_DETAIL_RIGHT_FOLDS_VARIADIC_UNROLLED_HPP
