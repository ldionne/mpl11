/*!
 * @file
 * This file defines `boost::mpl11::detail::trailing_if`.
 */

#ifndef BOOST_MPL11_DETAIL_TRAILING_IF_HPP
#define BOOST_MPL11_DETAIL_TRAILING_IF_HPP

#include <boost/mpl11/eval.hpp>
#include <boost/mpl11/if.hpp>


namespace boost { namespace mpl11 { inline namespace v2 { namespace detail {
template <typename Derived, typename Else>
struct trailing_if {
    template <bool Condition>
    using if_c = mpl11::if_c<Condition, eval<Derived>, Else>;

    template <typename Condition>
    using if_ = if_c<Condition::type::value>;
};
}}}}

#endif // !BOOST_MPL11_DETAIL_TRAILING_IF_HPP
