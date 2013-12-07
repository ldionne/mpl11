/*!
 * @file
 * Defines `boost::mpl11::arg`.
 */

#ifndef BOOST_MPL11_ARG_HPP
#define BOOST_MPL11_ARG_HPP

#include <boost/mpl11/fwd/arg.hpp>

#include <boost/mpl11/detail/no_decay.hpp>
#include <boost/mpl11/fwd/vector.hpp>
#include <boost/mpl11/replicate.hpp>


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
                    replicate_c_t<N, void*>
                >::apply((detail::no_decay<Args>*)nullptr...)
            );
        };
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ARG_HPP
