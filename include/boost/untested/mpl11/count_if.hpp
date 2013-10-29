/*!
 * @file
 * Defines `boost::mpl11::count_if`.
 */

#ifndef BOOST_MPL11_COUNT_IF_HPP
#define BOOST_MPL11_COUNT_IF_HPP

#include <boost/mpl11/fwd/count_if.hpp>

#include <boost/mpl11/apply_wrap.hpp>
#include <boost/mpl11/arg.hpp>
#include <boost/mpl11/foldl.hpp>
#include <boost/mpl11/if.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/lambda.hpp>
#include <boost/mpl11/next.hpp>


namespace boost { namespace mpl11 {
    template <typename Sequence, typename Predicate>
    struct count_if
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

#endif // !BOOST_MPL11_COUNT_IF_HPP
