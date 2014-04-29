/*!
 * @file
 * Defines `boost::mpl11::detail::left_folds::until`.
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

#ifndef BOOST_MPL11_DETAIL_LEFT_FOLDS_UNTIL_HPP
#define BOOST_MPL11_DETAIL_LEFT_FOLDS_UNTIL_HPP

#include <boost/mpl11/fwd/iterable.hpp>


namespace boost { namespace mpl11 { namespace detail { namespace left_folds {
    template <
        template <typename ...> class pred,
        template <typename ...> class f,
        typename z,
        typename xs,
        template <typename ...> class head,
        template <typename ...> class tail,
        bool = pred<xs>::type::value
    >
    struct single_step;

    template <
        template <typename ...> class pred,
        template <typename ...> class f,
        typename z,
        typename xs,
        template <typename ...> class head,
        template <typename ...> class tail
    >
    struct single_step<pred, f, z, xs, head, tail, true> {
        using next = xs;
        using state = z;
    };

    template <
        template <typename ...> class pred,
        template <typename ...> class f,
        typename z,
        typename xs,
        template <typename ...> class head,
        template <typename ...> class tail
    >
    struct single_step<pred, f, z, xs, head, tail, false> {
        using next = tail<xs>;
        using state = f<z, head<xs>>;
    };

    template <
        template <typename ...> class pred,
        template <typename ...> class f,
        typename z,
        typename xs,
        template <typename ...> class head,
        template <typename ...> class tail,
        bool = pred<xs>::type::value
    >
    struct multi_step;

    template <
        template <typename ...> class pred,
        template <typename ...> class f,
        typename z,
        typename xs,
        template <typename ...> class head,
        template <typename ...> class tail
    >
    struct multi_step<pred, f, z, xs, head, tail, true> {
        using next = xs;
        using state = z;
    };

    

    template <
        template <typename ...> class pred,
        template <typename ...> class f,
        typename z,
        typename xs,
        template <typename ...> class head,
        template <typename ...> class tail
    >
    struct multi_step<pred, f, z, xs, head, tail, false> {
        using state0 = f<z, head<xs>>;
        using next0  = tail<xs>;

        
            using state1 = typename single_step<
                pred, f, state0, next0, head, tail
            >::state;

            using next1 = typename single_step<
                pred, f, state0, next0, head, tail
            >::next;
        
            using state2 = typename single_step<
                pred, f, state1, next1, head, tail
            >::state;

            using next2 = typename single_step<
                pred, f, state1, next1, head, tail
            >::next;
        
            using state3 = typename single_step<
                pred, f, state2, next2, head, tail
            >::state;

            using next3 = typename single_step<
                pred, f, state2, next2, head, tail
            >::next;
        
            using state4 = typename single_step<
                pred, f, state3, next3, head, tail
            >::state;

            using next4 = typename single_step<
                pred, f, state3, next3, head, tail
            >::next;
        
            using state5 = typename single_step<
                pred, f, state4, next4, head, tail
            >::state;

            using next5 = typename single_step<
                pred, f, state4, next4, head, tail
            >::next;
        

        using next = typename multi_step<
            pred, f, state5, next5, head, tail
        >::next;

        using state = typename multi_step<
            pred, f, state5, next5, head, tail
        >::state;
    };

    /*!
     * @ingroup details
     *
     * Left fold stopping whenever the `predicate` returns true.
     *
     * The metafunctions are unlifted for performance reasons.
     */
    template <
        template <typename ...> class predicate,
        template <typename ...> class f,
        typename state,
        typename xs,
        template <typename ...> class head = mpl11::head,
        template <typename ...> class tail = mpl11::tail
    >
    using until = typename multi_step<
        predicate, f, state, xs, head, tail
    >::state;
}}}} // end namespace boost::mpl11::detail::left_folds

#endif // !BOOST_MPL11_DETAIL_LEFT_FOLDS_UNTIL_HPP
