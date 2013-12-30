/*!
 * @file
 * Defines `boost::mpl11::detail::variadic_drop`.
 */

#ifndef BOOST_MPL11_DETAIL_VARIADIC_DROP_HPP
#define BOOST_MPL11_DETAIL_VARIADIC_DROP_HPP

#include <boost/mpl11/detail/std_size_t.hpp>


namespace boost { namespace mpl11 { namespace detail {
    /*!
     * @ingroup details
     *
     * `MetafunctionClass` invoking another `MetafunctionClass` with the
     * arguments left after dropping the first `N` arguments.
     */
    template <std_size_t N, typename F>
    struct variadic_drop;
}}}


#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/repeat.hpp>


namespace boost { namespace mpl11 { namespace detail {
    namespace variadic_drop_detail {
        struct impl {
            template <typename ...Head>
            struct apply {
                using type = apply;

                template <typename F, typename ...Tail>
                static mpl11::apply<F, Tail...>
                drop_n(Head..., identity<Tail>*...);
            };
        };
    } // end namespace variadic_drop_detail

    template <std_size_t N, typename F>
    struct variadic_drop {
        template <typename ...Args>
        using apply = decltype(
            unpack<
                repeat_c<void*, N>, variadic_drop_detail::impl
            >::type::template drop_n<F>((identity<Args>*)nullptr...)
        );
    };
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_VARIADIC_DROP_HPP
