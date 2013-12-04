/*!
 * @file
 * Defines `boost::mpl11::arg` and `boost::mpl11::_arg`.
 */

#ifndef BOOST_MPL11_ARG_HPP
#define BOOST_MPL11_ARG_HPP

#include <boost/mpl11/fwd/arg.hpp>

#include <boost/mpl11/detail/no_decay.hpp>
#include <boost/mpl11/detail/vector_fill.hpp>
#include <boost/mpl11/fwd/is_placeholder.hpp>
#include <boost/mpl11/fwd/vector.hpp>
#include <boost/mpl11/integral_c.hpp>


namespace boost { namespace mpl11 {
    namespace arg_detail {
        template <typename Ignore>
        struct arg_impl;

        template <typename ...Ignore>
        struct arg_impl<vector<Ignore...>> {
            template <typename Nth>
            static Nth apply(Ignore..., detail::no_decay<Nth>*, ...);
        };
    } // end namespace arg_detail

    template <unsigned long long N>
    struct arg {
        template <typename ...Args>
        struct apply {
            static_assert(N < sizeof...(Args),
            "Invalid usage of `arg`: "
            "accessing a parameter pack at an out-of-bounds index.");

            using type = decltype(
                arg_detail::arg_impl<
                    typename detail::vector_fill<N, void*>::type
                >::apply((detail::no_decay<Args>*)nullptr...)
            );
        };
    };

    template <unsigned long long N>
    struct _arg {
        template <typename Context, typename ...Args>
        using apply = typename arg<N>::template apply<Args...>;
    };

    template <unsigned long long N>
    struct is_placeholder<_arg<N>>
        : true_
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ARG_HPP
