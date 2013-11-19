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
     * The `_1`, ...`_9` aliases are provided for convenience. They
     * are equivalent to the `arg<N-1>` specialization corresponding
     * to their number (`_N` is equivalent to `arg<N-1>`).
     *
     *
     * @warning
     * Unlike in the original MPL, indexing starts at 0 for `mpl11::arg` but
     * the placeholders still represent the same thing.
     */
    template <unsigned long long N>
    struct arg;

    using _1 = arg<0>;
    using _2 = arg<1>;
    using _3 = arg<2>;
    using _4 = arg<3>;
    using _5 = arg<4>;
    using _6 = arg<5>;
    using _7 = arg<6>;
    using _8 = arg<7>;
    using _9 = arg<8>;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_ARG_HPP
