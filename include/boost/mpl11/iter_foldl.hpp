/*!
 * @file
 * Defines `boost::mpl11::iter_foldl`.
 */

#ifndef BOOST_MPL11_ITER_FOLDL_HPP
#define BOOST_MPL11_ITER_FOLDL_HPP

#include <boost/mpl11/apply_wrap.hpp>
#include <boost/mpl11/arg.hpp>
#include <boost/mpl11/begin.hpp>
#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/end.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/lambda.hpp>
#include <boost/mpl11/next.hpp>


namespace boost { namespace mpl11 {
namespace iter_foldl_detail {
    template <typename First, typename Last, typename State, typename F>
    struct iter_foldl_impl
        : iter_foldl_impl<
            typename next<First>::type,
            Last,
            typename apply_wrap<F, State, First>::type,
            F
        >
    { };

    template <typename Last, typename State, typename F>
    struct iter_foldl_impl<Last, Last, State, F>
        : identity<State>
    { };
} // end namespace iter_foldl_detail

namespace tag { struct iter_foldl; }

/*!
 * Accumulates the iterators in a range from an initial state using a
 * custom operation.
 *
 * Specifically, returns the result of the successive application of the
 * binary operation `F` to the result of the previous `F` invocation (or
 * `State` for the first application) and each iterator in the range
 * [`begin<Sequence>::type`, `end<Sequence>::type`) in order.
 *
 * The default implementation is equivalent to
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
 * @note
 * This is equivalent to the `mpl::iter_fold` metafunction from
 * the original MPL.
 */
template <typename Sequence, typename State, typename F>
struct iter_foldl
    : detail::tag_dispatched<tag::iter_foldl, Sequence, State, F>
      ::template with_default<
        iter_foldl_detail::iter_foldl_impl<
            begin<_2>, end<_2>, _3, lambda<_4>
        >
      >
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ITER_FOLDL_HPP
