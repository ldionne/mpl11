/*!
 * @file
 * Defines `boost::mpl11::new_`.
 */

#ifndef BOOST_MPL11_NEW_HPP
#define BOOST_MPL11_NEW_HPP

#include <boost/mpl11/fwd/new.hpp>

#include <boost/mpl11/class_of.hpp>


namespace boost { namespace mpl11 {
    template <typename Container>
    struct new_
        : class_of<Container>::type::template new_impl<Container>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_NEW_HPP
