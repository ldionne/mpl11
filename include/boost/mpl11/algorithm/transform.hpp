/*!
 * @file
 * This file defines the `boost::mpl11::transform` algorithm.
 */

#ifndef BOOST_MPL11_ALGORITHM_TRANSFORM_HPP
#define BOOST_MPL11_ALGORITHM_TRANSFORM_HPP

#include <boost/mpl11/algorithm/fold.hpp>
#include <boost/mpl11/functional/apply_raw.hpp>
#include <boost/mpl11/functional/bind.hpp>
#include <boost/mpl11/functional/lambda.hpp>
#include <boost/mpl11/functional/placeholders.hpp>
#include <boost/mpl11/functional/quote.hpp>


namespace boost { namespace mpl11 {
namespace transform_detail {
    template <typename Sequence, typename F, typename Inserter>
    struct default_impl
        : fold<
            Sequence,
            typename Inserter::state,
            bind<
                typename lambda<typename Inserter::operation>::type,
                _1,
                bind<typename lambda<F>::type, _2>
            >
        >
    { };
} // end namespace transform_detail

namespace algorithm {
    struct transform : detail::tag_dispatched<transform> {
        struct mpl11 {
            using default_implementation = quote<
                transform_detail::default_impl
            >;
        };
    };
}

template <typename Sequence, typename F, typename Inserter>
struct transform
    : apply_raw<algorithm::transform, Sequence, F, Inserter>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ALGORITHM_TRANSFORM_HPP
