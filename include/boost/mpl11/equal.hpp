/*!
 * @file
 * Defines `boost::mpl11::equal`.
 */

#ifndef BOOST_MPL11_EQUAL_HPP
#define BOOST_MPL11_EQUAL_HPP

#include <boost/mpl11/fwd/equal.hpp>

#include <boost/mpl11/and.hpp>
#include <boost/mpl11/class_of.hpp>
#include <boost/mpl11/detail/is_same.hpp>


namespace boost { namespace mpl11 {
    template <typename X, typename Y, typename ...Z>
    struct equal
        : and_<equal<X, Y>, equal<Y, Z...>>
    { };

    namespace equal_detail {
        struct use_is_same {
            template <typename X, typename Y>
            using equal_impl = detail::is_same<X, Y>;
        };
    } // end namespace equal_detail

    template <typename X, typename Y>
    struct equal<X, Y>
        : class_of<X, equal_detail::use_is_same>::type::template
            equal_impl<X, Y>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_EQUAL_HPP
