/*!
 * @file
 * Defines `boost::mpl11::detail::copy_into_variadic_pack`.
 */

#ifndef BOOST_MPL11_DETAIL_COPY_INTO_VARIADIC_PACK_HPP
#define BOOST_MPL11_DETAIL_COPY_INTO_VARIADIC_PACK_HPP

namespace boost { namespace mpl11 { namespace detail {
    /*!
     * @ingroup details
     *
     * Copy an arbitrary sequence into a `variadic::pack`.
     *
     *
     * @todo
     * Find an elegant way to convert arbitrary sequences into variadic packs.
     *
     * @todo
     * Find an elegant way to leverage sequences whose behavior is that of
     * a variadic parameter pack.
     */
    template <typename Sequence>
    struct copy_into_variadic_pack;
}}} // end namespace boost::mpl11::detail


#include <boost/mpl11/begin.hpp>
#include <boost/mpl11/deref.hpp>
#include <boost/mpl11/detail/variadic/pack.hpp>
#include <boost/mpl11/end.hpp>
#include <boost/mpl11/equal.hpp>
#include <boost/mpl11/next.hpp>


namespace boost { namespace mpl11 { namespace detail {
    namespace copy_into_variadic_pack_detail {
        template <
            typename Pack,
            typename First, typename Last,
            bool = equal<First, Last>::value
        >
        struct impl;

        template <typename Pack, typename First, typename Last>
        struct impl<Pack, First, Last, true> {
            using type = Pack;
        };

        template <typename ...T, typename First, typename Last>
        struct impl<variadic::pack<T...>, First, Last, false>
            : impl<
                variadic::pack<T..., typename deref<First>::type>,
                typename next<First>::type,
                Last
            >
        { };
    } // end namespace copy_into_variadic_pack_detail

    template <typename Sequence>
    struct copy_into_variadic_pack
        : copy_into_variadic_pack_detail::impl<
            variadic::pack<>,
            typename begin<Sequence>::type,
            typename end<Sequence>::type
        >
    { };
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_COPY_INTO_VARIADIC_PACK_HPP
