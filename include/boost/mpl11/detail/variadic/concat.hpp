/*!
 * @file
 * Defines `boost::mpl11::detail::variadic::concat`.
 */

#ifndef BOOST_MPL11_DETAIL_VARIADIC_CONCAT_HPP
#define BOOST_MPL11_DETAIL_VARIADIC_CONCAT_HPP

namespace boost { namespace mpl11 { namespace detail { namespace variadic {
    /*!
     * @ingroup details
     *
     * Concatenate two or more variadic parameter packs.
     */
    template <typename Pack1, typename Pack2, typename ...PackN>
    struct concat;
}}}} // end namespace boost::mpl11::detail::variadic


#include <boost/mpl11/detail/variadic/pack.hpp>


namespace boost { namespace mpl11 { namespace detail { namespace variadic {
    template <typename Pack1, typename Pack2, typename ...PackN>
    struct concat
        : concat<
            Pack1, typename concat<Pack2, PackN...>::type
        >
    { };

    template <typename ...An, typename ...Bn>
    struct concat<pack<An...>, pack<Bn...>> {
        using type = pack<An..., Bn...>;
    };
}}}} // end namespace boost::mpl11::detail::variadic

#endif // !BOOST_MPL11_DETAIL_VARIADIC_CONCAT_HPP
