/*!
 * @file
 * Defines `boost::mpl11::detail::left_folds::bounded`.
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

#ifndef BOOST_MPL11_DETAIL_LEFT_FOLDS_BOUNDED_HPP
#define BOOST_MPL11_DETAIL_LEFT_FOLDS_BOUNDED_HPP

#include <boost/mpl11/detail/std_size_t.hpp>
#include <boost/mpl11/fwd/iterable.hpp>


namespace boost { namespace mpl11 { namespace detail { namespace left_folds {
    

    template <
        std_size_t n, template <typename ...> class f,
        typename state, typename xs,
        template <typename ...> class head,
        template <typename ...> class tail>
    struct bounded_impl {
        using left = bounded_impl<
            (n - 6)/2,
            f,
            f<f<f<f<f<f<state, head<xs>>, head<tail<xs>>>, head<tail<tail<xs>>>>, head<tail<tail<tail<xs>>>>>, head<tail<tail<tail<tail<xs>>>>>>, head<tail<tail<tail<tail<tail<xs>>>>>>>,
            tail<tail<tail<tail<tail<tail<xs>>>>>>,
            head, tail
        >;
        using right = bounded_impl<
            (n - 6) - (n - 6)/2,
            f,
            typename left::result,
            typename left::rest,
            head, tail
        >;

        using rest = typename right::rest;
        using result = typename right::result;
    };

    
        template <
            template <typename ...> class f,
            typename state, typename xs,
            template <typename ...> class head,
            template <typename ...> class tail>
        struct bounded_impl<0, f, state, xs, head, tail> {
            using rest = xs;
            using result = state;
        };
    
        template <
            template <typename ...> class f,
            typename state, typename xs,
            template <typename ...> class head,
            template <typename ...> class tail>
        struct bounded_impl<1, f, state, xs, head, tail> {
            using rest = tail<xs>;
            using result = f<state, head<xs>>;
        };
    
        template <
            template <typename ...> class f,
            typename state, typename xs,
            template <typename ...> class head,
            template <typename ...> class tail>
        struct bounded_impl<2, f, state, xs, head, tail> {
            using rest = tail<tail<xs>>;
            using result = f<f<state, head<xs>>, head<tail<xs>>>;
        };
    
        template <
            template <typename ...> class f,
            typename state, typename xs,
            template <typename ...> class head,
            template <typename ...> class tail>
        struct bounded_impl<3, f, state, xs, head, tail> {
            using rest = tail<tail<tail<xs>>>;
            using result = f<f<f<state, head<xs>>, head<tail<xs>>>, head<tail<tail<xs>>>>;
        };
    
        template <
            template <typename ...> class f,
            typename state, typename xs,
            template <typename ...> class head,
            template <typename ...> class tail>
        struct bounded_impl<4, f, state, xs, head, tail> {
            using rest = tail<tail<tail<tail<xs>>>>;
            using result = f<f<f<f<state, head<xs>>, head<tail<xs>>>, head<tail<tail<xs>>>>, head<tail<tail<tail<xs>>>>>;
        };
    
        template <
            template <typename ...> class f,
            typename state, typename xs,
            template <typename ...> class head,
            template <typename ...> class tail>
        struct bounded_impl<5, f, state, xs, head, tail> {
            using rest = tail<tail<tail<tail<tail<xs>>>>>;
            using result = f<f<f<f<f<state, head<xs>>, head<tail<xs>>>, head<tail<tail<xs>>>>, head<tail<tail<tail<xs>>>>>, head<tail<tail<tail<tail<xs>>>>>>;
        };
    

    /*!
     * @ingroup details
     *
     * Left fold stopping after `n` steps.
     *
     * The metafunction is unlifted for performance.
     */
    template <
        std_size_t n,
        template <typename ...> class f,
        typename state,
        typename xs,
        template <typename ...> class head = mpl11::head,
        template <typename ...> class tail = mpl11::tail
    >
    using bounded = typename bounded_impl<n, f, state, xs, head, tail>::result;
}}}} // end namespace boost::mpl11::detail::left_folds

#endif // !BOOST_MPL11_DETAIL_LEFT_FOLDS_BOUNDED_HPP
