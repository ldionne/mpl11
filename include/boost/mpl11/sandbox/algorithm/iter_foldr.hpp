/*!
 * @file
 * This file defines the `boost::mpl11::iter_foldr` algorithm.
 */

#ifndef BOOST_MPL11_ALGORITHM_ITER_FOLDR_HPP
#define BOOST_MPL11_ALGORITHM_ITER_FOLDR_HPP

#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/eval.hpp>
#include <boost/mpl11/functional/apply_raw.hpp>
#include <boost/mpl11/functional/lambda.hpp>
#include <boost/mpl11/functional/quote.hpp>
#include <boost/mpl11/if.hpp>
#include <boost/mpl11/intrinsic/begin.hpp>
#include <boost/mpl11/intrinsic/end.hpp>
#include <boost/mpl11/intrinsic/next.hpp>
#include <boost/mpl11/is_same.hpp>


namespace boost { namespace mpl11 {
namespace iter_foldr_detail {
    template <typename First, typename Last, typename State, typename BinaryOp>
    struct iter_default_impl
        : if_<is_same<First, Last>,
            State,
            eval<apply_raw<
                BinaryOp,
                eval<iter_default_impl<
                    eval<next<First>>, Last, State, BinaryOp
                >>,
                First
            >>
        >
    { };

    template <typename Sequence, typename State, typename BinaryOp>
    struct default_impl
        : iter_default_impl<
            typename begin<Sequence>::type,
            typename end<Sequence>::type,
            State,
            typename lambda<BinaryOp>::type
        >
    { };
} // end namespace iter_foldr_detail

namespace algorithm {
    struct iter_foldr : detail::tag_dispatched<iter_foldr> {
        struct mpl11 {
            using default_implementation = quote<
                iter_foldr_detail::default_impl
            >;
        };
    };
}

template <typename Sequence, typename State, typename BinaryOp>
struct iter_foldr
    : apply_raw<algorithm::iter_foldr, Sequence, State, BinaryOp>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ALGORITHM_ITER_FOLDR_HPP
