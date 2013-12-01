/*!
 * @file
 * Forward declares `boost::mpl11::arg` and `boost::mpl11::_arg`.
 */

#ifndef BOOST_MPL11_FWD_ARG_HPP
#define BOOST_MPL11_FWD_ARG_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup metafunction_classes
     *
     * `MetafunctionClass` returning the `N`th of its arguments.
     */
    template <unsigned long long N>
    struct arg;

    /*!
     * @ingroup placeholders
     *
     * `Placeholder` counterpart of `mpl11::arg`.
     *
     * The `_1`, ...`_9` aliases are provided for convenience. They
     * are equivalent to the `_arg<N-1>` specialization corresponding
     * to their number (`_N` is equivalent to `_arg<N-1>`).
     *
     *
     * @warning
     * Unlike in the original MPL, indexing starts at 0 for `_arg` but the
     * `_N` specializations still represent the same thing.
     */
    template <unsigned long long N>
    struct _arg;

    using _1 = _arg<0>;
    using _2 = _arg<1>;
    using _3 = _arg<2>;
    using _4 = _arg<3>;
    using _5 = _arg<4>;
    using _6 = _arg<5>;
    using _7 = _arg<6>;
    using _8 = _arg<7>;
    using _9 = _arg<8>;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_ARG_HPP
