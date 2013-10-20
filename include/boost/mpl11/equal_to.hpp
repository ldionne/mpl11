/*!
 * @file
 * Defines `boost::mpl11::equal_to`.
 */

#ifndef BOOST_MPL11_EQUAL_TO_HPP
#define BOOST_MPL11_EQUAL_TO_HPP

#include <boost/mpl11/fwd/equal_to.hpp>

#include <boost/mpl11/and.hpp>
#include <boost/mpl11/class.hpp>


namespace boost { namespace mpl11 {
    template <typename A, typename B, typename ...C>
    struct equal_to
        : and_<
            typename equal_to<A, B>::type,
            equal_to<B, C...>
        >
    { };

    template <typename A, typename B>
    struct equal_to<A, B>
        : class_<A>::type::template equal_to<A, B>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_EQUAL_TO_HPP
