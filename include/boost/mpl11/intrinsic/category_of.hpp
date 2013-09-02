/*!
 * @file
 * Defines `boost::mpl11::intrinsic::category_of`.
 */

#ifndef BOOST_MPL11_INTRINSIC_CATEGORY_OF_HPP
#define BOOST_MPL11_INTRINSIC_CATEGORY_OF_HPP

#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 { namespace intrinsic {
    /*!
     * @ingroup intrinsic
     *
     * Returns the category of a type.
     */
    template <typename T>
    struct category_of
        : detail::tag_dispatched<tag::category_of, T>
    { };
}}} // end namespace boost::mpl11::intrinsic

#endif // !BOOST_MPL11_INTRINSIC_CATEGORY_OF_HPP
