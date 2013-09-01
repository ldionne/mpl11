/*!
 * @file
 * Defines `boost::mpl11::algorithm::iter_foldl`.
 */

#ifndef BOOST_MPL11_ALGORITHM_ITER_FOLDL_HPP
#define BOOST_MPL11_ALGORITHM_ITER_FOLDL_HPP

#include <boost/mpl11/always.hpp>
#include <boost/mpl11/apply_wrap.hpp>
#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/intrinsic/begin.hpp>
#include <boost/mpl11/intrinsic/end.hpp>
#include <boost/mpl11/intrinsic/equal_to.hpp>
#include <boost/mpl11/intrinsic/next.hpp>
#include <boost/mpl11/lambda.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
namespace iter_foldl_detail {
    template <typename First, typename Last, typename State, typename F,
              bool = intrinsic::equal_to<First, Last>::type::value>
    struct iter_foldl_impl
        : iter_foldl_impl<
            typename intrinsic::next<First>::type,
            Last,
            typename apply_wrap<F, State, First>::type,
            F
        >
    { };

    template <typename First, typename Last, typename State, typename F>
    struct iter_foldl_impl<First, Last, State, F, true>
        : identity<State>
    { };
} // end namespace iter_foldl_detail

namespace algorithm {
    /*!
     * @ingroup algorithm
     *
     * Accumulates the iterators in a range from an initial state using a
     * custom operation.
     *
     * Specifically, returns the result of the successive application of the
     * binary operation `F` to the result of the previous `F` invocation (or
     * `State` for the first application) and each iterator in the range
     * [`begin<Sequence>::type`, `end<Sequence>::type`) in order.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to
       @code
            using Iter1 = begin<Sequence>::type;
            using State1 = apply<F, State, Iter1>::type;

            using Iter2 = next<Iter1>::type;
            using State2 = apply<F, State1, Iter2>::type;

            ...

            using StateN = apply<F, StateN-1, IterN>::type;
            using Last = next<IterN>::type;
            using Result = StateN;
       @endcode
     *
     *
     * @note
     * This is equivalent to the `mpl::iter_fold` metafunction from
     * the original MPL.
     */
    template <typename Sequence, typename State, typename F>
    struct iter_foldl
        : detail::tag_dispatched<tag::iter_foldl, Sequence, State, F>
          ::template with_default<
            lazy_always<
                iter_foldl_detail::iter_foldl_impl<
                    typename intrinsic::begin<Sequence>::type,
                    typename intrinsic::end<Sequence>::type,
                    State,
                    typename lambda<F>::type
                >
            >
          >
    { };
} // end namespace algorithm
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ALGORITHM_ITER_FOLDL_HPP
