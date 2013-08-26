/*!
 * @file
 * Defines `boost::mpl11::prior`.
 */

#ifndef BOOST_MPL11_PRIOR_HPP
#define BOOST_MPL11_PRIOR_HPP

#include <boost/mpl11/detail/tag_dispatched.hpp>


namespace boost { namespace mpl11 {
namespace tag { struct prior; }

/*!
 * Returns the previous iterator in the sequence.
 *
 * This operation does not have a default implementation.
 *
 * @warning
 * Differences from the original MPL:
 * - No default implementation is provided.
 */
template <typename Iterator>
struct prior
    : detail::tag_dispatched<tag::prior, Iterator>::template
      with_default<>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_PRIOR_HPP
