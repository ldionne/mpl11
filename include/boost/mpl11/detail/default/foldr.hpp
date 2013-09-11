/*!
 * @file
 * Defines the default implementation of `boost::mpl11::algorithm::foldr`.
 */

#ifndef BOOST_MPL11_DETAIL_DEFAULT_FOLDR_HPP
#define BOOST_MPL11_DETAIL_DEFAULT_FOLDR_HPP

#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/functional/apply_wrap.hpp>
#include <boost/mpl11/functional/lambda.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/intrinsic/begin.hpp>
#include <boost/mpl11/intrinsic/deref.hpp>
#include <boost/mpl11/intrinsic/end.hpp>
#include <boost/mpl11/intrinsic/next.hpp>
#include <boost/mpl11/operator/equal_to.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
namespace foldr_detail {
    template <typename First, typename Last, typename State, typename F,
              bool = equal_to<First, Last>::type::value>
    struct foldr_impl
        : apply_wrap<
            F,
            typename foldr_impl<
                typename next<First>::type, Last, State, F
            >::type,
            typename deref<First>::type
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
        typename begin<Sequence>::type,
        typename end<Sequence>::type,
        State,
        typename lambda<F>::type
    >
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_DETAIL_DEFAULT_FOLDR_HPP
