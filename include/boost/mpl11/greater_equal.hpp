/*!
 * @file
 * Defines `boost::mpl11::greater_equal`.
 */

#ifndef BOOST_MPL11_GREATER_EQUAL_HPP
#define BOOST_MPL11_GREATER_EQUAL_HPP

#include <boost/mpl11/fwd/greater_equal.hpp>

#include <boost/mpl11/and.hpp>
#include <boost/mpl11/class.hpp>


namespace boost { namespace mpl11 {
    template <typename A, typename B, typename ...C>
    struct greater_equal
        : and_<
            typename greater_equal<A, B>::type,
            greater_equal<B, C...>
        >
    { };

    template <typename A, typename B>
    struct greater_equal<A, B>
        : class_<A>::type::template greater_equal<A, B>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_GREATER_EQUAL_HPP
