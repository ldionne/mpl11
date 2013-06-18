/*!
 * @file
 * This file defines the `boost::mpl11::iter_fold` algorithm.
 */

#ifndef BOOST_MPL11_ALGORITHM_ITER_FOLD_HPP
#define BOOST_MPL11_ALGORITHM_ITER_FOLD_HPP

#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/eval.hpp>
#include <boost/mpl11/functional_fwd.hpp>
#include <boost/mpl11/if.hpp>
#include <boost/mpl11/intrinsic_fwd.hpp>
#include <boost/mpl11/is_same.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
namespace iter_fold_detail {
    template <typename First, typename Last, typename State, typename BinaryOp>
    struct iter_fold_impl
        : if_<is_same<First, Last>,
            State,
            eval<iter_fold_impl<
                eval<next<First>>, Last,
                eval<apply_raw<BinaryOp, State, First>>,
                BinaryOp
            >>
        >
    { };
}

namespace algorithm {
    struct iter_fold : detail::tag_dispatched<iter_fold> {
        struct mpl11 {
            struct default_implementation {
                template <typename Sequence, typename State, typename BinaryOp>
                struct apply
                    : iter_fold_detail::iter_fold_impl<
                        typename begin<Sequence>::type,
                        typename end<Sequence>::type,
                        State,
                        typename lambda<BinaryOp>::type
                    >
                { };
            };
        };
    };
}

template <typename Sequence, typename State, typename BinaryOp>
struct iter_fold
    : apply_raw<algorithm::iter_fold, Sequence, State, BinaryOp>
{ };
}}}


#include <boost/mpl11/functional/apply_raw.hpp>
#include <boost/mpl11/functional/lambda.hpp>
#include <boost/mpl11/intrinsic/begin.hpp>
#include <boost/mpl11/intrinsic/end.hpp>
#include <boost/mpl11/intrinsic/next.hpp>

#endif // !BOOST_MPL11_ALGORITHM_ITER_FOLD_HPP
