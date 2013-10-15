/*!
 * @file
 * Defines `boost::mpl11::unpack_args`.
 */

#ifndef BOOST_MPL11_UNPACK_ARGS_HPP
#define BOOST_MPL11_UNPACK_ARGS_HPP

#include <boost/mpl11/fwd/unpack_args.hpp>

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/begin.hpp>
#include <boost/mpl11/deref.hpp>
#include <boost/mpl11/end.hpp>
#include <boost/mpl11/equal_to.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/joined_view.hpp>
#include <boost/mpl11/next.hpp>
#include <boost/mpl11/single_view.hpp>


namespace boost { namespace mpl11 {
    namespace unpack_args_detail {
        template <typename ...> struct variadic;

        template <template <typename ...> class Finish>
        class fill {
            template <typename First, typename Last, typename Variadic,
                      bool = equal_to<First, Last>::type::value>
            struct apply_impl;

            template <typename First, typename Last, typename ...T>
            struct apply_impl<First, Last, variadic<T...>, true>
                : identity<Finish<T...>>
            { };

            template <typename First, typename Last, typename ...T>
            struct apply_impl<First, Last, variadic<T...>, false>
                : apply_impl<
                    typename next<First>::type,
                    Last,
                    variadic<typename deref<First>::type, T...>
                >
            { };

        public:
            template <typename Sequence>
            struct apply
                : apply_impl<
                    typename begin<Sequence>::type,
                    typename end<Sequence>::type,
                    variadic<>
                >
            { };
        };
    } // end namespace unpack_args_detail

    template <typename F>
    struct unpack_args {
        template <typename Args>
        struct apply
            : unpack_args_detail::fill<mpl11::apply>::template apply<
                joined_view<single_view<F>, Args>
            >::type
        { };
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_UNPACK_ARGS_HPP
