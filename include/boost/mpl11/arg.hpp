/*!
 * @file
 * Defines `boost::mpl11::arg`.
 */

#ifndef BOOST_MPL11_ARG_HPP
#define BOOST_MPL11_ARG_HPP

#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/detail/variadic_at.hpp>
#include <boost/mpl11/is_placeholder.hpp>


namespace boost { namespace mpl11 {
    /*!
     * `Placeholder` returning the `N`th of its arguments.
     *
     * The `_1, ..._9` aliases are provided for convenience. They
     * are equivalent to the `arg<N>` specialization corresponding
     * to their number (`_N` is equivalent to `arg<N>`).
     */
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

    using _1 = arg<1>;
    using _2 = arg<2>;
    using _3 = arg<3>;
    using _4 = arg<4>;
    using _5 = arg<5>;
    using _6 = arg<6>;
    using _7 = arg<7>;
    using _8 = arg<8>;
    using _9 = arg<9>;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ARG_HPP
