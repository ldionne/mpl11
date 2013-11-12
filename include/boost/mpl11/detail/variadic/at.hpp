/*!
 * @file
 * Defines `boost::mpl11::detail::variadic::at`.
 */

#ifndef BOOST_MPL11_DETAIL_VARIADIC_AT_HPP
#define BOOST_MPL11_DETAIL_VARIADIC_AT_HPP

namespace boost { namespace mpl11 { namespace detail { namespace variadic {
    /*!
     * @ingroup details
     *
     * Returns the parameter at position `N` in a parameter pack.
     */
    template <typename Pack, unsigned long long N>
    struct at;
}}}} // end namespace boost::mpl11::detail::variadic


#include <boost/mpl11/detail/no_decay.hpp>
#include <boost/mpl11/detail/variadic/fill.hpp>
#include <boost/mpl11/detail/variadic/pack.hpp>


namespace boost { namespace mpl11 { namespace detail { namespace variadic {
    namespace at_detail {
        template <typename Ignore>
        struct at_impl;

        template <typename ...Ignore>
        struct at_impl<pack<Ignore...>> {
            template <typename Nth>
            static Nth apply(Ignore..., no_decay<Nth>*, ...);
        };
    } // end namespace at_detail

    template <typename ...An, unsigned long long N>
    struct at<pack<An...>, N> {
        static_assert(N < sizeof...(An),
        "Accessing a variadic parameter pack at an out-of-bounds index.");

        using type = decltype(
            at_detail::at_impl<
                typename fill<N, void*>::type
            >::apply((no_decay<An>*)nullptr...)
        );
    };
}}}} // end namespace boost::mpl11::detail::variadic

#endif // !BOOST_MPL11_DETAIL_VARIADIC_AT_HPP
