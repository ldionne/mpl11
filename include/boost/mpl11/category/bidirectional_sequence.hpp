/*!
 * @file
 * Defines `boost::mpl11::category::bidirectional_sequence`.
 */

#ifndef BOOST_MPL11_CATEGORY_BIDIRECTIONAL_SEQUENCE_HPP
#define BOOST_MPL11_CATEGORY_BIDIRECTIONAL_SEQUENCE_HPP

#include <boost/mpl11/fwd/category/bidirectional_sequence.hpp>

#include <boost/mpl11/category/forward_sequence.hpp>


namespace boost { namespace mpl11 { namespace category {
    struct bidirectional_sequence : forward_sequence { };
}}}

#endif // !BOOST_MPL11_CATEGORY_BIDIRECTIONAL_SEQUENCE_HPP
