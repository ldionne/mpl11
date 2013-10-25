/*!
 * @file
 * Defines `boost::mpl11::Comparable`.
 */

#ifndef BOOST_MPL11_COMPARABLE_COMPARABLE_HPP
#define BOOST_MPL11_COMPARABLE_COMPARABLE_HPP

#include <boost/mpl11/fwd/comparable.hpp>


namespace boost { namespace mpl11 {
    struct Comparable {
        template <typename X, typename Y>
        struct equal_to;

        template <typename X, typename Y>
        struct not_equal_to;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_COMPARABLE_COMPARABLE_HPP
