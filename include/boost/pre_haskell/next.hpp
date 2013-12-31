/*!
 * @file
 * Defines `boost::mpl11::next`.
 */

#ifndef BOOST_MPL11_NEXT_HPP
#define BOOST_MPL11_NEXT_HPP

#include <boost/mpl11/fwd/next.hpp>

#include <boost/mpl11/class_of.hpp>


namespace boost { namespace mpl11 {
    template <typename Iterator>
    struct next
        : class_of<Iterator>::type::template next_impl<Iterator>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_NEXT_HPP
