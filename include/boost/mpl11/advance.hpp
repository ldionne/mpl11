/*!
 * @file
 * Defines `boost::mpl11::advance`.
 */

#ifndef BOOST_MPL11_ADVANCE_HPP
#define BOOST_MPL11_ADVANCE_HPP

#include <boost/mpl11/fwd/advance.hpp>

#include <boost/mpl11/class_of.hpp>
#include <boost/mpl11/integral_c.hpp> // for advance_c


namespace boost { namespace mpl11 {
    template <typename Iterator, typename N>
    struct advance
        : class_of<Iterator>::type::template advance_impl<Iterator, N>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ADVANCE_HPP
