/*!
 * @file
 * Defines the default implementation of `boost::mpl11::algorithm::count_if`.
 */

#ifndef BOOST_MPL11_DETAIL_DEFAULT_COUNT_IF_HPP
#define BOOST_MPL11_DETAIL_DEFAULT_COUNT_IF_HPP

#include <boost/mpl11/algorithm/foldl.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/functional/apply_wrap.hpp>
#include <boost/mpl11/functional/arg.hpp>
#include <boost/mpl11/functional/lambda.hpp>
#include <boost/mpl11/if.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/intrinsic/next.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
template <typename Sequence, typename Predicate>
struct dispatch<detail::default_<tag::count_if>, Sequence, Predicate>
    : algorithm::foldl<
        Sequence,
        ulong<0>,
        if_<apply_wrap<typename lambda<Predicate>::type, _2>,
            next<_1>,
            _1
        >
    >
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_DETAIL_DEFAULT_COUNT_IF_HPP
