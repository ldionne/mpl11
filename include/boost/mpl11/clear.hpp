/*!
 * @file
 * Defines `boost::mpl11::clear`.
 */

#ifndef BOOST_MPL11_CLEAR_HPP
#define BOOST_MPL11_CLEAR_HPP

#include <boost/mpl11/arg.hpp>
#include <boost/mpl11/begin.hpp>
#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/end.hpp>
#include <boost/mpl11/erase.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
/*!
 * Returns an empty sequence concept-identical to `Sequence`.
 *
 * The default implementation is equivalent to
 * `erase<Sequence, begin<Sequence>::type, end<Sequence>::type>`.
 */
template <typename Sequence>
struct clear
    : detail::tag_dispatched<tag::clear, Sequence>::template
      with_default<erase<_2, begin<_2>, end<_2>>>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_CLEAR_HPP
