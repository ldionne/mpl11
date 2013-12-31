/*!
 * @file
 * Defines `boost::mpl11::if_`.
 */

#ifndef BOOST_MPL11_IF_HPP
#define BOOST_MPL11_IF_HPP

#include <boost/mpl11/fwd/if.hpp>

#include <boost/mpl11/detail/conditional.hpp>
#include <boost/mpl11/integral_c.hpp> // required by forward declaration


namespace boost { namespace mpl11 {
    template <typename Condition, typename Then, typename Else>
    struct if_
        : detail::conditional<Condition::type::value, Then, Else>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_IF_HPP
