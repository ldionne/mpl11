/*!
 * @file
 * Defines `boost::mpl11::detail::variadic_last`.
 */

#ifndef BOOST_MPL11_DETAIL_VARIADIC_LAST_HPP
#define BOOST_MPL11_DETAIL_VARIADIC_LAST_HPP

namespace boost { namespace mpl11 { namespace detail {
    /*!
     * @ingroup details
     *
     * Returns the last element of a variadic parameter pack.
     */
    template <typename Head, typename ...Tail>
    struct variadic_last;

    namespace variadic_last_detail {
        template <typename ...Head>
        struct impl {
            template <typename Last>
            static Last apply(Head..., Last*);
        };
    }

    template <typename Head, typename ...Tail>
    struct variadic_last
        : decltype(
            variadic_last_detail::impl<
                decltype((void*)(Tail*)nullptr)...
            >::apply((Head*)nullptr, (Tail*)nullptr...)
        )
    { };
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_VARIADIC_LAST_HPP
