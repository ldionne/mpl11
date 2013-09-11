/*!
 * @file
 * Defines the default implementation of `boost::mpl11::algorithm::foldl`.
 */

#ifndef BOOST_MPL11_DETAIL_DEFAULT_FOLDL_HPP
#define BOOST_MPL11_DETAIL_DEFAULT_FOLDL_HPP

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
namespace foldl_detail {
    template <typename First, typename Last, typename State, typename F,
              bool = equal_to<First, Last>::type::value>
    struct foldl_impl
        : foldl_impl<
            typename next<First>::type,
            Last,
            typename apply_wrap<
                F, State, typename deref<First>::type
            >::type,
            F
        >
    { };

    template <typename First, typename Last, typename State, typename F>
    struct foldl_impl<First, Last, State, F, true>
        : identity<State>
    { };
} // end namespace foldl_detail

template <typename Sequence, typename State, typename F>
struct dispatch<detail::default_<tag::foldl>, Sequence, State, F>
    : foldl_detail::foldl_impl<
        typename begin<Sequence>::type,
        typename end<Sequence>::type,
        State,
        typename lambda<F>::type
    >
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_DETAIL_DEFAULT_FOLDL_HPP
