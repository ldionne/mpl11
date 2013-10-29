/*!
 * @file
 * Defines `boost::mpl11::if_`.
 */

#ifndef BOOST_MPL11_IF_HPP
#define BOOST_MPL11_IF_HPP

#include <boost/mpl11/fwd/if.hpp>

#include <boost/mpl11/bool.hpp> // for if_c
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/not.hpp>


namespace boost { namespace mpl11 {
    namespace if_detail {
        template <typename Condition, typename Then, typename Else>
        struct if_impl;

        template <typename Then, typename Else>
        struct if_impl<true_, Then, Else> {
            using type = Then;
        };

        template <typename Then, typename Else>
        struct if_impl<false_, Then, Else> {
            using type = Else;
        };
    } // end namespace if_detail

    template <typename Condition, typename Then, typename Else>
    struct if_
        : if_detail::if_impl<
            typename not_<identity<Condition>>::type, Else, Then
        >
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_IF_HPP
