/*!
 * @file
 * Defines `boost::mpl11::category_of`.
 */

#ifndef BOOST_MPL11_CATEGORY_OF_HPP
#define BOOST_MPL11_CATEGORY_OF_HPP

#include <boost/mpl11/fwd/category_of.hpp>

#include <boost/mpl11/category/none.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/identity.hpp>


namespace boost { namespace mpl11 {
    template <typename T>
    struct dispatch<tag::category_of, T>
        : identity<category::none>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_CATEGORY_OF_HPP
