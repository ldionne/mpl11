/*!
 * @file
 * Defines `boost::mpl11::detail::variadic::pack`.
 */

#ifndef BOOST_MPL11_DETAIL_VARIADIC_PACK_HPP
#define BOOST_MPL11_DETAIL_VARIADIC_PACK_HPP

namespace boost { namespace mpl11 { namespace detail { namespace variadic {
    /*!
     * @ingroup details
     *
     * Represents a variadic parameter pack.
     *
     *
     * @internal
     * It's important that metafunctions working on variadic parameter pack
     * always use this holder. This can potentially reduce the total number
     * of instantiations required by the compiler. I'm leaving this as a
     * reminder if someone is ever tempted to make these metafunctions
     * "more general" by accepting any variadic template as a holder.
     *
     * The best way to do this is to perform the core computations with
     * `variadic::pack` and then to use `variadic::rebind` to transfer the
     * results to a different holder.
     */
    template <typename ...An>
    struct pack;
}}}} // end namespace boost::mpl11::detail::variadic

#endif // !BOOST_MPL11_DETAIL_VARIADIC_PACK_HPP
