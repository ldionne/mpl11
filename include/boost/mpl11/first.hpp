/*!
 * @file
 * Defines `boost::mpl11::first`.
 */

#ifndef BOOST_MPL11_FIRST_HPP
#define BOOST_MPL11_FIRST_HPP

#include <boost/mpl11/fwd/first.hpp>

#include <boost/mpl11/class.hpp>


namespace boost { namespace mpl11 {
    template <typename Pair>
    struct first
        : class_<Pair>::type::template first<Pair>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FIRST_HPP
