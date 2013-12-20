/*!
 * @file
 * Defines `boost::mpl11::detail::foldl_variadic`.
 */

#ifndef BOOST_MPL11_DETAIL_FOLDL_VARIADIC_HPP
#define BOOST_MPL11_DETAIL_FOLDL_VARIADIC_HPP

namespace boost { namespace mpl11 { namespace detail {
    /*!
     * @ingroup details
     *
     * Left-fold algorithm folding a variadic sequence of types.
     */
    template <typename State, typename F, typename ...Sequence>
    struct foldl_variadic;
}}} // end namespace boost::mpl11::detail


#include <boost/mpl11/apply.hpp>


namespace boost { namespace mpl11 { namespace detail {
namespace foldl_variadic_detail {
    template <bool Done>
    struct impl;

    // There are still types to process.
    template <>
    struct impl<false> {
        template <typename State, typename F, typename Head, typename ...Tail>
        using apply =
            typename impl<sizeof...(Tail) == 0>::template apply<
                typename mpl11::apply<F, State, Head>::type, F, Tail...
            >;
    };

    // There are no more types to process.
    template <>
    struct impl<true> {
        template <typename State, typename F>
        struct apply {
            using type = State;
        };
    };
} // end namespace foldl_variadic_detail

template <typename State, typename F, typename ...Sequence>
struct foldl_variadic
    : foldl_variadic_detail::impl<sizeof...(Sequence) == 0>::
        template apply<State, F, Sequence...>
{ };
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_FOLDL_VARIADIC_HPP
