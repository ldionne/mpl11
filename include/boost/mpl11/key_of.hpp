/*!
 * @file
 * Defines `boost::mpl11::key_of`.
 */

#ifndef BOOST_MPL11_KEY_OF_HPP
#define BOOST_MPL11_KEY_OF_HPP

#include <boost/mpl11/detail/tag_dispatched.hpp>


namespace boost { namespace mpl11 {
namespace tag { struct key_of; }

/*!
 * Returns the key that _would_ be used for an element in an associative
 * sequence.
 *
 * No default implementation is provided for this operation.
 */
template <typename AssociativeSequence, typename Element>
struct key_of
    : detail::tag_dispatched<tag::key_of, AssociativeSequence, Element>
      ::template with_default<>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_KEY_OF_HPP
