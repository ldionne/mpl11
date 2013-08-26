/*!
 * @file
 * Defines `boost::mpl11::push_front`.
 */

#ifndef BOOST_MPL11_PUSH_FRONT_HPP
#define BOOST_MPL11_PUSH_FRONT_HPP

#include <boost/mpl11/arg.hpp>
#include <boost/mpl11/begin.hpp>
#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/insert.hpp>


namespace boost { namespace mpl11 {
namespace tag { struct push_front; }

/*!
 * Inserts an element at the beginning of a sequence.
 *
 * The default implementation is equivalent to
 * `insert<Sequence, begin<Sequence>::type, Element>`.
 */
template <typename Sequence, typename Element>
struct push_front
    : detail::tag_dispatched<tag::push_front, Sequence, Element>::template
      with_default<insert<_2, begin<_2>, _3>>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_PUSH_FRONT_HPP
