/*!
 * @file
 * Defines `boost::mpl11::detail::variadic_at`.
 */

#ifndef BOOST_MPL11_DETAIL_VARIADIC_AT_HPP
#define BOOST_MPL11_DETAIL_VARIADIC_AT_HPP

#include <boost/mpl11/detail/std_size_t.hpp>


namespace boost { namespace mpl11 { namespace detail {
    /*!
     * @ingroup details
     *
     * Returns the element of a variadic parameter pack at the given index.
     */
    template <std_size_t Index, typename ...Args>
    struct variadic_at;
}}}


#include <boost/mpl11/detail/variadic_last.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/repeat.hpp>


namespace boost { namespace mpl11 { namespace detail {
    namespace variadic_at_detail {
        struct impl {
            template <typename ...Ignore>
            struct apply {
                using type = apply;

                template <typename Nth>
                static identity<Nth> nth(Ignore..., identity<Nth>*, ...);
            };
        };
    } // end namespace variadic_at_detail

    template <std_size_t Index, typename ...Args>
    struct variadic_at {
        static_assert(Index < sizeof...(Args),
        "Invalid usage of `variadic_at`: "
        "Accessing a parameter pack at an out-of-bounds index.");

        using type = typename decltype(
            unpack<
                repeat_c<void*, Index>, variadic_at_detail::impl
            >::type::nth((identity<Args>*)nullptr...)
        )::type;
    };

    template <typename A0, typename ...An>
    struct variadic_at<0, A0, An...> { using type = A0; };
    template <typename A0, typename A1, typename ...An>
    struct variadic_at<1, A0, A1, An...> { using type = A1; };

    template <typename ...Args>
    struct variadic_at<sizeof...(Args), Args...>
        : variadic_last<Args...>
    { };
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_VARIADIC_AT_HPP
