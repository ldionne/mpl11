/*!
 * @file
 * Defines `boost::mpl11::arg`.
 */

#ifndef BOOST_MPL11_ARG_HPP
#define BOOST_MPL11_ARG_HPP

#include <boost/mpl11/fwd/arg.hpp>

#include <boost/mpl11/at.hpp>
#include <boost/mpl11/detail/dependent_on.hpp>
#include <boost/mpl11/fwd/is_placeholder.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/vector.hpp>


namespace boost { namespace mpl11 {
    template <unsigned long long N>
    struct arg {
        template <typename ...Args>
        struct apply
            : at_c<vector<Args...>, N - 1>
        { };
    };

    template <>
    struct arg<0> {
        template <typename ...Args>
        struct apply {
            static_assert(
            detail::dependent_on<apply>::template value<bool, false>(),
            "Using `arg<0>` is prohibited.");

            struct type;
        };
    };

    template <unsigned long long N>
    struct is_placeholder<arg<N>>
        : true_
    { };

    template <>
    struct is_placeholder<arg<0>>
        : false_
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ARG_HPP
