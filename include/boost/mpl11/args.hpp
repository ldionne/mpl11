/*!
 * @file
 * Defines `boost::mpl11::args`.
 */

#ifndef BOOST_MPL11_ARGS_HPP
#define BOOST_MPL11_ARGS_HPP

#include <boost/mpl11/fwd/args.hpp>

#include <boost/mpl11/detail/vector_slice.hpp>
#include <boost/mpl11/fwd/is_placeholder.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/vector.hpp>


namespace boost { namespace mpl11 {
    template <unsigned long long First>
    struct args<First> {
        template <typename ...Args>
        struct apply
            : args<First, sizeof...(Args)>::template apply<Args...>
        { };
    };

    template <unsigned long long First, unsigned long long Last>
    struct args<First, Last> {
        static_assert(First <= Last,
        "Invalid indexing of `args`: `First > Last`.");

        template <typename ...Args>
        struct apply
            : detail::vector_slice<
                vector<Args...>, First, Last
            >
        { };
    };

    template <unsigned long long First>
    struct is_placeholder<args<First>>
        : true_
    { };

    template <unsigned long long First, unsigned long long Last>
    struct is_placeholder<args<First, Last>>
        : true_
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ARGS_HPP
