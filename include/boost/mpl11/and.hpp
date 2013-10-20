/*!
 * @file
 * Defines `boost::mpl11::and_`.
 */

#ifndef BOOST_MPL11_AND_HPP
#define BOOST_MPL11_AND_HPP

#include <boost/mpl11/fwd/and.hpp>

#include <boost/mpl11/class.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/if.hpp>


namespace boost { namespace mpl11 {
    template <typename A, typename B, typename ...C>
    struct and_
        : if_<A, and_<B, C...>, identity<A>>::type
    { };

    template <typename A, typename B>
    struct and_<A, B>
        : class_<A>::type::template and_<A, B>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_AND_HPP
