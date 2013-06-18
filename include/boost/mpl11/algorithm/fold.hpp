/*!
 * @file
 * This file defines the `boost::mpl11::fold` algorithm.
 */

#ifndef BOOST_MPL11_ALGORITHM_FOLD_HPP
#define BOOST_MPL11_ALGORITHM_FOLD_HPP

#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/functional_fwd.hpp>
#include <boost/mpl11/intrinsic_fwd.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
namespace fold_detail {
    // Don't use lambda expressions here! fold is required for
    // implementing bind, so that would create a nasty circular
    // dependency.
    template <typename BinaryOp>
    struct deref_2nd_apply_raw {
        template <typename State, typename Iterator>
        struct apply
            : apply_raw<
                BinaryOp, State, typename deref<Iterator>::type
            >
        { };
    };

    template <typename Sequence, typename State, typename BinaryOp>
    struct fold_impl
        : iter_fold<
            Sequence,
            State,
            deref_2nd_apply_raw<typename lambda<BinaryOp>::type>
        >
    { };
}

namespace algorithm {
    struct fold : detail::tag_dispatched<fold> {
        struct mpl11 {
            using default_implementation = quote<fold_detail::fold_impl>;
        };
    };
}

template <typename Sequence, typename State, typename BinaryOp>
struct fold
    : apply_raw<algorithm::fold, Sequence, State, BinaryOp>
{ };
}}}


#include <boost/mpl11/algorithm/iter_fold.hpp>
#include <boost/mpl11/functional/apply_raw.hpp>
#include <boost/mpl11/functional/lambda.hpp>
#include <boost/mpl11/functional/quote.hpp>
#include <boost/mpl11/intrinsic/deref.hpp>

#endif // !BOOST_MPL11_ALGORITHM_FOLD_HPP
