/*!
 * @file
 * Defines `boost::mpl11::detail::default_unpack`.
 */

#ifndef BOOST_MPL11_DETAIL_DEFAULT_UNPACK_HPP
#define BOOST_MPL11_DETAIL_DEFAULT_UNPACK_HPP

namespace boost { namespace mpl11 { namespace detail {
    /*!
     * @ingroup details
     *
     * Default implementation of the `unpack` method for `Sequence`s.
     */
    template <typename S, typename F>
    struct default_unpack;
}}}


#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/foldl.hpp>


namespace boost { namespace mpl11 { namespace detail {
    namespace default_unpack_detail {
        struct fill_apply {
            template <typename Variadic, typename X>
            struct apply;

            template <
                template <typename ...> class Variadic, typename ...T,
                typename X
            >
            struct apply<Variadic<T...>, X> {
                using type = Variadic<T..., X>;
            };
        };
    } // end namespace unpack_detail

    template <typename S, typename F>
    struct default_unpack
        : foldl<default_unpack_detail::fill_apply, apply<F>, S>::type
    { };
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_DEFAULT_UNPACK_HPP
