/*!
 * @file
 * Defines `boost::mpl11::push_back`.
 */

#ifndef BOOST_MPL11_PUSH_BACK_HPP
#define BOOST_MPL11_PUSH_BACK_HPP

#include <boost/mpl11/arg.hpp>
#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/end.hpp>
#include <boost/mpl11/insert.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
/*!
 * Inserts an element at the end of a sequence.
 *
 * The default implementation is equivalent to
 * `insert<Sequence, end<Sequence>::type, Element>`.
 */
template <typename Sequence, typename Element>
struct push_back
    : detail::tag_dispatched<tag::push_back, Sequence, Element>::template
      with_default<insert<_2, end<_2>, _3>>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_PUSH_BACK_HPP
