/*!
 * @file
 * Defines `boost::mpl11::category::associative_sequence`.
 */

#ifndef BOOST_MPL11_CATEGORY_ASSOCIATIVE_SEQUENCE_HPP
#define BOOST_MPL11_CATEGORY_ASSOCIATIVE_SEQUENCE_HPP

#include <boost/mpl11/fwd/category/associative_sequence.hpp>

#include <boost/mpl11/category/forward_sequence.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/fwd/parent.hpp>
#include <boost/mpl11/identity.hpp>


namespace boost { namespace mpl11 {
    template <>
    struct dispatch<tag::parent, category::associative_sequence>
        : identity<category::forward_sequence>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_CATEGORY_ASSOCIATIVE_SEQUENCE_HPP
