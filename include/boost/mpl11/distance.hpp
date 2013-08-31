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
#include <boost/mpl11/next.hpp>
#include <boost/mpl11/quote.hpp>
#include <boost/mpl11/tags.hpp>
#include <boost/mpl11/view/bounded_by.hpp>


namespace boost { namespace mpl11 {
/*!
 * Returns the distance between `First` and `Last` iterators.
 *
 * The default implementation is equivalent to
   @code
        iter_foldl<
            view::bounded_by<First, Last>,
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
            view::bounded_by<_1, _2>,
            ulong<0>,
            quote<next>
        >
      >
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_DISTANCE_HPP
