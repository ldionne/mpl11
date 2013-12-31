/*!
 * @file
 * Defines `boost::mpl11::clear`.
 */

#ifndef BOOST_MPL11_CLEAR_HPP
#define BOOST_MPL11_CLEAR_HPP

#include <boost/mpl11/fwd/clear.hpp>

#include <boost/mpl11/class_of.hpp>


namespace boost { namespace mpl11 {
    template <typename Container>
    struct clear
        : class_of<Container>::type::template clear_impl<Container>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_CLEAR_HPP
