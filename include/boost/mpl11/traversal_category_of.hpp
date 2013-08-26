/*!
 * @file
 * Defines `boost::mpl11::traversal_category_of`.
 */

#ifndef BOOST_MPL11_TRAVERSAL_CATEGORY_OF_HPP
#define BOOST_MPL11_TRAVERSAL_CATEGORY_OF_HPP

#include <boost/mpl11/detail/tag_dispatched.hpp>


namespace boost { namespace mpl11 {
namespace tag { struct traversal_category_of; }

/*!
 * Returns the traversal category of a sequence or an iterator.
 *
 * There is no default implementation for this operation.
 */
template <typename SequenceOrIterator>
struct traversal_category_of
    : detail::tag_dispatched<tag::traversal_category_of, SequenceOrIterator>
      ::template with_default<>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_TRAVERSAL_CATEGORY_OF_HPP
