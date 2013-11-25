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
#include <boost/mpl11/detail/tp_conditional.hpp>
#include <boost/mpl11/end.hpp>
#include <boost/mpl11/equal.hpp>
#include <boost/mpl11/has_optimization.hpp>
#include <boost/mpl11/next.hpp>
#include <boost/mpl11/optimization.hpp>
#include <boost/mpl11/size.hpp>


namespace boost { namespace mpl11 {
    namespace foldl_detail {
        //! @todo Unroll this with a script.
        template <
            unsigned long long Size, typename Iter, typename State, typename F
        >
        struct unrolled_foldl_impl
            : unrolled_foldl_impl<
                Size - 1,
                next_t<Iter>,
                apply_t<F, State, deref_t<Iter>>,
                F
            >
        { };

        template <typename Iter, typename State, typename F>
        struct unrolled_foldl_impl<0, Iter, State, F> {
            using type = State;
        };

        template <typename Sequence, typename State, typename F>
        struct unrolled_foldl
            : unrolled_foldl_impl<
                size<Sequence>::value,
                begin_t<Sequence>,
                State, F
            >
        { };

        template <
            typename First, typename Last,
            typename State, typename F,
            bool = equal<First, Last>::value
        >
        struct normal_foldl_impl;

        template <typename First, typename Last, typename State, typename F>
        struct normal_foldl_impl<First, Last, State, F, false>
            : normal_foldl_impl<
                next_t<First>,
                Last,
                apply_t<F, State, deref_t<First>>,
                F
            >
        { };

        template <typename First, typename Last, typename State, typename F>
        struct normal_foldl_impl<First, Last, State, F, true> {
            using type = State;
        };

        template <typename Sequence, typename State, typename F>
        struct normal_foldl
            : normal_foldl_impl<
                begin_t<Sequence>,
                end_t<Sequence>,
                State, F
            >
        { };
    } // end namespace foldl_detail

    template <typename Sequence, typename State, typename F>
    struct foldl
        : detail::tp_conditional<
            has_optimization<Sequence, optimization::O1_size>::value,
            foldl_detail::unrolled_foldl,
            foldl_detail::normal_foldl
        >::template type<Sequence, State, F>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FOLDL_HPP
