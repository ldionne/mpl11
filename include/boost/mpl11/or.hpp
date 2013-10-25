/*!
 * @file
 * Defines `boost::mpl11::or_`.
 */

#ifndef BOOST_MPL11_OR_HPP
#define BOOST_MPL11_OR_HPP

#include <boost/mpl11/fwd/or.hpp>

#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/if.hpp>
#include <boost/mpl11/integral_c.hpp>


namespace boost { namespace mpl11 {
    template <typename F1, typename F2, typename ...Fn>
    struct or_
        : or_<F1, or_<F2, Fn...>>
    { };

    template <typename F1, typename F2>
    struct or_<F1, F2>
        : identity<
            bool_<if_c<F1::type::value, true_, F2>::type::type::value>
        >
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_OR_HPP
