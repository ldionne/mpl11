/*!
 * @file
 * Defines `boost::mpl11::foldr`.
 */

#ifndef BOOST_MPL11_FOLDR_HPP
#define BOOST_MPL11_FOLDR_HPP

#include <boost/mpl11/fwd/foldr.hpp>

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/begin.hpp>
#include <boost/mpl11/deref.hpp>
#include <boost/mpl11/end.hpp>
#include <boost/mpl11/equal.hpp>
#include <boost/mpl11/next.hpp>


namespace boost { namespace mpl11 {
    namespace foldr_detail {
        template <
            typename First, typename Last,
            typename State, typename F,
            bool = equal<First, Last>::value
        >
        struct foldr_impl;

        template <typename First, typename Last, typename State, typename F>
        struct foldr_impl<First, Last, State, F, false>
            : apply<
                F,
                typename foldr_impl<
                    next_t<First>, Last, State, F
                >::type,
                deref_t<First>
            >
        { };

        template <typename First, typename Last, typename State, typename F>
        struct foldr_impl<First, Last, State, F, true> {
            using type = State;
        };
    } // end namespace foldr_detail

    //! @todo
    //! Optimize `foldr` like `foldl`. We might be able to share some
    //! implementation details.
    template <typename Sequence, typename State, typename F>
    struct foldr
        : foldr_detail::foldr_impl<
            begin_t<Sequence>,
            end_t<Sequence>,
            State, F
        >
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FOLDR_HPP
