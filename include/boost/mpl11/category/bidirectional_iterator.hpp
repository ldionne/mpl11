/*!
 * @file
 * Defines `boost::mpl11::category::bidirectional_iterator`.
 */

#ifndef BOOST_MPL11_CATEGORY_BIDIRECTIONAL_ITERATOR_HPP
#define BOOST_MPL11_CATEGORY_BIDIRECTIONAL_ITERATOR_HPP

#include <boost/mpl11/fwd/category/bidirectional_iterator.hpp>

#include <boost/mpl11/category/forward_iterator.hpp>


namespace boost { namespace mpl11 { namespace category {
    struct bidirectional_iterator : forward_iterator { };
}}}

#endif // !BOOST_MPL11_CATEGORY_BIDIRECTIONAL_ITERATOR_HPP
