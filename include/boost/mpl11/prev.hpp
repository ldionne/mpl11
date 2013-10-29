/*!
 * @file
 * Defines `boost::mpl11::prev`.
 */

#ifndef BOOST_MPL11_PREV_HPP
#define BOOST_MPL11_PREV_HPP

#include <boost/mpl11/fwd/prev.hpp>

#include <boost/mpl11/class_of.hpp>


namespace boost { namespace mpl11 {
    template <typename Iterator>
    struct prev
        : class_of<Iterator>::type::template prev_impl<Iterator>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_PREV_HPP
