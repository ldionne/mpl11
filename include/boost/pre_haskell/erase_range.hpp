/*!
 * @file
 * Defines `boost::mpl11::erase_range`.
 */

#ifndef BOOST_MPL11_ERASE_RANGE_HPP
#define BOOST_MPL11_ERASE_RANGE_HPP

#include <boost/mpl11/fwd/erase_range.hpp>

#include <boost/mpl11/class_of.hpp>


namespace boost { namespace mpl11 {
    template <typename Container, typename First, typename Last>
    struct erase_range
        : class_of<Container>::type::template
            erase_range_impl<Container, First, Last>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ERASE_RANGE_HPP
