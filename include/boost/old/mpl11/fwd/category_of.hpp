/*!
 * @file
 * Forward declares `boost::mpl11::category_of`.
 */

#ifndef BOOST_MPL11_FWD_CATEGORY_OF_HPP
#define BOOST_MPL11_FWD_CATEGORY_OF_HPP

#include <boost/mpl11/dispatch.hpp>


namespace boost { namespace mpl11 {
    namespace tag { struct category_of; }

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

#endif // !BOOST_MPL11_FWD_CATEGORY_OF_HPP
