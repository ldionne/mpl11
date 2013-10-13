/*!
 * @file
 * Defines `boost::mpl11::count_if`.
 */

#ifndef BOOST_MPL11_ALGORITHM_COUNT_IF_HPP
#define BOOST_MPL11_ALGORITHM_COUNT_IF_HPP

#include <boost/mpl11/algorithm/count_if_fwd.hpp>
#include <boost/mpl11/algorithm/foldl.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/functional/apply_wrap.hpp>
#include <boost/mpl11/functional/arg.hpp>
#include <boost/mpl11/functional/lambda.hpp>
#include <boost/mpl11/if.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/intrinsic/next.hpp>


namespace boost { namespace mpl11 {
    template <typename Sequence, typename Predicate>
    struct dispatch<tag::default_<tag::count_if>, Sequence, Predicate>
        : foldl<
            Sequence,
            ulong<0>,
            if_<apply_wrap<typename lambda<Predicate>::type, _2>,
                next<_1>,
                _1
            >
        >
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ALGORITHM_COUNT_IF_HPP
