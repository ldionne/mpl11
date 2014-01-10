/*!
 * @file
 * Defines `boost::mpl11::detail::lazy_variadic_foldr`.
 */

#ifndef BOOST_MPL11_DETAIL_LAZY_VARIADIC_FOLDR_HPP
#define BOOST_MPL11_DETAIL_LAZY_VARIADIC_FOLDR_HPP

namespace boost { namespace mpl11 { namespace detail {
    /*!
     * @ingroup details
     *
     * Lazy right-fold algorithm processing a variadic parameter pack.
     *
     * The binary operation is invoked with the current element and a
     * metafunction returning the current state.
     *
     *
     * @todo
     * Optimize this and make it able to process _huge_ sequences.
     */
    template <typename F, typename State, typename ...T>
    struct lazy_variadic_foldr;
}}} // end namespace boost::mpl11::detail


#include <boost/mpl11/apply.hpp>


namespace boost { namespace mpl11 { namespace detail {
    template <typename F, typename State, typename Head, typename ...Tail>
    struct lazy_variadic_foldr<F, State, Head, Tail...> {
        using type = typename apply<
            F, Head, lazy_variadic_foldr<F, State, Tail...>
        >::type;
    };

    template <typename F, typename State>
    struct lazy_variadic_foldr<F, State> {
        using type = State;
    };
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_LAZY_VARIADIC_FOLDR_HPP
