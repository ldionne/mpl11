/*!
 * @file
 * Defines `boost::mpl11::end`.
 */

#ifndef BOOST_MPL11_END_HPP
#define BOOST_MPL11_END_HPP

#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
/*!
 * Returns the past-the-end iterator of the sequence.
 *
 * No default implementation is provided for this operation.
 *
 * @warning
 * Differences from the original MPL:
 * - If `Sequence` is not a `ForwardSequence`, `end<Sequence>::type` is
 *   invalid instead of being the same as `mpl::void_`.
 * - There is no default implementation.
 */
template <typename Sequence>
struct end
    : detail::tag_dispatched<tag::end, Sequence>::template
      with_default<>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_END_HPP
