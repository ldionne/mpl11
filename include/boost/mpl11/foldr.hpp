/*!
 * @file
 * Defines `boost::mpl11::foldr`.
 */

#ifndef BOOST_MPL11_FOLDR_HPP
#define BOOST_MPL11_FOLDR_HPP

#include <boost/mpl11/apply_wrap.hpp>
#include <boost/mpl11/arg.hpp>
#include <boost/mpl11/deref.hpp>
#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/iter_foldr.hpp>
#include <boost/mpl11/lambda.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
namespace foldr_detail {
template <typename Sequence, typename State, typename F>
struct foldr_impl
    : iter_foldr<
        Sequence, State, apply_wrap<typename lambda<F>::type, _1, deref<_2>>
    >
{ };
} // end namespace foldr_detail

/*!
 * Accumulates the elements of a sequence from an initial state using a
 * custom operation.
 *
 * Specifically, returns the result of the successive application of the
 * binary operation `F` to the result of the next `F` invocation (or `State`
 * for the first application) and every element of the sequence in order.
 *
 * The default implementation is equivalent to
   @code
        iter_foldr<
            Sequence, State,
            apply_wrap<lambda<F>::type, _1, deref<_2>>
        >
   @endcode
 */
template <typename Sequence, typename State, typename F>
struct foldr
    : detail::tag_dispatched<tag::foldr, Sequence, State, F>
      ::template with_default<foldr_detail::foldr_impl<_2, _3, _4>>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FOLDR_HPP
