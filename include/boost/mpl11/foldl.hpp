/*!
 * @file
 * Defines `boost::mpl11::foldl`.
 */

#ifndef BOOST_MPL11_FOLDL_HPP
#define BOOST_MPL11_FOLDL_HPP

#include <boost/mpl11/fwd/foldl.hpp>

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/begin.hpp>
#include <boost/mpl11/deref.hpp>
#include <boost/mpl11/end.hpp>
#include <boost/mpl11/equal.hpp>
#include <boost/mpl11/next.hpp>


namespace boost { namespace mpl11 {
    namespace foldl_detail {
        template <
            typename First, typename Last,
            typename State, typename F,
            bool = equal<First, Last>::value
        >
        struct foldl_impl;

        template <typename First, typename Last, typename State, typename F>
        struct foldl_impl<First, Last, State, F, false>
            : foldl_impl<
                typename next<First>::type,
                Last,
                typename apply<
                    F, State, typename deref<First>::type
                >::type,
                F
            >
        { };

        template <typename First, typename Last, typename State, typename F>
        struct foldl_impl<First, Last, State, F, true> {
            using type = State;
        };
    } // end namespace foldl_detail

    template <typename Sequence, typename State, typename F>
    struct foldl
        : foldl_detail::foldl_impl<
            typename begin<Sequence>::type,
            typename end<Sequence>::type,
            State, F
        >
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FOLDL_HPP
