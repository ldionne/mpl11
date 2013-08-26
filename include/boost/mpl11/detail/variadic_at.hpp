/*!
 * @file
 * Defines `boost::mpl11::detail::variadic_at`.
 */

#ifndef BOOST_MPL11_DETAIL_VARIADIC_AT_HPP
#define BOOST_MPL11_DETAIL_VARIADIC_AT_HPP

#include <boost/mpl11/identity.hpp>


namespace boost { namespace mpl11 {
namespace variadic_at_detail {
    template <unsigned long Pos, typename ...Pack>
    struct impl { };

    template <typename Head, typename ...Tail>
    struct impl<0, Head, Tail...>
        : identity<Head>
    { };

    template <unsigned long Pos, typename Head, typename ...Tail>
    struct impl<Pos, Head, Tail...>
        : impl<Pos - 1, Tail...>
    { };
} // end namespace variadic_at_detail

namespace detail {
    template <unsigned long Pos, typename ...Pack>
    struct variadic_at_c : variadic_at_detail::impl<Pos, Pack...> {
        static_assert(Pos < sizeof...(Pack),
        "Trying to access a variadic parameter pack at an "
        "index that is out of bounds.");
    };

    template <typename Pos, typename ...Pack>
    struct variadic_at
        : variadic_at_c<Pos::type::value, Pack...>
    { };
} // end namespace detail
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_DETAIL_VARIADIC_AT_HPP
