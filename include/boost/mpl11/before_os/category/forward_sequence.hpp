/*!
 * @file
 * Defines `boost::mpl11::category::forward_sequence`.
 */

#ifndef BOOST_MPL11_CATEGORY_FORWARD_SEQUENCE_HPP
#define BOOST_MPL11_CATEGORY_FORWARD_SEQUENCE_HPP

#include <boost/mpl11/fwd/category/forward_sequence.hpp>

#include <boost/mpl11/category/none.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/fwd/parent.hpp>
#include <boost/mpl11/identity.hpp>


namespace boost { namespace mpl11 {
    template <>
    struct dispatch<tag::parent, category::forward_sequence>
        : identity<category::none>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_CATEGORY_FORWARD_SEQUENCE_HPP
