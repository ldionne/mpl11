/*!
 * @file
 * Defines `boost::mpl11::detail::variadic::drop`.
 */

#ifndef BOOST_MPL11_DETAIL_VARIADIC_DROP_HPP
#define BOOST_MPL11_DETAIL_VARIADIC_DROP_HPP

namespace boost { namespace mpl11 { namespace detail { namespace variadic {
    /*!
     * @ingroup details
     *
     * Returns a `variadic::pack` containing all the elements in
     * the range [`Index`, `sizeof...(An)`).
     */
    template <typename Pack, unsigned long long Index>
    struct drop;
}}}} // end namespace boost::mpl11::detail::variadic


#include <boost/mpl11/detail/no_decay.hpp>
#include <boost/mpl11/detail/variadic/fill.hpp>
#include <boost/mpl11/detail/variadic/pack.hpp>


namespace boost { namespace mpl11 { namespace detail { namespace variadic {
    namespace drop_detail {
        template <typename IgnoreHead>
        struct drop_impl;

        template <typename ...IgnoreHead>
        struct drop_impl<pack<IgnoreHead...>> {
            template <typename ...Tail>
            static pack<Tail...> apply(IgnoreHead..., no_decay<Tail>*...);
        };
    } // end namespace drop_detail

    template <typename ...An, unsigned long long Index>
    struct drop<pack<An...>, Index> {
        static_assert(Index <= sizeof...(An),
        "Dropping more elements from a parameter pack than the size "
        "of the pack.");

        using type = decltype(
            drop_detail::drop_impl<
                typename fill<Index, void*>::type
            >::apply((no_decay<An>*)nullptr...)
        );
    };
}}}} // end namespace boost::mpl11::detail::variadic

#endif // !BOOST_MPL11_DETAIL_VARIADIC_DROP_HPP
