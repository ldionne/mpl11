/*!
 * @file
 * Defines `boost::mpl11::foldl`.
 */

#ifndef BOOST_MPL11_FOLDL_HPP
#define BOOST_MPL11_FOLDL_HPP

#include <boost/mpl11/apply_wrap.hpp>
#include <boost/mpl11/arg.hpp>
#include <boost/mpl11/deref.hpp>
#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/iter_foldl.hpp>
#include <boost/mpl11/lambda.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
namespace foldl_detail {
template <typename Sequence, typename State, typename F>
struct foldl_impl
    : iter_foldl<
        Sequence, State, apply_wrap<typename lambda<F>::type, _1, deref<_2>>
    >
{ };
} // end namespace foldl_detail

/*!
 * Accumulates the elements of a sequence from an initial state using a
 * custom operation.
 *
 * Specifically, returns the result of the successive application of the
 * binary operation `F` to the result of the previous `F` invocation (or
 * `State` for the first application) and every element of the sequence
 * in order.
 *
 * The default implementation is equivalent to
   @code
        iter_foldl<
            Sequence, State,
            apply_wrap<lambda<F>::type, _1, deref<_2>>
        >
   @endcode
 *
 * @note
 * This is equivalent to the `mpl::fold` metafunction from the original MPL.
 */
template <typename Sequence, typename State, typename F>
struct foldl
    : detail::tag_dispatched<tag::foldl, Sequence, State, F>
      ::template with_default<foldl_detail::foldl_impl<_1, _2, _3>>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FOLDL_HPP
