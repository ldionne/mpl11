/*!
 * @file
 * Defines `boost::mpl11::arg`.
 */

#ifndef BOOST_MPL11_FUNCTIONAL_ARG_HPP
#define BOOST_MPL11_FUNCTIONAL_ARG_HPP

#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/detail/variadic_at.hpp>
#include <boost/mpl11/functional/arg_fwd.hpp>
#include <boost/mpl11/functional/is_placeholder.hpp>


namespace boost { namespace mpl11 {
    template <unsigned long N>
    struct arg {
        template <typename ...Args>
        struct apply
            : detail::variadic_at_c<N - 1, Args...>
        { };
    };

    template <unsigned long N>
    struct is_placeholder<arg<N>>
        : true_
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FUNCTIONAL_ARG_HPP
