/*!
 * @file
 * This file defines the `boost::mpl11::foldr` algorithm.
 */

#ifndef BOOST_MPL11_ALGORITHM_FOLDR_HPP
#define BOOST_MPL11_ALGORITHM_FOLDR_HPP

#include <boost/mpl11/algorithm/iter_foldr.hpp>
#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/functional/apply.hpp>
#include <boost/mpl11/functional/apply_raw.hpp>
#include <boost/mpl11/functional/placeholders.hpp>
#include <boost/mpl11/functional/quote.hpp>
#include <boost/mpl11/intrinsic/deref.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
namespace foldr_detail {
    template <typename Sequence, typename State, typename BinaryOp>
    struct default_impl
        : iter_foldr<
            Sequence, State, apply<BinaryOp, State, deref<_1>>
        >
    { };
}

namespace algorithm {
    struct foldr : detail::tag_dispatched<foldr> {
        struct mpl11 {
            using default_implementation = quote<foldr_detail::default_impl>;
        };
    };
}

template <typename Sequence, typename State, typename BinaryOp>
struct foldr
    : apply_raw<algorithm::foldr, Sequence, State, BinaryOp>
{ };
}}}

#endif // !BOOST_MPL11_ALGORITHM_FOLDR_HPP
