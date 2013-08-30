/*!
 * @file
 * Defines `boost::mpl11::deref`.
 */

#ifndef BOOST_MPL11_DEREF_HPP
#define BOOST_MPL11_DEREF_HPP

#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
/*!
 * Dereferences an iterator.
 *
 * No default implementation is provided for this operation.
 *
 * @warning
 * Differences from the original MPL:
 * - No default implementation is provided.
 */
template <typename Iterator>
struct deref
    : detail::tag_dispatched<tag::deref, Iterator>::template
      with_default<>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_DEREF_HPP
