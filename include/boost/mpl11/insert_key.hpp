/*!
 * @file
 * Defines `boost::mpl11::insert_key`.
 */

#ifndef BOOST_MPL11_INSERT_KEY_HPP
#define BOOST_MPL11_INSERT_KEY_HPP

#include <boost/mpl11/fwd/insert_key.hpp>

#include <boost/mpl11/class_of.hpp>


namespace boost { namespace mpl11 {
    template <typename Container, typename Element>
    struct insert_key
        : class_of<Container>::type::template
            insert_key_impl<Container, Element>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INSERT_KEY_HPP
