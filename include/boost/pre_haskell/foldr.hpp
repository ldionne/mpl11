/*!
 * @file
 * Defines `boost::mpl11::foldr`.
 */

#ifndef BOOST_MPL11_FOLDR_HPP
#define BOOST_MPL11_FOLDR_HPP

#include <boost/mpl11/fwd/foldr.hpp>

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/head.hpp>
#include <boost/mpl11/is_empty.hpp>
#include <boost/mpl11/tail.hpp>


namespace boost { namespace mpl11 {
    namespace foldr_detail {
        template <typename S, typename State, typename F,
            bool = is_empty<S>::value
        >
        struct foldr_impl;

        template <typename S, typename State, typename F>
        struct foldr_impl<S, State, F, false>
            : apply<
                F,
                typename foldr_impl<tail_t<S>, State, F>::type,
                head_t<S>
            >
        { };

        template <typename S, typename State, typename F>
        struct foldr_impl<S, State, F, true> {
            using type = State;
        };
    } // end namespace foldr_detail

    //! @todo
    //! Optimize `foldr` like `foldl`. We might be able to share some
    //! implementation details.
    template <typename Sequence, typename State, typename F>
    struct foldr
        : foldr_detail::foldr_impl<Sequence, State, F>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FOLDR_HPP
