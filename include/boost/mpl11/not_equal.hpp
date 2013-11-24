/*!
 * @file
 * Defines `boost::mpl11::not_equal`.
 */

#ifndef BOOST_MPL11_NOT_EQUAL_HPP
#define BOOST_MPL11_NOT_EQUAL_HPP

#include <boost/mpl11/fwd/not_equal.hpp>

#include <boost/mpl11/and.hpp>
#include <boost/mpl11/class_of.hpp>
#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/not.hpp>


namespace boost { namespace mpl11 {
    template <typename X, typename Y, typename ...Z>
    struct not_equal
        : and_<not_equal<X, Y>, not_equal<Y, Z...>>
    { };

    namespace not_equal_detail {
        struct use_is_same {
            template <typename X, typename Y>
            using not_equal_impl = not_<detail::is_same<X, Y>>;
        };
    } // end namespace equal_detail

    template <typename X, typename Y>
    struct not_equal<X, Y>
        : class_of<X, not_equal_detail::use_is_same>::type::template
            not_equal_impl<X, Y>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_NOT_EQUAL_HPP
