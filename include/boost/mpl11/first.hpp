/*!
 * @file
 * Defines `boost::mpl11::first`.
 */

#ifndef BOOST_MPL11_FIRST_HPP
#define BOOST_MPL11_FIRST_HPP

#include <boost/mpl11/detail/tag_dispatched.hpp>


namespace boost { namespace mpl11 {
namespace tag { struct first; }

/*!
 * Returns the first element of a pair.
 *
 * This operation does not have a default implementation.
 *
 * @warning
 * Differences from the original MPL:
 * - No default implementation is provided.
 * - The operation is tag dispatched.
 */
template <typename Pair>
struct first
    : detail::tag_dispatched<tag::first, Pair>::template
      with_default<>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FIRST_HPP
