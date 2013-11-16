/*!
 * @file
 * Forward declares `boost::mpl11::arg`.
 */

#ifndef BOOST_MPL11_FWD_ARG_HPP
#define BOOST_MPL11_FWD_ARG_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup metafunctions
     *
     * @ref MetafunctionClass and @ref Placeholder returning the `N`th of
     * its arguments.
     *
     * The `_0`, ...`_9` aliases are provided for convenience. They
     * are equivalent to the `arg<N>` specialization corresponding
     * to their number (`_N` is equivalent to `arg<N>`).
     *
     *
     * @warning
     * Unlike in the original MPL, indexing starts at 0.
     */
    template <unsigned long long N>
    struct arg;

    using _0 = arg<0>;
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

#endif // !BOOST_MPL11_FWD_ARG_HPP
