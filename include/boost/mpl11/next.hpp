/*!
 * @file
 * Defines `boost::mpl11::next`.
 */

#ifndef BOOST_MPL11_NEXT_HPP
#define BOOST_MPL11_NEXT_HPP

#include <boost/mpl11/fwd/next.hpp>

#include <boost/mpl11/class.hpp>


namespace boost { namespace mpl11 {
    template <typename Iterator>
    struct next
        : class_<Iterator>::type::template next<Iterator>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_NEXT_HPP
