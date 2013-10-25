/*!
 * @file
 * Defines `boost::mpl11::and_`.
 */

#ifndef BOOST_MPL11_AND_HPP
#define BOOST_MPL11_AND_HPP

#include <boost/mpl11/fwd/and.hpp>

#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/if.hpp>
#include <boost/mpl11/integral_c.hpp>


namespace boost { namespace mpl11 {
    template <typename F1, typename F2, typename ...Fn>
    struct and_
        : and_<F1, and_<F2, Fn...>>
    { };

    template <typename F1, typename F2>
    struct and_<F1, F2>
        : identity<
            bool_<if_c<F1::type::value, F2, false_>::type::type::value>
        >
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_AND_HPP
