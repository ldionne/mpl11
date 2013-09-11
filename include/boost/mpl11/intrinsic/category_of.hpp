/*!
 * @file
 * Defines `boost::mpl11::category_of`.
 */

#ifndef BOOST_MPL11_INTRINSIC_CATEGORY_OF_HPP
#define BOOST_MPL11_INTRINSIC_CATEGORY_OF_HPP

#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup intrinsics
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
}} // end namespace boost::mpl11

#ifndef BOOST_MPL11_DONT_INCLUDE_DEFAULTS
#   include <boost/mpl11/detail/default/category_of.hpp>
#endif

#endif // !BOOST_MPL11_INTRINSIC_CATEGORY_OF_HPP
