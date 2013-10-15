/*!
 * @file
 * Defines `boost::mpl11::category::integral_constant`.
 */

#ifndef BOOST_MPL11_CATEGORY_INTEGRAL_CONSTANT_HPP
#define BOOST_MPL11_CATEGORY_INTEGRAL_CONSTANT_HPP

#include <boost/mpl11/fwd/category/integral_constant.hpp>

#include <boost/mpl11/category/none.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/fwd/parent.hpp>
#include <boost/mpl11/identity.hpp>


namespace boost { namespace mpl11 {
    template <>
    struct dispatch<tag::parent, category::integral_constant>
        : identity<category::none>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_CATEGORY_INTEGRAL_CONSTANT_HPP
