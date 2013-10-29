/*!
 * @file
 * Defines `boost::mpl11::Comparable`.
 */

#ifndef BOOST_MPL11_COMPARABLE_HPP
#define BOOST_MPL11_COMPARABLE_HPP

#include <boost/mpl11/fwd/comparable.hpp>

#include <boost/mpl11/equal.hpp>
#include <boost/mpl11/not.hpp>


namespace boost { namespace mpl11 {
    struct Comparable {
        //! This operation must be provided by the user.
        template <typename X, typename Y>
        struct equal_impl;

        //! Equivalent to `not_<equal<X, Y>>`.
        template <typename X, typename Y>
        struct not_equal_impl
            : not_<equal<X, Y>>
        { };
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_COMPARABLE_HPP
