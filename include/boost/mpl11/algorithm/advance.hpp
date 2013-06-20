/*!
 * @file
 * This file defines the `boost::mpl11::advance` algorithm.
 */

#ifndef BOOST_MPL11_ALGORITHM_ADVANCE_HPP
#define BOOST_MPL11_ALGORITHM_ADVANCE_HPP

#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/eval.hpp>
#include <boost/mpl11/functional/apply_raw.hpp>
#include <boost/mpl11/functional/quote.hpp>
#include <boost/mpl11/if.hpp>
#include <boost/mpl11/intrinsic/next.hpp>
#include <boost/mpl11/intrinsic/prior.hpp>
#include <boost/mpl11/trait/is_bidirectional_iterator.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
namespace advance_detail {
    template <template <typename ...> class NextIter,
              template <typename ...> class PrevN,
              typename Iterator,
              typename N>
    struct move_impl
        : if_c<N::value == 0,
            Iterator,
            eval<move_impl<
                NextIter, PrevN, eval<NextIter<Iterator>>, eval<PrevN<N>>
            >>
        >
    { };

    template <typename Iterator, typename N>
    struct fwd_impl : move_impl<next, prior, Iterator, N> {
        static_assert(N::value >= 0,
        "negative distance provided to `advance` with a forward iterator");
    };

    template <typename Iterator, typename N>
    struct bidir_impl
        : if_c<N::value < 0,
            move_impl<prior, next, Iterator, N>,
            move_impl<next, prior, Iterator, N>
        >::type
    { };

    template <typename Iterator, typename N>
    struct default_impl
        : if_<trait::is_bidirectional_iterator<Iterator>,
            bidir_impl<Iterator, N>,
            fwd_impl<Iterator, N>
        >::type
    { };
} // end namespace advance_detail

namespace algorithm {
    struct advance : detail::tag_dispatched<advance> {
        struct mpl11 {
            using default_implementation = quote<advance_detail::default_impl>;
        };
    };
}

template <typename Iterator, typename N>
struct advance
    : apply_raw<algorithm::advance, Iterator, N>
{ };
}}}

#endif // !BOOST_MPL11_ALGORITHM_ADVANCE_HPP
