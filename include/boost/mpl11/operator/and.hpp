/*!
 * @file
 * Defines `boost::mpl11::and_`.
 */

#ifndef BOOST_MPL11_OPERATOR_AND_HPP
#define BOOST_MPL11_OPERATOR_AND_HPP

#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/if.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/operator/and_fwd.hpp>


namespace boost { namespace mpl11 {
    template <typename F1, typename F2, typename ...Fn>
    struct dispatch<tag::default_<tag::and_>, F1, F2, Fn...>
        : and_<F1, and_<F2, Fn...>>
    { };

    template <typename F1, typename F2>
    struct dispatch<tag::default_<tag::and_>, F1, F2>
        : identity<
            bool_<if_c<F1::type::value, F2, false_>::type::type::value>
        >
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_OPERATOR_AND_HPP
