/*!
 * @file
 * Defines `boost::mpl11::iter_foldr`.
 */

#ifndef BOOST_MPL11_ITER_FOLDR_HPP
#define BOOST_MPL11_ITER_FOLDR_HPP

#include <boost/mpl11/apply_wrap.hpp>
#include <boost/mpl11/arg.hpp>
#include <boost/mpl11/begin.hpp>
#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/end.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/lambda.hpp>
#include <boost/mpl11/next.hpp>


namespace boost { namespace mpl11 {
namespace iter_foldr_detail {
    template <typename First, typename Last, typename State, typename F>
    struct iter_foldr_impl
        : apply_wrap<
            F,
            typename iter_foldr_impl<
                typename next<First>::type, Last, State, F
            >::type,
            First
        >
    { };

    template <typename Last, typename State, typename F>
    struct iter_foldr_impl<Last, Last, State, F>
        : identity<State>
    { };
} // end namespace iter_foldr_detail

namespace tag { struct iter_foldr; }

/*!
 * Accumulates the iterators in a range from an initial state using a
 * custom operation.
 *
 * Specifically, returns the result of the successive application of the
 * binary operation `F` to the result of the next `F` invocation (or
 * `State` for the first application) and each iterator in the range
 * [`begin<Sequence>::type`, `end<Sequence>::type`) in order.
 *
 * The default implementation is equivalent to the following:
 * Let `First` be the same as `begin<Sequence>::type` and  `Last` the same
 * as `end<Sequence>::type`. The default implementation is equivalent to
 * `iter_foldr_impl<First, Last, State, F>`, where `iter_foldr_impl` is
 * equivalent to `identity<State>` if `is_same<First, Last>::value` is
 * `true` and
   @code
        apply<
            F,
            iter_foldr_impl<next<First>::type, Last, State, F>::type,
            First
        >
   @endcode
 * otherwise.
 */
template <typename Sequence, typename State, typename F>
struct iter_foldr
    : detail::tag_dispatched<tag::iter_foldr, Sequence, State, F>
      ::template with_default<
        iter_foldr_detail::iter_foldr_impl<
            begin<_2>, end<_2>, _3, lambda<_4>
        >
      >
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ITER_FOLDR_HPP
