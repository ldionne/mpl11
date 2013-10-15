/*!
 * @file
 * Defines `boost::mpl11::category::random_access_iterator`.
 */

#ifndef BOOST_MPL11_CATEGORY_RANDOM_ACCESS_ITERATOR_HPP
#define BOOST_MPL11_CATEGORY_RANDOM_ACCESS_ITERATOR_HPP

#include <boost/mpl11/fwd/category/random_access_iterator.hpp>

#include <boost/mpl11/category/bidirectional_iterator.hpp>


namespace boost { namespace mpl11 { namespace category {
    struct random_access_iterator : bidirectional_iterator { };
}}}

#endif // !BOOST_MPL11_CATEGORY_RANDOM_ACCESS_ITERATOR_HPP
