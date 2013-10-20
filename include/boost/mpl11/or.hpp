/*!
 * @file
 * Defines `boost::mpl11::or_`.
 */

#ifndef BOOST_MPL11_OR_HPP
#define BOOST_MPL11_OR_HPP

#include <boost/mpl11/fwd/or.hpp>

#include <boost/mpl11/class.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/if.hpp>


namespace boost { namespace mpl11 {
    template <typename A, typename B, typename ...C>
    struct or_
        : if_<A, identity<A>, or_<B, C...>>::type
    { };

    template <typename A, typename B>
    struct or_<A, B>
        : class_<A>::type::template or_<A, B>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_OR_HPP
