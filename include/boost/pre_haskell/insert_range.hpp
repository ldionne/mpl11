/*!
 * @file
 * Defines `boost::mpl11::insert_range`.
 */

#ifndef BOOST_MPL11_INSERT_RANGE_HPP
#define BOOST_MPL11_INSERT_RANGE_HPP

#include <boost/mpl11/fwd/insert_range.hpp>

#include <boost/mpl11/class_of.hpp>


namespace boost { namespace mpl11 {
    template <typename Container, typename Position, typename Range>
    struct insert_range
        : class_of<Container>::type::template
            insert_range_impl<Container, Position, Range>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INSERT_RANGE_HPP
