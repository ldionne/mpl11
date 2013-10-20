/*!
 * @file
 * Defines `boost::mpl11::category::random_access_sequence`.
 */

#ifndef BOOST_MPL11_CATEGORY_RANDOM_ACCESS_SEQUENCE_HPP
#define BOOST_MPL11_CATEGORY_RANDOM_ACCESS_SEQUENCE_HPP

#include <boost/mpl11/fwd/category/random_access_sequence.hpp>

#include <boost/mpl11/category/bidirectional_sequence.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/fwd/parent.hpp>
#include <boost/mpl11/identity.hpp>


namespace boost { namespace mpl11 {
    template <>
    struct dispatch<tag::parent, category::random_access_sequence>
        : identity<category::bidirectional_sequence>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_CATEGORY_RANDOM_ACCESS_SEQUENCE_HPP
