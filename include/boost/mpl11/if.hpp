/*!
 * @file
 * Defines `boost::mpl11::if_`.
 */

#ifndef BOOST_MPL11_IF_HPP
#define BOOST_MPL11_IF_HPP

#include <boost/mpl11/fwd/if.hpp>

#include <boost/mpl11/detail/conditional.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/integral_c.hpp> // for if_c
#include <boost/mpl11/not.hpp>


namespace boost { namespace mpl11 {
    template <typename Condition, typename Then, typename Else>
    struct if_
        : detail::conditional<
            not_<identity<Condition>>::value, Else, Then
        >
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_IF_HPP
