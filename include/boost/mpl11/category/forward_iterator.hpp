/*!
 * @file
 * Defines `boost::mpl11::category::forward_iterator`.
 */

#ifndef BOOST_MPL11_CATEGORY_FORWARD_ITERATOR_HPP
#define BOOST_MPL11_CATEGORY_FORWARD_ITERATOR_HPP

#include <boost/mpl11/fwd/category/forward_iterator.hpp>

#include <boost/mpl11/category/none.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/fwd/parent.hpp>
#include <boost/mpl11/identity.hpp>


namespace boost { namespace mpl11 {
    template <>
    struct dispatch<tag::parent, category::forward_iterator>
        : identity<category::none>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_CATEGORY_FORWARD_ITERATOR_HPP
