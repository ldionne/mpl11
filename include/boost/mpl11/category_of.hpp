/*!
 * @file
 * Defines `boost::mpl11::category_of`.
 */

#ifndef BOOST_MPL11_CATEGORY_OF_HPP
#define BOOST_MPL11_CATEGORY_OF_HPP

#include <boost/mpl11/detail/tag_dispatched.hpp>


namespace boost { namespace mpl11 {
namespace tag { struct category_of; }

/*!
 * Returns the category of a type.
 *
 * There is no default implementation for this operation.
 */
template <typename T>
struct category_of
    : detail::tag_dispatched<tag::category_of, T>
      ::template with_default<>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_CATEGORY_OF_HPP
