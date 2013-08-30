/*!
 * @file
 * Defines `boost::mpl11::second`.
 */

#ifndef BOOST_MPL11_SECOND_HPP
#define BOOST_MPL11_SECOND_HPP

#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
/*!
 * Returns the second element of a pair.
 *
 * This operation does not have a default implementation.
 *
 * @warning
 * Differences from the original MPL:
 * - No default implementation is provided.
 * - The operation is tag dispatched.
 */
template <typename Pair>
struct second
    : detail::tag_dispatched<tag::second, Pair>::template
      with_default<>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_SECOND_HPP
