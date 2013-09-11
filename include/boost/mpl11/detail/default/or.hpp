/*!
 * @file
 * Defines the default implementation of `boost::mpl11::or_`.
 */

#ifndef BOOST_MPL11_DETAIL_DEFAULT_OR_HPP
#define BOOST_MPL11_DETAIL_DEFAULT_OR_HPP

#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/if.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/operator/or.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
    template <typename F1, typename F2, typename ...Fn>
    struct dispatch<detail::default_<tag::or_>, F1, F2, Fn...>
        : or_<F1, or_<F2, Fn...>>
    { };

    template <typename F1, typename F2>
    struct dispatch<detail::default_<tag::or_>, F1, F2>
        : identity<
            bool_<if_c<F1::type::value, true_, F2>::type::type::value>
        >
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_DETAIL_DEFAULT_OR_HPP
