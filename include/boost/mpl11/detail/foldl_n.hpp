/*!
 * @file
 * Defines `boost::mpl11::detail::foldl_n`.
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

#ifndef BOOST_MPL11_DETAIL_FOLDL_N_HPP
#define BOOST_MPL11_DETAIL_FOLDL_N_HPP

#include <boost/mpl11/detail/std_size_t.hpp>
#include <boost/mpl11/fwd/iterable.hpp>


namespace boost { namespace mpl11 { namespace detail {
namespace foldl_n_detail {
    

    template <std_size_t n, typename f, typename state, typename xs>
    struct impl {
        using left = impl<
            (n - 6)/2,
            f,
            typename f::type::template apply<typename f::type::template apply<typename f::type::template apply<typename f::type::template apply<typename f::type::template apply<typename f::type::template apply<state, head<xs>>, head<tail<xs>>>, head<tail<tail<xs>>>>, head<tail<tail<tail<xs>>>>>, head<tail<tail<tail<tail<xs>>>>>>, head<tail<tail<tail<tail<tail<xs>>>>>>>,
            tail<tail<tail<tail<tail<tail<xs>>>>>>
        >;
        using right = impl<
            (n - 6) - (n - 6)/2,
            f,
            typename left::result,
            typename left::rest
        >;

        using rest = typename right::rest;
        using result = typename right::result;
    };

    
        template <typename f, typename state, typename xs>
        struct impl<0, f, state, xs> {
            using rest = xs;
            using result = state;
        };
    
        template <typename f, typename state, typename xs>
        struct impl<1, f, state, xs> {
            using rest = tail<xs>;
            using result = typename f::type::template apply<state, head<xs>>;
        };
    
        template <typename f, typename state, typename xs>
        struct impl<2, f, state, xs> {
            using rest = tail<tail<xs>>;
            using result = typename f::type::template apply<typename f::type::template apply<state, head<xs>>, head<tail<xs>>>;
        };
    
        template <typename f, typename state, typename xs>
        struct impl<3, f, state, xs> {
            using rest = tail<tail<tail<xs>>>;
            using result = typename f::type::template apply<typename f::type::template apply<typename f::type::template apply<state, head<xs>>, head<tail<xs>>>, head<tail<tail<xs>>>>;
        };
    
        template <typename f, typename state, typename xs>
        struct impl<4, f, state, xs> {
            using rest = tail<tail<tail<tail<xs>>>>;
            using result = typename f::type::template apply<typename f::type::template apply<typename f::type::template apply<typename f::type::template apply<state, head<xs>>, head<tail<xs>>>, head<tail<tail<xs>>>>, head<tail<tail<tail<xs>>>>>;
        };
    
        template <typename f, typename state, typename xs>
        struct impl<5, f, state, xs> {
            using rest = tail<tail<tail<tail<tail<xs>>>>>;
            using result = typename f::type::template apply<typename f::type::template apply<typename f::type::template apply<typename f::type::template apply<typename f::type::template apply<state, head<xs>>, head<tail<xs>>>, head<tail<tail<xs>>>>, head<tail<tail<tail<xs>>>>>, head<tail<tail<tail<tail<xs>>>>>>;
        };
    
} // end namespace foldl_n_detail

/*!
 * @ingroup details
 *
 * Left fold stopping after `n` steps.
 */
template <std_size_t n, typename f, typename state, typename xs>
using foldl_n = typename foldl_n_detail::impl<n, f, state, xs>::result;
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_FOLDL_N_HPP
