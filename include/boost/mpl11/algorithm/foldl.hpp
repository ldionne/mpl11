/*!
 * @file
 * This file defines the `boost::mpl11::foldl` algorithm.
 */

#ifndef BOOST_MPL11_ALGORITHM_FOLDL_HPP
#define BOOST_MPL11_ALGORITHM_FOLDL_HPP

#include <boost/mpl11/algorithm/iter_foldl.hpp>
#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/functional/apply_raw.hpp>
#include <boost/mpl11/functional/lambda.hpp>
#include <boost/mpl11/functional/quote.hpp>
#include <boost/mpl11/intrinsic/deref.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
namespace foldl_detail {
    // Don't use lambda expressions here! foldl is required for
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
    struct default_impl
        : iter_foldl<
            Sequence,
            State,
            deref_2nd_apply_raw<typename lambda<BinaryOp>::type>
        >
    { };
}

namespace algorithm {
    struct foldl : detail::tag_dispatched<foldl> {
        struct mpl11 {
            using default_implementation = quote<foldl_detail::default_impl>;
        };
    };
}

template <typename Sequence, typename State, typename BinaryOp>
struct foldl
    : apply_raw<algorithm::foldl, Sequence, State, BinaryOp>
{ };
}}}

#endif // !BOOST_MPL11_ALGORITHM_FOLDL_HPP
