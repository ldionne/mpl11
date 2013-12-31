/*!
 * @file
 * Defines `boost::mpl11::insert`.
 */

#ifndef BOOST_MPL11_INSERT_HPP
#define BOOST_MPL11_INSERT_HPP

#include <boost/mpl11/fwd/insert.hpp>

#include <boost/mpl11/class_of.hpp>


namespace boost { namespace mpl11 {
    template <typename Container, typename Position, typename Element>
    struct insert
        : class_of<Container>::type::template
            insert_impl<Container, Position, Element>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INSERT_HPP
