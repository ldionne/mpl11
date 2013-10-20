/*!
 * @file
 * Defines `boost::mpl11::greater`.
 */

#ifndef BOOST_MPL11_GREATER_HPP
#define BOOST_MPL11_GREATER_HPP

#include <boost/mpl11/fwd/greater.hpp>

#include <boost/mpl11/and.hpp>
#include <boost/mpl11/class.hpp>


namespace boost { namespace mpl11 {
    template <typename A, typename B, typename ...C>
    struct greater
        : and_<
            typename greater<A, B>::type,
            greater<B, C...>
        >
    { };

    template <typename A, typename B>
    struct greater<A, B>
        : class_<A>::type::template greater<A, B>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_GREATER_HPP
