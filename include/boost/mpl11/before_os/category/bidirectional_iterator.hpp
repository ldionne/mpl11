/*!
 * @file
 * Defines `boost::mpl11::category::bidirectional_iterator`.
 */

#ifndef BOOST_MPL11_CATEGORY_BIDIRECTIONAL_ITERATOR_HPP
#define BOOST_MPL11_CATEGORY_BIDIRECTIONAL_ITERATOR_HPP

#include <boost/mpl11/fwd/category/bidirectional_iterator.hpp>

#include <boost/mpl11/category/forward_iterator.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/fwd/parent.hpp>
#include <boost/mpl11/identity.hpp>


namespace boost { namespace mpl11 {
    template <>
    struct dispatch<tag::parent, category::bidirectional_iterator>
        : identity<category::forward_iterator>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_CATEGORY_BIDIRECTIONAL_ITERATOR_HPP
