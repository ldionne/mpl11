/*!
 * @file
 * Defines `boost::mpl11::Comparable::not_equal_to`.
 */

#ifndef BOOST_MPL11_COMPARABLE_NOT_EQUAL_TO_HPP
#define BOOST_MPL11_COMPARABLE_NOT_EQUAL_TO_HPP

#include <boost/mpl11/comparable/comparable.hpp>
#include <boost/mpl11/equal_to.hpp>
#include <boost/mpl11/not.hpp>


namespace boost { namespace mpl11 {
    template <typename X, typename Y>
    struct Comparable::not_equal_to
        : not_<equal_to<X, Y>>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_COMPARABLE_NOT_EQUAL_TO_HPP
