/*!
 * @file
 * This file defines `boost::mpl11::if_` and `boost::mpl11::if_c`.
 */

#ifndef BOOST_MPL11_IF_HPP
#define BOOST_MPL11_IF_HPP

#include <boost/mpl11/identity.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
namespace if_detail {
    template <bool C, typename Then, typename Else>
    struct conditional : identity<Then> { };

    template <typename Then, typename Else>
    struct conditional<false, Then, Else> : identity<Else> { };

    struct no_else;
}

template <bool Cond, typename Then, typename Else = if_detail::no_else>
struct if_c
    : if_c<Cond, Then>::template else_<Else>
{ };

template <bool Cond, typename Then>
struct if_c<Cond, Then, if_detail::no_else> {
    template <bool Cond2, typename Then2 = void, typename Else = if_detail::no_else>
    struct else_if_c
        : if_c<Cond, Then>::template
          else_<typename if_c<Cond2, Then2, Else>::type>
    { };

    template <typename Cond2, typename Then2 = void, typename Else = if_detail::no_else>
    struct else_if
        : else_if_c<Cond2::value, Then2, Else>
    { };

    template <typename Else>
    struct else_
        : if_detail::conditional<Cond, Then, Else>
    { };
};

template <typename Cond, typename Then, typename Else>
struct if_
    : if_c<Cond::value, Then, Else>
{ };
}}}

#endif // !BOOST_MPL11_IF_HPP
