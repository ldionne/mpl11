/*!
 * @file
 * Defines `boost::mpl11::less_equal`.
 */

#ifndef BOOST_MPL11_LESS_EQUAL_HPP
#define BOOST_MPL11_LESS_EQUAL_HPP

#include <boost/mpl11/fwd/less_equal.hpp>

#include <boost/mpl11/and.hpp>
#include <boost/mpl11/class.hpp>


namespace boost { namespace mpl11 {
    template <typename A, typename B, typename ...C>
    struct less_equal
        : and_<
            typename less_equal<A, B>::type,
            less_equal<B, C...>
        >
    { };

    template <typename A, typename B>
    struct less_equal<A, B>
        : class_<A>::type::template less_equal<A, B>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_LESS_EQUAL_HPP
