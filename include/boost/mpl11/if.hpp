/*!
 * @file
 * Defines `boost::mpl11::if_`.
 */

#ifndef BOOST_MPL11_IF_HPP
#define BOOST_MPL11_IF_HPP

#include <boost/mpl11/fwd/if.hpp>


namespace boost { namespace mpl11 {
    template <typename Condition, typename Then, typename Else>
    struct if_ {
        using type = typename if_c<Condition::type::value, Then, Else>::type;
    };

    template <typename Then, typename Else>
    struct if_c<true, Then, Else> {
        using type = Then;
    };

    template <typename Then, typename Else>
    struct if_c<false, Then, Else> {
        using type = Else;
    };

    namespace if_detail {
        template <bool Condition> struct if_impl;

        template <> struct if_impl<true>
        { template <typename Then, typename Else> using result = Then; };

        template <> struct if_impl<false>
        { template <typename Then, typename Else> using result = Else; };
    } // end namespace if_detail
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_IF_HPP
