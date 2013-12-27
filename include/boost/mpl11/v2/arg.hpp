/*!
 * @file
 * Defines `boost::mpl11::arg`.
 */

#ifndef BOOST_MPL11_ARG_HPP
#define BOOST_MPL11_ARG_HPP

#include <boost/mpl11/fwd/arg.hpp>

#include <boost/mpl11/detail/std_size_t.hpp>
#include <boost/mpl11/finite_sequence.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/repeat.hpp>


namespace boost { namespace mpl11 {
    template <>
    struct arg<0>;

    template <>
    struct arg<1> {
        template <typename A1, typename ...An>
        struct apply { using type = A1; };
    };

    template <>
    struct arg<2> {
        template <typename A1, typename A2, typename ...An>
        struct apply { using type = A2; };
    };

    namespace arg_detail {
        struct arg_impl {
            template <typename ...Ignore>
            struct apply {
                using type = apply;

                template <typename Nth>
                static identity<Nth> nth(Ignore..., identity<Nth>*, ...);
            };
        };
    } // end namespace arg_detail

    template <detail::std_size_t N>
    struct arg {
    private:
        template <detail::std_size_t NArg>
        struct assert_usage {
            static_assert(N <= NArg,
            "Invalid usage of `arg`: "
            "Accessing a parameter pack at an out-of-bounds index.");
        };

    public:
        template <typename ...Args>
        using apply = decltype(
            assert_usage<sizeof...(Args)>{},
            unpack<repeat_c<void*, N>, arg_detail::arg_impl>::type::nth(
                (identity<Args>*)nullptr...
            )
        );
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ARG_HPP
