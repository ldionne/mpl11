/*!
 * @file
 * Defines `boost::mpl11::category::random_access_sequence`.
 */

#ifndef BOOST_MPL11_CATEGORY_RANDOM_ACCESS_SEQUENCE_HPP
#define BOOST_MPL11_CATEGORY_RANDOM_ACCESS_SEQUENCE_HPP

#include <boost/mpl11/fwd/category/random_access_sequence.hpp>

#include <boost/mpl11/category/bidirectional_sequence.hpp>


namespace boost { namespace mpl11 { namespace category {
    struct random_access_sequence : bidirectional_sequence { };
}}}

#endif // !BOOST_MPL11_CATEGORY_RANDOM_ACCESS_SEQUENCE_HPP
