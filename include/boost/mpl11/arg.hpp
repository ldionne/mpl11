/*!
 * @file
 * Defines `boost::mpl11::arg`.
 */

#ifndef BOOST_MPL11_ARG_HPP
#define BOOST_MPL11_ARG_HPP

#include <boost/mpl11/fwd/arg.hpp>

#include <boost/mpl11/detail/std_size_t.hpp>
#include <boost/mpl11/fwd/identity.hpp>
#include <boost/mpl11/fwd/vector.hpp>
#include <boost/mpl11/repeat.hpp>


namespace boost { namespace mpl11 {
    namespace arg_detail {
        template <typename Ignore>
        struct arg_impl;

        template <typename ...Ignore>
        struct arg_impl<vector<Ignore...>> {
            template <typename Nth>
            static Nth apply(Ignore..., identity<Nth>*, ...);
        };
    } // end namespace arg_detail

    template <detail::std_size_t N>
    struct arg {
        template <typename ...Args>
        struct apply {
            static_assert(N < sizeof...(Args),
            "Invalid usage of `arg`: "
            "accessing a parameter pack at an out-of-bounds index.");

            using type = decltype(
                arg_detail::arg_impl<
                    typename repeat_c<void*, N>::type
                >::apply((identity<Args>*)nullptr...)
            );
        };
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ARG_HPP
