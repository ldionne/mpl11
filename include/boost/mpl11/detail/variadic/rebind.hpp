/*!
 * @file
 * Defines `boost::mpl11::detail::variadic::rebind`.
 */

#ifndef BOOST_MPL11_DETAIL_VARIADIC_REBIND_HPP
#define BOOST_MPL11_DETAIL_VARIADIC_REBIND_HPP

namespace boost { namespace mpl11 { namespace detail { namespace variadic {
    /*!
     * @ingroup details
     *
     * Transfers template parameters from a `pack` to another
     * arbitrary template.
     *
     *
     * @note
     * We only accept `packs` as the source on purpose. We don't
     * want this metafunction to be a general purpose rebinder.
     */
    template <typename Source, template <typename ...> class Destination>
    struct rebind;
}}}} // end namespace boost::mpl11::detail::variadic


#include <boost/mpl11/detail/variadic/pack.hpp>


namespace boost { namespace mpl11 { namespace detail { namespace variadic {
    template <typename ...An, template <typename ...> class Destination>
    struct rebind<pack<An...>, Destination> {
        using type = Destination<An...>;
    };
}}}} // end namespace boost::mpl11::detail::variadic

#endif // !BOOST_MPL11_DETAIL_VARIADIC_REBIND_HPP
