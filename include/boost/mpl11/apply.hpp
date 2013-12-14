/*!
 * @file
 * Defines `boost::mpl11::apply`.
 */

#ifndef BOOST_MPL11_APPLY_HPP
#define BOOST_MPL11_APPLY_HPP

#include <boost/mpl11/fwd/apply.hpp>


namespace boost { namespace mpl11 {
    namespace apply_detail {
        template <bool HasArgs>
        struct apply_impl;

        template <>
        struct apply_impl<true> {
            template <typename F, typename ...Args>
            using nested_apply = typename F::template apply<Args...>;
        };

        template <typename F>
        auto pick() -> typename F::apply;

        template <typename F>
        auto pick() -> typename F::template apply<>;

        template <>
        struct apply_impl<false> {
            template <typename F>
            using nested_apply = decltype(pick<F>());
        };
    } // end namespace apply_detail

    template <typename F, typename ...Args>
    struct apply
        : apply_detail::apply_impl<sizeof...(Args) != 0>::
            template nested_apply<F, Args...>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_APPLY_HPP
