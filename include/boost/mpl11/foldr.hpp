/*!
 * @file
 * Defines `boost::mpl11::foldr`.
 */

#ifndef BOOST_MPL11_FOLDR_HPP
#define BOOST_MPL11_FOLDR_HPP

#include <boost/mpl11/fwd/foldr.hpp>

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/fwd/sequence.hpp>


namespace boost { namespace mpl11 {
    namespace foldr_detail {
        template <typename F, typename State, typename S,
            bool = is_empty<S>::value
        >
        struct foldr_impl;

        template <typename F, typename State, typename S>
        struct foldr_impl<F, State, S, false> {
            using type = typename apply<
                F,
                typename head<S>::type,
                typename foldr_impl<F, State ,typename tail<S>::type>::type
            >::type;
        };

        template <typename F, typename State, typename S>
        struct foldr_impl<F, State, S, true> {
            using type = State;
        };
    } // end namespace foldr_detail

    template <typename F, typename State, typename S>
    struct foldr
        : foldr_detail::foldr_impl<F, State, S>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FOLDR_HPP
