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
     * Default implementation of the `unpack` method for iterables.
     */
    template <typename S, typename F>
    struct default_unpack;
}}}


#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/fwd/foldable.hpp>


namespace boost { namespace mpl11 { namespace detail {
    namespace default_unpack_detail {
        template <typename ...T>
        struct holder {
            using type = holder;

            template <typename X>
            using append = holder<T..., X>;

            template <template <typename ...> class F>
            using into = F<T...>;
        };

        struct fill_holder {
            using type = fill_holder;
            template <typename Holder, typename X>
            using apply = typename Holder::type::template append<X>;
        };
    } // end namespace default_unpack_detail

    template <typename Iter, typename F>
    struct default_unpack
        : foldl<
            default_unpack_detail::fill_holder,
            default_unpack_detail::holder<F>,
            Iter
        >::type::template into<apply>
    { };
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_DEFAULT_UNPACK_HPP
