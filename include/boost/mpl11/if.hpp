/*!
 * @file
 * Defines `boost::mpl11::if_`.
 */

#ifndef BOOST_MPL11_IF_HPP
#define BOOST_MPL11_IF_HPP

#include <boost/mpl11/fwd/if.hpp>

#include <boost/mpl11/class.hpp>


namespace boost { namespace mpl11 {
    template <typename Condition, typename Then, typename Else>
    struct if_
        : class_<Condition>::type::template if_<Condition, Then, Else>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_IF_HPP
