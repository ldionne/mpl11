/*!
 * @file
 * Defines `boost::mpl11::next`.
 */

#ifndef BOOST_MPL11_NEXT_HPP
#define BOOST_MPL11_NEXT_HPP

#include <boost/mpl11/detail/tag_dispatched.hpp>


namespace boost { namespace mpl11 {
namespace tag { struct next; }

/*!
 * Returns the next iterator in the sequence.
 *
 * This operation does not have a default implementation.
 *
 * @warning
 * Differences from the original MPL:
 * - No default implementation is provided.
 */
template <typename Iterator>
struct next
    : detail::tag_dispatched<tag::next, Iterator>::template
      with_default<>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_NEXT_HPP
