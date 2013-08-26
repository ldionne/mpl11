/*!
 * @file
 * Defines `boost::mpl11::distance`.
 */

#ifndef BOOST_MPL11_DISTANCE_HPP
#define BOOST_MPL11_DISTANCE_HPP

#include <boost/mpl11/arg.hpp>
#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/iter_foldl.hpp>
#include <boost/mpl11/iterator_range.hpp>
#include <boost/mpl11/lambda.hpp>
#include <boost/mpl11/next.hpp>


namespace boost { namespace mpl11 {
namespace tag { struct distance; }

/*!
 * Returns the distance between `First` and `Last` iterators.
 *
 * The default implementation is equivalent to
   @code
        iter_foldl<
            iterator_range<First, Last>,
            ulong<0>,
            next<_1>
        >
   @endcode
 */
template <typename First, typename Last>
struct distance
    : detail::tag_dispatched<tag::distance, First, Last>::template
      with_default<
        iter_foldl<
            iterator_range<_2, _3>,
            ulong<0>,
            typename lambda<next<_1>>::type
        >
      >
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_DISTANCE_HPP
