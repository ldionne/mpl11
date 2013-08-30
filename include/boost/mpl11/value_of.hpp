/*!
 * @file
 * Defines `boost::mpl11::value_of`.
 */

#ifndef BOOST_MPL11_VALUE_OF_HPP
#define BOOST_MPL11_VALUE_OF_HPP

#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
/*!
 * Returns the value that _would_ be used for an element in an associative
 * sequence.
 *
 * No default implementation is provided for this operation.
 */
template <typename AssociativeSequence, typename Element>
struct value_of
    : detail::tag_dispatched<tag::value_of, AssociativeSequence, Element>
      ::template with_default<>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_VALUE_OF_HPP
