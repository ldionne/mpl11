/*!
 * @file
 * Defines `boost::mpl11::detail::strict_variadic_foldl`.
 */

#ifndef BOOST_MPL11_DETAIL_STRICT_VARIADIC_FOLDL_HPP
#define BOOST_MPL11_DETAIL_STRICT_VARIADIC_FOLDL_HPP

namespace boost { namespace mpl11 { namespace detail {
    /*!
     * @ingroup details
     *
     * Strict left-fold algorithm processing a variadic parameter pack.
     *
     *
     * @todo
     * Optimize this and make it able to process _huge_ sequences.
     */
    template <typename f, typename state, typename ...xs>
    struct strict_variadic_foldl : state { };

    namespace strict_vfoldl_detail {
        template <bool, typename x>
        using second = x;
    }

    template <typename f, typename state, typename x, typename ...xs>
    struct strict_variadic_foldl<f, state, x, xs...>
        : strict_vfoldl_detail::second<
            sizeof(typename f::type::template apply<state, x>),
            strict_variadic_foldl<
                f, typename f::type::template apply<state, x>, xs...
            >
        >
    { };
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_STRICT_VARIADIC_FOLDL_HPP
