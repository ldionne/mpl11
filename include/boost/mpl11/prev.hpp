/*!
 * @file
 * Defines `boost::mpl11::prev`.
 */

#ifndef BOOST_MPL11_PREV_HPP
#define BOOST_MPL11_PREV_HPP

#include <boost/mpl11/fwd/prev.hpp>

#include <boost/mpl11/class.hpp>


namespace boost { namespace mpl11 {
    template <typename Iterator>
    struct prev
        : class_<Iterator>::type::template prev<Iterator>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_PREV_HPP
