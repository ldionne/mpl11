/*!
 * @file
 * Defines `boost::mpl11::size`.
 */

#ifndef BOOST_MPL11_SIZE_HPP
#define BOOST_MPL11_SIZE_HPP

#include <boost/mpl11/arg.hpp>
#include <boost/mpl11/begin.hpp>
#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/distance.hpp>
#include <boost/mpl11/end.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
/*!
 * Returns the number of elements in a sequence.
 *
 * The default implementation is equivalent to
 * `distance<begin<Sequence>::type, end<Sequence>::type>`.
 */
template <typename Sequence>
struct size
    : detail::tag_dispatched<tag::size, Sequence>::template
      with_default<distance<begin<_2>, end<_2>>>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_SIZE_HPP
