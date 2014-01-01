/*!
 * @file
 * Defines `boost::mpl11::arg`.
 */

#ifndef BOOST_MPL11_ARG_HPP
#define BOOST_MPL11_ARG_HPP

#include <boost/mpl11/fwd/arg.hpp>

#include <boost/mpl11/detail/std_size_t.hpp>


namespace boost { namespace mpl11 {
    template <>
    struct arg<0>;

    template <>
    struct arg<1> {
        template <typename A1, typename ...An>
        struct apply {
            using type = A1;
        };
    };

    template <detail::std_size_t N>
    struct arg {
        template <typename A1, typename ...An>
        struct apply
            : arg<N - 1>::template apply<An...>
        { };
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ARG_HPP
