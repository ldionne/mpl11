/*!
 * @file
 * Defines `boost::mpl11::begin`.
 */

#ifndef BOOST_MPL11_BEGIN_HPP
#define BOOST_MPL11_BEGIN_HPP

#include <boost/mpl11/detail/tag_dispatched.hpp>


namespace boost { namespace mpl11 {
namespace tag { struct begin; }

/*!
 * Returns an iterator pointing to the first element of the sequence.
 *
 * No default implementation is provided for this operation.
 *
 * @warning
 * Differences from the original MPL:
 * - If `Sequence` is not a `ForwardSequence`, `begin<Sequence>::type` is
 *   invalid instead of being the same as `mpl::void_`.
 * - There is no default implementation.
 */
template <typename Sequence>
struct begin
    : detail::tag_dispatched<tag::begin, Sequence>::template
      with_default<>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_BEGIN_HPP
