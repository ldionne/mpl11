/*!
 * @file
 * Defines `boost::mpl11::detail::conditional`.
 */

#ifndef BOOST_MPL11_DETAIL_CONDITIONAL_HPP
#define BOOST_MPL11_DETAIL_CONDITIONAL_HPP

#include <boost/mpl11/identity.hpp>


namespace boost { namespace mpl11 { namespace detail {
    template <bool Condition, typename Then, typename Else>
    struct conditional
        : identity<Then>
    { };

    template <typename Then, typename Else>
    struct conditional<false, Then, Else>
        : identity<Else>
    { };
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_CONDITIONAL_HPP
