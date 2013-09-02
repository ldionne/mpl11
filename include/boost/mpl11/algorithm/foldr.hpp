/*!
 * @file
 * Defines `boost::mpl11::algorithm::foldr`.
 */

#ifndef BOOST_MPL11_ALGORITHM_FOLDR_HPP
#define BOOST_MPL11_ALGORITHM_FOLDR_HPP

#include <boost/mpl11/apply_wrap.hpp>
#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/intrinsic/begin.hpp>
#include <boost/mpl11/intrinsic/deref.hpp>
#include <boost/mpl11/intrinsic/end.hpp>
#include <boost/mpl11/intrinsic/equal_to.hpp>
#include <boost/mpl11/intrinsic/next.hpp>
#include <boost/mpl11/lambda.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
namespace algorithm {
    /*!
     * @ingroup algorithm
     *
     * Accumulates the elements of a sequence from an initial state using a
     * custom operation.
     *
     * Specifically, returns the result of the successive application of the
     * binary operation `F` to the result of the next `F` invocation (or
     * `State` for the first application) and every element of the sequence
     * in order.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to the following:
     * Let `First` be the same as `begin<Sequence>::type` and  `Last`
     * the same as `end<Sequence>::type`. `foldr` is equivalent to
     * `foldr_impl<First, Last, State, F>`, where `foldr_impl` is
     * equivalent to `identity<State>` if `equal_to<First, Last>::type::value`
     * is `true` and
       @code
            apply<
                F,
                foldr_impl<next<First>::type, Last, State, F>::type,
                deref<First>::type
            >
       @endcode
     * otherwise.
     */
    template <typename Sequence, typename State, typename F>
    struct foldr
        : detail::tag_dispatched<tag::foldr, Sequence, State, F>
    { };
} // end namespace algorithm

namespace foldr_detail {
    template <typename First, typename Last, typename State, typename F,
              bool = intrinsic::equal_to<First, Last>::type::value>
    struct foldr_impl
        : apply_wrap<
            F,
            typename foldr_impl<
                typename intrinsic::next<First>::type, Last, State, F
            >::type,
            typename intrinsic::deref<First>::type
        >
    { };

    template <typename First, typename Last, typename State, typename F>
    struct foldr_impl<First, Last, State, F, true>
        : identity<State>
    { };
} // end namespace foldr_detail

template <typename Sequence, typename State, typename F>
struct dispatch<detail::default_<tag::foldr>, Sequence, State, F>
    : foldr_detail::foldr_impl<
        typename intrinsic::begin<Sequence>::type,
        typename intrinsic::end<Sequence>::type,
        State,
        typename lambda<F>::type
    >
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ALGORITHM_FOLDR_HPP
