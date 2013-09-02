/*!
 * @file
 * Defines `boost::mpl11::intrinsic::category_of`.
 */

#ifndef BOOST_MPL11_INTRINSIC_CATEGORY_OF_HPP
#define BOOST_MPL11_INTRINSIC_CATEGORY_OF_HPP

#include <boost/mpl11/categories.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
namespace intrinsic {
    /*!
     * @ingroup intrinsic
     *
     * Returns the category of a type.
     *
     *
     * ### Default implementation
     *
     * Equivalent to `identity<category::none>`.
     */
    template <typename T>
    struct category_of
        : dispatch<tag::category_of, T>
    { };
} // end namespace intrinsic

template <typename T>
struct dispatch<detail::default_<tag::category_of>, T>
    : identity<category::none>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INTRINSIC_CATEGORY_OF_HPP
