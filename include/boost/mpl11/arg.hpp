/*!
 * @file
 * Defines `boost::mpl11::arg`.
 */

#ifndef BOOST_MPL11_ARG_HPP
#define BOOST_MPL11_ARG_HPP

#include <boost/mpl11/fwd/arg.hpp>

#include <boost/mpl11/detail/std_size_t.hpp>
#include <boost/mpl11/detail/variadic_at.hpp>


namespace boost { namespace mpl11 {
    template <>
    struct arg<0>;

    template <detail::std_size_t N>
    struct arg {
        template <typename A1, typename ...An>
        using apply = detail::variadic_at<N - 1, A1, An...>;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ARG_HPP
