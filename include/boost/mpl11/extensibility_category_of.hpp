/*!
 * @file
 * Defines `boost::mpl11::extensibility_category_of`.
 */

#ifndef BOOST_MPL11_EXTENSIBILITY_CATEGORY_OF_HPP
#define BOOST_MPL11_EXTENSIBILITY_CATEGORY_OF_HPP

#include <boost/mpl11/detail/tag_dispatched.hpp>


namespace boost { namespace mpl11 {
namespace tag { struct extensibility_category_of; }

/*!
 * Returns the extensibility category of a sequence.
 *
 * There is no default implementation for this operation.
 */
template <typename Sequence>
struct extensibility_category_of
    : detail::tag_dispatched<tag::extensibility_category_of, Sequence>
      ::template with_default<>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_EXTENSIBILITY_CATEGORY_OF_HPP
