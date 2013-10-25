/*!
 * @file
 * Defines `boost::mpl11::Comparable::equal_to`.
 */

#ifndef BOOST_MPL11_COMPARABLE_EQUAL_TO_HPP
#define BOOST_MPL11_COMPARABLE_EQUAL_TO_HPP

#include <boost/mpl11/comparable/comparable.hpp>
#include <boost/mpl11/detail/is_same.hpp>


namespace boost { namespace mpl11 {
    template <typename X, typename Y>
    struct Comparable::equal_to
        : detail::is_same<X, Y>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_COMPARABLE_EQUAL_TO_HPP
